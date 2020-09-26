
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
    editPath = new QLineEdit("192.168.36.43");
    editPort = new QLineEdit("8899");
    //按钮
    QPushButton *btn1 = new QPushButton("连接机器人");
    QPushButton *btn2 = new QPushButton("断开连接机器人");
    QPushButton *btn3 = new QPushButton("获取IO状态");
    QPushButton *btn4 = new QPushButton("发送IO状态");

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

    // 获取IO状态
    connect(btn3, &QPushButton::clicked, this, [&]{
        double value = -1;
        int rst = Robot::getInstance()->robotServiceGetBoardIOStatus(RobotIoType::RobotBoardUserDI, "U_DI_06", value);
        if (rst == ErrnoSucc) {
            qDebug() << "U_DI_06: " << value ;
        }else {
            qDebug() << "获取失败";
        }
        
    });
    // 设置IO状态
    connect(btn4, &QPushButton::clicked, this, [&]{
        int rst = Robot::getInstance()->robotServiceSetBoardIOStatus(RobotIoType::RobotBoardUserDO, "U_DO_06", double(io_status));

        if (rst == ErrnoSucc) {
            qDebug() << "设置成功:"<< io_status;
        }else {
            qDebug() << "设置失败:"<< io_status;
        };
        io_status = io_status == 0 ? 1 : 0;

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