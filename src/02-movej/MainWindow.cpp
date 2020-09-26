
#include "MainWindow.h"

double MainWindow::DEGREE2RA  = M_PI/180;

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    //初始化
    setWindowTitle("连接和断开连接机器人");
    //布局
    QVBoxLayout *layout = new QVBoxLayout;
    //输入ip和端口
    editPath = new QLineEdit("192.168.36.29");
    editPort = new QLineEdit("8899");
    //按钮
    QPushButton *btn1 = new QPushButton("连接机器人");
    QPushButton *btn2 = new QPushButton("断开连接机器人");
    QPushButton *btn3 = new QPushButton("归零位置");
    QPushButton *btn4 = new QPushButton("movej移动机器人");
    //添加到布局中
    layout->addWidget(editPath);
    layout->addWidget(editPort);
    layout->addWidget(btn1);
    layout->addWidget(btn2);

    joint1 = new QLineEdit("0");
    joint2 = new QLineEdit("0");
    joint3 = new QLineEdit("0");
    joint4 = new QLineEdit("60");
    joint5 = new QLineEdit("0");
    joint6 = new QLineEdit("0");

    //添加输入框
    layout->addWidget(joint1);
    layout->addWidget(joint2);
    layout->addWidget(joint3);
    layout->addWidget(joint4);
    layout->addWidget(joint5);
    layout->addWidget(joint6);


    layout->addWidget(btn3);
    layout->addWidget(btn4);
    //设置布局
    setLayout(layout);

    //连接机器人
    connect(btn1, &QPushButton::clicked, this, &MainWindow::connectRobot);
    //断开连接机器人
    connect(btn2, &QPushButton::clicked, this, &MainWindow::disConnectRobot);
    //归零位置
    connect(btn3, &QPushButton::clicked, this, &MainWindow::zeroPosition);
    //movej
    connect(btn4, &QPushButton::clicked, this, &MainWindow::moveJ);
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
    double jointAngle[aubo_robot_namespace::ARM_DOF] = {0*DEGREE2RA,45*DEGREE2RA,-30*DEGREE2RA,30*DEGREE2RA,0,0};
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

//movej
void MainWindow::moveJ() {
    qDebug()<<"move"<<endl;
    //获取6个关节的角度
    double angle1 = joint1->text().toDouble()*DEGREE2RA;
    double angle2 = joint2->text().toDouble()*DEGREE2RA;
    double angle3 = joint1->text().toDouble()*DEGREE2RA;
    double angle4 = joint4->text().toDouble()*DEGREE2RA;
    double angle5 = joint5->text().toDouble()*DEGREE2RA;
    double angle6 = joint6->text().toDouble()*DEGREE2RA;
    //6个关节的角度
    double jointAngle[aubo_robot_namespace::ARM_DOF]{angle1,angle2,angle3,angle4,angle5,angle6};

    //移动关节
    Robot::getInstance()->moveJ(jointAngle,true);
}