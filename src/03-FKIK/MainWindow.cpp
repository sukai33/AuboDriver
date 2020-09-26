
#include <cfloat>
#include "MainWindow.h"

using namespace aubo_robot_namespace;

int io_status{0};

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    //初始化
    setWindowTitle("连接和断开连接机器人");
    //布局
    QVBoxLayout *layout = new QVBoxLayout;
    //输入ip和端口
    editPath = new QLineEdit("192.168.36.37");
    editPort = new QLineEdit("8899");
    //按钮
    QPushButton *btn1 = new QPushButton("连接机器人");
    QPushButton *btn2 = new QPushButton("断开连接机器人");
    QPushButton *btn3 = new QPushButton("获取joints正解得pose");
    QPushButton *btn4 = new QPushButton("获取pose逆解的joints");

    //添加到布局中
    layout->addWidget(editPath);
    layout->addWidget(editPort);
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    layout->addWidget(btn4);

    //设置布局
    setLayout(layout);

    //连接机器人
    connect(btn1, &QPushButton::clicked, this, &MainWindow::connectRobot);
    //断开连接机器人
    connect(btn2, &QPushButton::clicked, this, &MainWindow::disConnectRobot);

    // 获取joints正解得pose
    connect(btn3, &QPushButton::clicked, this, [&]{
        JointParam jointParam;
        int rst = Robot::getInstance()->robotServiceGetJointAngleInfo(jointParam);
        if (rst == ErrnoSucc) {
            qDebug() << "jointParam: "
                    << jointParam.jointPos[0] << ", "
                    << jointParam.jointPos[1] << ", "
                    << jointParam.jointPos[2] << ", "
                    << jointParam.jointPos[3] << ", "
                    << jointParam.jointPos[4] << ", "
                    << jointParam.jointPos[5] ;

            std::cout << "正解结果---------------------------------------" << std::endl;
            aubo_robot_namespace::wayPoint_S wayPoint;
            Robot::getInstance()->robotServiceRobotFk(jointParam.jointPos, 6, wayPoint);

            aubo_robot_namespace::Pos &pos = wayPoint.cartPos.position;
            aubo_robot_namespace::Rpy rpy;
            Robot::getInstance()->quaternionToRPY(wayPoint.orientation, rpy);
            qDebug() << "wayPoint x: " << pos.x << " y: " << pos.y << " z: " << pos.z;
            qDebug() << "rpy rx: " << rpy.rx * RA2DE << " ry: " << rpy.ry * RA2DE<< " rz: " << rpy.rz * RA2DE;
        }else {
            qDebug() << "获取失败";
        }
        
    });
    // 获取pose逆解得joints
    connect(btn4, &QPushButton::clicked, this, [&]{
        aubo_robot_namespace::wayPoint_S wayPoint;
        int rst = Robot::getInstance()->robotServiceGetCurrentWaypointInfo(wayPoint);

        if (rst == ErrnoSucc) {
            aubo_robot_namespace::Pos &pos = wayPoint.cartPos.position;
            aubo_robot_namespace::Rpy rpy;
            Robot::getInstance()->quaternionToRPY(wayPoint.orientation, rpy);

            qDebug() << "wayPoint x: " << pos.x << " y: " << pos.y << " z: " << pos.z;
            qDebug() << "rpy rx: " << rpy.rx * RA2DE << " ry: " << rpy.ry * RA2DE<< " rz: " << rpy.rz * RA2DE;
            std::cout << "jointParam: " << wayPoint.jointpos[0] * RA2DE;
            std::cout << ", " << wayPoint.jointpos[1] * RA2DE ;
            std::cout << ", " << wayPoint.jointpos[2] * RA2DE ;
            std::cout << ", " << wayPoint.jointpos[3] * RA2DE ;
            std::cout << ", " << wayPoint.jointpos[4] * RA2DE ;
            std::cout << ", " << wayPoint.jointpos[5] * RA2DE ;
            std::cout << std::endl;

            JointParam jointParam;
            int rst1 = Robot::getInstance()->robotServiceGetJointAngleInfo(jointParam);
            if (rst1 == ErrnoSucc) {

                std::cout << "逆解结果---------------------------------------" << std::endl;
                // 当前关节角
                // 目标位置
                // 目标姿态
                // 输出结果：目标的关节角
                aubo_robot_namespace::Pos position = pos;
                aubo_robot_namespace::Ori ori = wayPoint.orientation;
                aubo_robot_namespace::wayPoint_S targetWayPoint;

                position.z += 0.05; // z向上提高5cm
                Robot::getInstance()->robotServiceRobotIk(jointParam.jointPos, position, ori, targetWayPoint);
                qDebug() << "output_joints: "
                        << targetWayPoint.jointpos[0] * RA2DE << ","
                        << targetWayPoint.jointpos[1] * RA2DE << ","
                        << targetWayPoint.jointpos[2] * RA2DE << ","
                        << targetWayPoint.jointpos[3] * RA2DE << ","
                        << targetWayPoint.jointpos[4] * RA2DE << ","
                        << targetWayPoint.jointpos[5] * RA2DE ;
            }else {
                qDebug() << "逆解时当前关节角获取失败";
            }
        }else {
            qDebug() << "获取失败";
        };

    });

}

MainWindow::~MainWindow() = default;

//连接槽函数
void MainWindow::connectRobot() {
    //获取ip和端口
    QByteArray arr = editPath->text().toLatin1();
    //将QString转成char *
    char *path = arr.data();
    int port = editPort->text().toInt();
    //连接
    Robot::getInstance()->connect(path, port);
}

//断开连接槽函数
void MainWindow::disConnectRobot() {
    Robot::getInstance()->disConnect();
}