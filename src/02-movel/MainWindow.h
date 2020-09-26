
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

class MainWindow : public QWidget {
private:
    static double DEGREE2RA;

    QLineEdit *editPath;
    QLineEdit *editPort;
    QLineEdit *pos_x;
    QLineEdit *pos_y;
    QLineEdit *pos_z;
    QLineEdit *rpy_x;
    QLineEdit *rpy_y;
    QLineEdit *rpy_z;
public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    //连接槽函数
    void connectRobot();

    //断开连接槽函数
    void disConnectRobot();

    //归零位置
    void zeroPosition();
    void targetPosition();

    //movej
    void moveL();
    void moveL2();
};


#endif //AUBOROBOTQT_MAINWINDOW_H
