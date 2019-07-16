#ifndef GLOBAL_PROCESS_DEFINE_H
#define GLOBAL_PROCESS_DEFINE_H

// 自检命令定义
enum Cmd4SelfCheck
{
    Cmd4SelfCheck_Debug = 1, // 第一条自检命令
    Cmd4SelfCheck_GetMainWnd, // 获取主窗口
};

// 状态监测命令
enum Cmd4StatusMonitor
{
    Cmd4StatusMonitor_Debug = 100, // 第一条状态监测命令
};

#endif // GLOBAL_PROCESS_DEFINE_H
