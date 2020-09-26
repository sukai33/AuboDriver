
#ifndef AUBOROBOTQT_MAINWINDOW_H
#define AUBOROBOTQT_MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "../utils/Robot.h"
#include <QLineEdit>
class MainWindow: public QWidget {
    Q_OBJECT
private:
    QLineEdit* editPath;
    QLineEdit* editPort;
public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

    //连接槽函数
    void connectRobot();

    //断开连接槽函数
    void disConnectRobot();

};


#endif //AUBOROBOTQT_MAINWINDOW_H
