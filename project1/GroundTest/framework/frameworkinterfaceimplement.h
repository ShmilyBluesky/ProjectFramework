#ifndef FRAMEWORKINTERFACEIMPLEMENT_H
#define FRAMEWORKINTERFACEIMPLEMENT_H

#include <QObject>
#include "frameworkinterface.h"

class PluginsManager;

class FrameworkInterfaceImplement : public FrameworkInterface
{
public:
    explicit FrameworkInterfaceImplement(PluginsManager *pluginManager);
    ~FrameworkInterfaceImplement();

    // inherite from FrameworkInterface
    virtual ProcessResult process(PluginID id, int iCmd,
                                  const QVariant& arg1 = QVariant(),
                                  const QVariant& arg2 = QVariant(),
                                  const QVariant& arg3 = QVariant(),
                                  const QVariant& arg4 = QVariant(),
                                  const QVariant& arg5 = QVariant(),
                                  const QVariant& arg6 = QVariant()); // 处理接口
    virtual QVariant get(PluginID id, int iCmd,
                         const QVariant& arg = QVariant()); // 获取数据

signals:

public slots:

private:
    PluginsManager *m_pluginManager; // 插件管理器
};

#endif // FRAMEWORKINTERFACEIMPLEMENT_H
