#ifndef FRAMEWORKINTERFACE_H
#define FRAMEWORKINTERFACE_H

#include "global_define.h"
#include <QVariant>

// 框架接口
class FrameworkInterface
{
public:
    FrameworkInterface()
    {
    }

    virtual ~FrameworkInterface()
    {
    }

    // 接口
    virtual ProcessResult process(PluginID id, int iCmd,
                                  const QVariant& arg1 = QVariant(),
                                  const QVariant& arg2 = QVariant(),
                                  const QVariant& arg3 = QVariant(),
                                  const QVariant& arg4 = QVariant(),
                                  const QVariant& arg5 = QVariant(),
                                  const QVariant& arg6 = QVariant()) = 0; // 处理接口
    virtual QVariant get(PluginID id, int iCmd,
                         const QVariant& arg = QVariant()) = 0; //
};

#endif // FRAMEWORKINTERFACE_H
