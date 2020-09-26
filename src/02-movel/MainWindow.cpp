
#include "MainWindow.h"

using namespace aubo_robot_namespace;
double MainWindow::DEGREE2RA  = M_PI/180;

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    //初始化
    setWindowTitle("连接和断开连接机器人");
    //布局
    QVBoxLayout *layout = new QVBoxLayout;
    //输入ip和端口
    editPath = new QLineEdit("192.168.36.29");
//    editPath = new QLineEdit("192.168.1.101");
    editPort = new QLineEdit("8899");
    //按钮
    QPushButton *btn1 = new QPushButton("连接机器人");
    QPushButton *btn2 = new QPushButton("断开连接机器人");
    QPushButton *btn3 = new QPushButton("归零位置");
    QPushButton *btn_move = new QPushButton("移动到指定位置");
    QPushButton *btn4 = new QPushButton("movel移动机器人up");
    QPushButton *btn5 = new QPushButton("movel移动机器人down");
    //添加到布局中
    layout->addWidget(editPath);
    layout->addWidget(editPort);
    layout->addWidget(btn1);
    layout->addWidget(btn2);

    pos_x = new QLineEdit("0.1215");
    pos_y = new QLineEdit("-0.4785");
    pos_z = new QLineEdit("0.462499");
    rpy_x = new QLineEdit("180");
    rpy_y = new QLineEdit("0");
    rpy_z = new QLineEdit("0");

    //添加输入框
    layout->addWidget(pos_x);
    layout->addWidget(pos_y);
    layout->addWidget(pos_z);
    layout->addWidget(rpy_x);
    layout->addWidget(rpy_y);
    layout->addWidget(rpy_z);


    layout->addWidget(btn3);
    layout->addWidget(btn_move);
    layout->addWidget(btn4);
    layout->addWidget(btn5);
    //设置布局
    setLayout(layout);

    //连接机器人
    connect(btn1, &QPushButton::clicked, this, &MainWindow::connectRobot);
    //断开连接机器人
    connect(btn2, &QPushButton::clicked, this, &MainWindow::disConnectRobot);
    //归零位置
    connect(btn3, &QPushButton::clicked, this, &MainWindow::zeroPosition);
    connect(btn_move, &QPushButton::clicked, this, &MainWindow::targetPosition);
    //movel
    connect(btn4, &QPushButton::clicked, this, &MainWindow::moveL);
    connect(btn5, &QPushButton::clicked, this, &MainWindow::moveL2);
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

//归零位置
void MainWindow::zeroPosition() {
//    double jointAngle[aubo_robot_namespace::ARM_DOF] = {0*DEGREE2RA,45*DEGREE2RA,-30*DEGREE2RA,30*DEGREE2RA,0,0};
    // 台3 aubo
//    double jointAngle[aubo_robot_namespace::ARM_DOF] = {90 * DE2RA, 0*DE2RA,-90*DE2RA, 0* DE2RA, -90 * DE2RA  ,0};

    // 上方位置
//    double jointAngle[6] = {
//            -9.263 * DE2RA,
//            12.880 * DE2RA,
//            -35.598 * DE2RA,
//            34.058 * DE2RA,
//            -90.864 * DE2RA,
//            -66.888 * DE2RA
//    };

    double jointAngle[6] = {
            0.516 * DE2RA,
            -25.956 * DE2RA,
            -75.008 * DE2RA,
            38.053 * DE2RA,
            -92.830 * DE2RA,
            0.447 * DE2RA
    };
    //移动到零点位置
    int ret = Robot::getInstance()->moveJ(jointAngle, true);
    //判断是否成功
    if (ret == aubo_robot_namespace::ErrnoSucc) {
        //显示的位置
        QPoint *point = new QPoint(100, 100);
        //显示的文本
        QToolTip::showText(*point, "归零成功", this);
    }
}

void MainWindow::targetPosition() {

    qDebug()<<"move"<<endl;
    //获取6个关节的角度
    double x = pos_x->text().toDouble();
    double y = pos_y->text().toDouble();
    double z = pos_z->text().toDouble();
    double rx = rpy_x->text().toDouble() * DE2RA;
    double ry = rpy_y->text().toDouble() * DE2RA;
    double rz = rpy_z->text().toDouble() * DE2RA;
    //6个关节的角度
    double pose[aubo_robot_namespace::ARM_DOF]{x,y,z,rx,ry,rz};
    int rst = Robot::getInstance()->moveL(pose, true);

    if (rst == ErrnoSucc) {
        std::cout << "Success" << std::endl;
    }else {
        std::cerr << rst << std::endl;
    }
}


//moveL up
void MainWindow::moveL() {
    qDebug()<<"moveL up";

    aubo_robot_namespace::wayPoint_S wayPoint;
    int rst = Robot::getInstance()->robotServiceGetCurrentWaypointInfo(wayPoint);

    if (rst == ErrnoSucc) {

        aubo_robot_namespace::ToolInEndDesc robotTool;
        aubo_robot_namespace::Pos toolPos{0, 0, 0.15};
//        aubo_robot_namespace::Ori toolOri;
        robotTool.toolInEndPosition = toolPos;
        Robot::getInstance()->robotServiceSetRobotTool(robotTool);

        aubo_robot_namespace::Pos &pos = wayPoint.cartPos.position;
        aubo_robot_namespace::Rpy rpy;
        Robot::getInstance()->quaternionToRPY(wayPoint.orientation, rpy);
        pos.z += 0.10;

        double pose[6]{pos.x, pos.y, pos.z, rpy.rx, rpy.ry, rpy.rz};
        Robot::getInstance()->moveL(pose, true);
    }
}

void MainWindow::moveL2(){
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

        // 当前关节角
        JointParam jointParam;
        int rst1 = Robot::getInstance()->robotServiceGetJointAngleInfo(jointParam);
        if (rst1 == ErrnoSucc) {

            std::cout << "逆解结果---------------------------------------" << std::endl;
            // 目标位置
            aubo_robot_namespace::Pos position = pos;
            // 目标姿态
            aubo_robot_namespace::Ori ori = wayPoint.orientation;
            // 输出结果：目标的关节角
            aubo_robot_namespace::wayPoint_S targetWayPoint;

            position.z -= 0.10; // z向下移动5cm
            Robot::getInstance()->robotServiceRobotIk(jointParam.jointPos, position, ori, targetWayPoint);
            qDebug() << "output_joints: "
                     << targetWayPoint.jointpos[0] * RA2DE << ","
                     << targetWayPoint.jointpos[1] * RA2DE << ","
                     << targetWayPoint.jointpos[2] * RA2DE << ","
                     << targetWayPoint.jointpos[3] * RA2DE << ","
                     << targetWayPoint.jointpos[4] * RA2DE << ","
                     << targetWayPoint.jointpos[5] * RA2DE ;

            int rst = Robot::getInstance()->moveL2(targetWayPoint.jointpos, true);
            std::cout << "rst: " << rst << std::endl;
            if (rst != ErrnoSucc) {
                std::cout << "移动失败" << std::endl;
            }
        }else {
            qDebug() << "逆解时当前关节角获取失败";
        }
    }else {
        qDebug() << "获取失败";
    };

};
