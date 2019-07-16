#include "selfcheckplugin.h"
#include "selfcheckmainwnd.h"
#include "global_process_define.h"
#include "framework/frameworkinterface.h"
#include <QDebug>

SelfCheckPlugin::SelfCheckPlugin(QObject *parent) :
    QObject(parent)
{
}

QString SelfCheckPlugin::name() const
{
    return tr("Self Check");
}

int SelfCheckPlugin::id() const
{
    return Plugin_SelfCheck;
}

ProcessResult SelfCheckPlugin::process(int iCmd,
                                       const QVariant &arg1,
                                       const QVariant &arg2,
                                       const QVariant &arg3,
                                       const QVariant &arg4,
                                       const QVariant &arg5,
                                       const QVariant &arg6)
{
    if (Cmd4SelfCheck_Debug == iCmd)
    {
        qDebug() << "self check process debug: " << arg1.toString();

        if (isFrameworkValid())
            framework()->process(Plugin_StatusMonitor, Cmd4StatusMonitor_Debug, QString("from self check ui."));

        return Process_Success;
    }

    return Process_UnkonwError;
}

QVariant SelfCheckPlugin::get(int iCmd, const QVariant &arg)
{
    QVariant result;

    if (Cmd4SelfCheck_GetMainWnd == iCmd)
    {
        SelfCheckMainWnd *wnd = new SelfCheckMainWnd();
        result = QVariant::fromValue<int>((int)wnd);
    }

    return result;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(SelfCheck, SelfCheckPlugin)
#endif // QT_VERSION < 0x050000
