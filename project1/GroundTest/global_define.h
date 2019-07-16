#ifndef GLOBAL_DEFINE_H
#define GLOBAL_DEFINE_H

// 处理返回结果
enum ProcessResult
{
    Process_Success = 0, // 处理成功
    Process_NoPlugin = -1, // 未发现插件
    Process_NoPluginCmd = -2, // 不支持该插件命令
    Process_ParamError = -3, // 参数错误
    Process_UnkonwError = -4 // 未知错误
};

// 插件ID
enum PluginID
{
    Plugin_Unknow = 0, // 未知
    Plugin_SelfCheck = 1, // 自检
    Plugin_StatusMonitor = 2, // 状态监测
};

#endif // GLOBAL_DEFINE_H
