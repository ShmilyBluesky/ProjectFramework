#include "statusmonitorplugin.h"
#include "global_process_define.h"
#include <QDebug>

StatusMonitorPlugin::StatusMonitorPlugin(QObject *parent) :
    QObject(parent)
{
}

QString StatusMonitorPlugin::name() const
{
    return tr("Status Monitor");
}

int StatusMonitorPlugin::id() const
{
    return Plugin_StatusMonitor;
}

ProcessResult StatusMonitorPlugin::process(int iCmd, const QVariant &arg1,
                                           const QVariant &arg2,
                                           const QVariant &arg3,
                                           const QVariant &arg4,
                                           const QVariant &arg5,
                                           const QVariant &arg6)
{
    if (Cmd4StatusMonitor_Debug == iCmd)
    {
        qDebug() << "status monitor debug:" << arg1.toString();
        return Process_Success;
    }

    return Process_UnkonwError;
}

QVariant StatusMonitorPlugin::get(int iCmd, const QVariant &arg)
{
    return QVariant();
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(StatusMonitor, StatusMonitorPlugin)
#endif // QT_VERSION < 0x050000
