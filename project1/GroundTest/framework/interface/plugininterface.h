#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include "qglobal.h"
#include "global_define.h"
#include <QVariant>

class FrameworkInterface;

class PluginInterface
{
public:
    PluginInterface(FrameworkInterface *framework = 0) :
        m_framework(framework)
    {
    }

    virtual ~PluginInterface()
    {
    }

    // 框架接口指针
    bool isFrameworkValid() const
    {
        return (0 == m_framework) ? false : true;
    }
    FrameworkInterface *framework()
    {
        return m_framework;
    }
    void setFramework(FrameworkInterface *framework)
    {
        m_framework = framework;
    }

    // 接口
    virtual QString name() const = 0; // 插件名称
    virtual int id() const = 0; // 插件id，具有唯一性，每一个插件对应一个id
    virtual ProcessResult process(int iCmd, const QVariant& arg1 = QVariant(),
                                  const QVariant& arg2 = QVariant(),
                                  const QVariant& arg3 = QVariant(),
                                  const QVariant& arg4 = QVariant(),
                                  const QVariant& arg5 = QVariant(),
                                  const QVariant& arg6 = QVariant()) = 0; // 处理接口
    virtual QVariant get(int iCmd, const QVariant& arg = QVariant()) = 0; // 获取数据

private:
    FrameworkInterface *m_framework; // 框架接口指针
};

QT_BEGIN_NAMESPACE

#define PluginInterface_iid "org.qt-project.Qt.PluginInterface"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
QT_END_NAMESPACE

#endif // PLUGININTERFACE_H
