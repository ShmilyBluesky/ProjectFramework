#ifndef SELFCHECKPLUGIN_H
#define SELFCHECKPLUGIN_H

#include <QObject>
#include "plugininterface.h"

class SelfCheckPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QGenericPluginFactoryInterface" FILE "SelfCheck.json")
#endif // QT_VERSION >= 0x050000
    Q_INTERFACES(PluginInterface)
public:
    SelfCheckPlugin(QObject *parent = 0);

    // inherite from interface
    QString name() const; // 插件名称
    int id() const; // 插件id，具有唯一性，每一个插件对应一个id
    ProcessResult process(int iCmd, const QVariant& arg1 = QVariant(),
                                  const QVariant& arg2 = QVariant(),
                                  const QVariant& arg3 = QVariant(),
                                  const QVariant& arg4 = QVariant(),
                                  const QVariant& arg5 = QVariant(),
                                  const QVariant& arg6 = QVariant()); // 处理接口
    QVariant get(int iCmd, const QVariant& arg = QVariant()); // 获取数据
};

#endif // SELFCHECKPLUGIN_H
