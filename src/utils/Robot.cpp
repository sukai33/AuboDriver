
#include "Robot.h"

using namespace aubo_robot_namespace;
//设置初始值
Robot *Robot::instance = nullptr;

Robot::Robot() {

}

Robot::~Robot() {
}

//获取Robot实例
Robot *Robot::getInstance() {
    if (Robot::instance == nullptr) {
        instance = new Robot;
    }
    return instance;
}

//初始化机械臂
int Robot::connect(char *path, int port) {

    int ret = aubo_robot_namespace::InterfaceCallSuccCode;

    /** 接口调用: 登录 ***/
    ret = robotService.robotServiceLogin(path, port, "aubo", "123456");
    if (ret == aubo_robot_namespace::InterfaceCallSuccCode) {
        std::cerr << "登录成功." << std::endl;
    } else {
        std::cerr << "登录失败." << std::endl;
    }


    /** 如果是连接真实机械臂，需要对机械臂进行初始化　**/
    aubo_robot_namespace::ROBOT_SERVICE_STATE result;

    //工具动力学参数
    aubo_robot_namespace::ToolDynamicsParam toolDynamicsParam;
    memset(&toolDynamicsParam, 0, sizeof(toolDynamicsParam));

    ret = robotService.rootServiceRobotStartup(toolDynamicsParam/**工具动力学参数**/,
                                               6        /*碰撞等级*/,
                                               true     /*是否允许读取位姿　默认为true*/,
                                               true,    /*是否允许侦测静态碰撞 */
                                               1000,    /*接口板允许的最大加速度 */
                                               result); /*机械臂初始化*/
    if (ret == aubo_robot_namespace::InterfaceCallSuccCode) {
        std::cerr << "机械臂初始化成功." << std::endl;
    } else {
        std::cerr << "机械臂初始化失败." << ret << std::endl;
    }
    return ret;
}

//断开连接
void Robot::disConnect() {
    int result = aubo_robot_namespace::ErrnoSucc;
    /** 机械臂Shutdown **/
//    result = robotService.robotServiceRobotShutdown();
//    if (result != aubo_robot_namespace::ErrnoSucc) {
//        qDebug() << "关闭机械臂失败" << endl;
//        return;
//    }
    /** 接口调用: 退出登录　**/
    result = robotService.robotServiceLogout();
    if (result != aubo_robot_namespace::ErrnoSucc) {
        qDebug() << "退出登录失败" << endl;
        return;
    }
    qDebug() << "断开连接成功" << endl;
}

/**
 * 获取关节状态
 * @param jointStatus 存放关节状态
 * @param size  关节数量
 * @return 获取成功或者失败  aubo_robot_namespace::InterfaceCallSuccCode为成功
 */
int Robot::robotServiceGetRobotJointStatus(aubo_robot_namespace::JointStatus *jointStatus, int size) {
    return robotService.robotServiceGetRobotJointStatus(jointStatus, 6);
}

//设置关节运动的最大加速度
int Robot::robotServiceSetGlobalMoveJointMaxAcc(const aubo_robot_namespace::JointVelcAccParam &moveMaxAcc) {

    return robotService.robotServiceSetGlobalMoveJointMaxAcc(moveMaxAcc);
}

//设置关节运动的最大速度
int Robot::robotServiceSetGlobalMoveJointMaxVelc(const aubo_robot_namespace::JointVelcAccParam &moveMaxVelc) {

    return robotService.robotServiceSetGlobalMoveJointMaxVelc(moveMaxVelc);
}

/**
 * movej运动
 * @param jointAngle 各个关节的角度
 * @param IsBolck  是否阻塞线程
 */
int Robot::moveJ(double jointAngle[aubo_robot_namespace::ARM_DOF], bool isBlock) {
    SetGlobalMoveJointMaxParams();
    //关节移动
    return robotService.robotServiceJointMove(jointAngle, isBlock);
}

//moveL
int Robot::moveL(aubo_robot_namespace::wayPoint_S &wayPoint, bool IsBolck) {
    SetGlobalMoveJointMaxParams();
    return robotService.robotServiceLineMove(wayPoint, IsBolck);
}
/**
 * 通过反解位姿之后的关节角通过moveL移动
 * @param pose
 * @param IsBolck
 * @return
 */
int Robot::moveL(const double *pose, bool IsBolck) {
    // 当前关节角
    JointParam jointParam;
    int rst1 = Robot::getInstance()->robotServiceGetJointAngleInfo(jointParam);
    if (rst1 != ErrnoSucc) {
        qDebug() << "逆解时, 未能获取当前关节角";
        return rst1;
    }

    aubo_robot_namespace::Pos pos{pose[0], pose[1], pose[2]};
    aubo_robot_namespace::Rpy rpy{pose[3], pose[4], pose[5]};
    aubo_robot_namespace::Ori orientation{};

    RPYToQuaternion(rpy, orientation);

    qDebug() << "wayPoint x: " << pos.x << " y: " << pos.y << " z: " << pos.z;
    qDebug() << "rpy rx: " << rpy.rx * RA2DE << " ry: " << rpy.ry * RA2DE<< " rz: " << rpy.rz * RA2DE;

    std::cout << "逆解结果---------------------------------------" << std::endl;
    // 目标位置
    aubo_robot_namespace::Pos position = pos;
    // 目标姿态
    aubo_robot_namespace::Ori ori = orientation;
    // 输出结果：目标的关节角
    aubo_robot_namespace::wayPoint_S targetWayPoint;

    int rst2 = Robot::getInstance()->robotServiceRobotIk(jointParam.jointPos, position, ori, targetWayPoint);
    if (rst2 != ErrnoSucc) {
        qDebug() << "逆解失败";
        return rst2;
    }

    SetGlobalMoveJointMaxParams();
    return robotService.robotServiceLineMove(targetWayPoint.jointpos, IsBolck);
}

/**
 * 通过反解之后的关节角通过moveL移动
 * @param jointAngle
 * @param IsBolck
 * @return
 */
int Robot::moveL2(double *jointAngle, bool IsBolck) {
    SetGlobalMoveJointMaxParams();
    return robotService.robotServiceLineMove(jointAngle, IsBolck);
}

void Robot::SetGlobalMoveJointMaxParams() {//关节型运动最大的加速度
    aubo_robot_namespace::JointVelcAccParam jointMaxAcc;
    double maxAccJoint = 60.0;
    jointMaxAcc.jointPara[0] = maxAccJoint / 180.0 * M_PI;
    jointMaxAcc.jointPara[1] = maxAccJoint / 180.0 * M_PI;
    jointMaxAcc.jointPara[2] = maxAccJoint / 180.0 * M_PI;
    jointMaxAcc.jointPara[3] = maxAccJoint / 180.0 * M_PI;
    jointMaxAcc.jointPara[4] = maxAccJoint / 180.0 * M_PI;
    jointMaxAcc.jointPara[5] = maxAccJoint / 180.0 * M_PI;   //接口要求单位是弧度

    //关节型运动最大的速度
    aubo_robot_namespace::JointVelcAccParam jointMaxVelc;
    double maxVelcJoint = 80.0;
    jointMaxVelc.jointPara[0] = maxVelcJoint / 180.0 * M_PI;
    jointMaxVelc.jointPara[1] = maxVelcJoint / 180.0 * M_PI;
    jointMaxVelc.jointPara[2] = maxVelcJoint / 180.0 * M_PI;
    jointMaxVelc.jointPara[3] = maxVelcJoint / 180.0 * M_PI;
    jointMaxVelc.jointPara[4] = maxVelcJoint / 180.0 * M_PI;
    jointMaxVelc.jointPara[5] = maxVelcJoint / 180.0 * M_PI;   //接口要求单位是弧度
//设置最大加速度
    robotServiceSetGlobalMoveJointMaxAcc(jointMaxAcc);
    //设置最大速度
    robotServiceSetGlobalMoveJointMaxVelc(jointMaxVelc);
}

//设置运动属性的偏移
int Robot::robotServiceSetMoveRelativeParam() {
    /** 接口调用: 设置偏移量**/
    aubo_robot_namespace::MoveRelative relativeMoveOnBase;
    relativeMoveOnBase.ena = true;
    relativeMoveOnBase.relativePosition[0] = 0;
    relativeMoveOnBase.relativePosition[1] = 0;
    relativeMoveOnBase.relativePosition[2] = 0.05 * (0 % 4);   //单位米

    relativeMoveOnBase.relativeOri.w = 1;
    relativeMoveOnBase.relativeOri.x = 0;
    relativeMoveOnBase.relativeOri.y = 0;
    relativeMoveOnBase.relativeOri.z = 0;

    return robotService.robotServiceSetMoveRelativeParam(relativeMoveOnBase);
}

/**
 * rpy转四元素
 * @param rpy
 * @param ori
 * @return
 */
int Robot::RPYToQuaternion(const aubo_robot_namespace::Rpy &rpy, aubo_robot_namespace::Ori &ori) {
    return robotService.RPYToQuaternion(rpy, ori);
}


/**
 * @brief quaternionToRPY     四元素转欧拉角
 * @param ori　　　　　姿态的四元素表示方法
 * @param rpy　　　　　姿态的欧拉角表示方法
 * @return　调用成功返回ErrnoSucc;错误返回错误号
 */
int Robot::quaternionToRPY(const aubo_robot_namespace::Ori &ori, aubo_robot_namespace::Rpy &rpy){
    return robotService.quaternionToRPY(ori, rpy);
};

// 获取当前关节角信息
int Robot::robotServiceGetJointAngleInfo(aubo_robot_namespace::JointParam &jointParam) {
    return robotService.robotServiceGetJointAngleInfo(jointParam);
}

// 获取当前路点信息
int Robot::robotServiceGetCurrentWaypointInfo(aubo_robot_namespace::wayPoint_S &wayPoint) {
    return robotService.robotServiceGetCurrentWaypointInfo(wayPoint);
}

/**
     * 轨迹运动
     * @param subMoveMode
     * @param IsBolck
     * @return
     */
int Robot::moveTrack(aubo_robot_namespace::move_track subMoveMode, bool IsBolck) {
    return robotService.robotServiceTrackMove(subMoveMode, IsBolck);
}


/**
 * 添加路点，一般用于robotServiceTrackMove中
 * @param wayPoint 路点坐标以及姿态
 * @return
 */
int Robot::addGlobalWayPoint(const aubo_robot_namespace::wayPoint_S &wayPoint) {
    return robotService.robotServiceAddGlobalWayPoint(wayPoint);
}

/**
 * 路点关节角度
 * @param jointAngle
 * @return
 */
int Robot::addGlobalWayPoint(const double jointAngle[aubo_robot_namespace::ARM_DOF]) {
    return robotService.robotServiceAddGlobalWayPoint(jointAngle);
}

/**
 * 获取路点
 * @param wayPointVector
 */
void Robot::getGlobalWayPointVector(std::vector<aubo_robot_namespace::wayPoint_S> &wayPointVector) {
    robotService.robotServiceGetGlobalWayPointVector(wayPointVector);
}

/**
     * 获取交融半径
     * @return
     */
float Robot::getGlobalBlendRadius() {
    return robotService.robotServiceGetGlobalBlendRadius();
}

/**
 * 设置交融半径
 * @param value
 * @return
 */
int Robot::setGlobalBlendRadius(float value) {
    return robotService.robotServiceSetGlobalBlendRadius(value);
}


/**
 * 保持当前位姿通过直线运动的方式运动到目标位置
 * @param userCoord
 * @param toolEndPositionOnUserCoord
 * @param toolInEndDesc
 * @param IsBolck
 * @return
 */
int Robot::moveLineToTargetPosition(const aubo_robot_namespace::CoordCalibrateByJointAngleAndTool &userCoord,
                                    const aubo_robot_namespace::Pos &toolEndPositionOnUserCoord,
                                    const aubo_robot_namespace::ToolInEndDesc &toolInEndDesc,     //相对于用户坐标系的目标位置
                                    bool IsBolck) {
    return robotService.robotMoveLineToTargetPosition(userCoord, toolEndPositionOnUserCoord, toolInEndDesc, IsBolck);
}


/** 保持当前位姿通过关节运动的方式运动到目标位置   参数描述参考robotMoveLineToTargetPosition **/
int Robot::moveJointToTargetPosition(const aubo_robot_namespace::CoordCalibrateByJointAngleAndTool &userCoord,
                                     const aubo_robot_namespace::Pos &toolEndPositionOnUserCoord,
                                     const aubo_robot_namespace::ToolInEndDesc &toolInEndDesc,    //相对于用户坐标系的目标位置
                                     bool IsBolck) {
    return robotService.robotMoveJointToTargetPosition(userCoord, toolEndPositionOnUserCoord, toolInEndDesc, IsBolck);
}

/**
 * 获取机械臂当前路点信息
 * @param wayPoint
 * @return
 */
int Robot::getCurrentWaypointInfo(aubo_robot_namespace::wayPoint_S &wayPoint) {
    return robotService.robotServiceGetCurrentWaypointInfo(wayPoint);
}

/**
 * @brief 逆解　　　　　此函数为机械臂逆解函数，根据位置信息(x,y,z)和对应位置的参考姿态(w,x,y,z)得到对应位置的关节角信息。
 *      机器人运动学方程的逆解，也称机器人的逆运动学问题。
 *      逆运动学问题：对某个机器人，当给出机器人手部（法兰盘中心）在基座标系中所处的位置和姿态时，求出其对应的关节角信息。
*  @param startPointJointAngle 开始点关节角
 * @param position   目标路点的位置   　　　单位:米      输入参数
 * @param ori        目标路点的参考姿态     单位:弧度rad 输入参数　　　　例如：可以获取当前位置位姿作为此参数，这样相当于保持当前姿态
 * @param wayPoint   计算结果----目标路点信息
 * @return　调用成功返回 ErrnoSucc;错误返回错误号
 */
int Robot::robotServiceRobotIk(const double *startPointJointAngle, const aubo_robot_namespace::Pos &position,
                               const aubo_robot_namespace::Ori &ori, aubo_robot_namespace::wayPoint_S &wayPoint) {
    return robotService.robotServiceRobotIk(startPointJointAngle, position, ori, wayPoint);
}

/**
 * 初始化全局的运动属性
 * @return
 */
int Robot::robotServiceInitGlobalMoveProfile() {
    return robotService.robotServiceInitGlobalMoveProfile();
}

/**
 * 末端型运动的最大加速度
 * @param moveMaxAcc
 * @return
 */
int Robot::robotServiceSetGlobalMoveEndMaxLineAcc(double moveMaxAcc) {

    return robotService.robotServiceSetGlobalMoveEndMaxLineAcc(moveMaxAcc);
}

/**
 * 末端型运动的最大速度
 * @param moveMaxVelc
 * @return
 */
int Robot::robotServiceSetGlobalMoveEndMaxLineVelc(double moveMaxVelc) {

    return robotService.robotServiceSetGlobalMoveEndMaxLineVelc(moveMaxVelc);
}

int Robot::robotServiceSetGlobalMoveEndMaxAngleVelc(double moveMaxVelc) {
    return robotService.robotServiceSetGlobalMoveEndMaxAngleVelc(moveMaxVelc);
}

int Robot::robotServiceSetGlobalMoveEndMaxAngleAcc(double moveMaxAcc) {
    return robotService.robotServiceSetGlobalMoveEndMaxAngleAcc(moveMaxAcc);
}

/**
 * 添加路点
 * @param wayPoint
 * @return
 */
int Robot::robotServiceAddGlobalWayPoint(const double jointAngle[aubo_robot_namespace::ARM_DOF]) {

    return robotService.robotServiceAddGlobalWayPoint(jointAngle);
}

/**
 * 设置圆轨迹时圆的圈数
 * @param times
 */
void Robot::robotServiceSetGlobalCircularLoopTimes(int times) {
    robotService.robotServiceSetGlobalCircularLoopTimes(times);
}

/**
 * 正解
 * @param jointAngle
 * @param size
 * @param wayPoint
 * @return
 */
int Robot::robotServiceRobotFk(const double *jointAngle, int size, aubo_robot_namespace::wayPoint_S &wayPoint) {
    return robotService.robotServiceRobotFk(jointAngle, size, wayPoint);
}
/**
 * 状态回调
 * @param ptr
 * @param arg
 * @return
 */
int Robot::robotServiceRegisterRealTimeJointStatusCallback(RealTimeJointStatusCallback ptr, void *arg) {
    return robotService.robotServiceRegisterRealTimeJointStatusCallback(ptr,arg);
}


/**
 * 获取用户IO
 * @param type
 * @param name
 * @param value
 * @return
 */
int Robot::robotServiceGetBoardIOStatus(aubo_robot_namespace::RobotIoType type, std::string name, double &value) {
    return robotService.robotServiceGetBoardIOStatus(type, name, value);
}

/**
 * 设置用户IO
 * @param type
 * @param name
 * @param value
 * @return
 */
int Robot::robotServiceSetBoardIOStatus(aubo_robot_namespace::RobotIoType type, std::string name, double value) {
    return robotService.robotServiceSetBoardIOStatus(type,name,value);
}

/**
 * 设置用户IO
 * @param type
 * @param addr
 * @param value
 * @return
 */
int Robot::robotServiceSetBoardIOStatus(aubo_robot_namespace::RobotIoType type, int addr, double value) {
    return robotService.robotServiceSetBoardIOStatus(type,addr,value);
}

//设置机械臂工具
int Robot::robotServiceSetRobotTool(const aubo_robot_namespace::ToolInEndDesc &robotTool) {
    return robotService.robotServiceSetRobotTool(robotTool);
}



