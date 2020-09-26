
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    //初始化
    setWindowTitle("连接和断开连接机器人");
    //布局
    QVBoxLayout *layout = new QVBoxLayout;
    //输入ip和端口
    editPath = new QLineEdit("192.168.36.22");
    editPort = new QLineEdit("8899");
    //按钮
    QPushButton *btn1 = new QPushButton("连接机器人");
    QPushButton *btn2 = new QPushButton("断开连接机器人");
    //添加到布局中
    layout->addWidget(editPath);
    layout->addWidget(editPort);
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    //设置布局
    setLayout(layout);

    //连接机器人
    connect(btn1, &QPushButton::clicked, this, &MainWindow::connectRobot);
    //断开连接机器人
    connect(btn2, &QPushButton::clicked, this, &MainWindow::disConnectRobot);
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