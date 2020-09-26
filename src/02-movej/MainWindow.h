
#ifndef AUBOROBOTQT_MAINWINDOW_H
#define AUBOROBOTQT_MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "../utils/Robot.h"
#include <QLineEdit>
#include "../utils/util.h"
#include "AuboRobotMetaType.h"
#include <QToolTip>
#include <math.h>

class MainWindow: public QWidget {
private:
    static double DEGREE2RA;

    QLineEdit* editPath;
    QLineEdit* editPort;
    QLineEdit *joint1;
    QLineEdit *joint2;
    QLineEdit *joint3;
    QLineEdit *joint4;
    QLineEdit *joint5;
    QLineEdit *joint6;
public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

    //连接槽函数
    void connectRobot();

    //断开连接槽函数
    void disConnectRobot();

    //归零位置
    void zeroPosition();

    //movej
    void moveJ();

};


#endif //AUBOROBOTQT_MAINWINDOW_H
