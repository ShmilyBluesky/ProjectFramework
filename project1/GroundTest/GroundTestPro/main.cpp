#include "mainwidget.h"
#include "pluginsmanager.h"
#include "frameworkintance.h"
#include "frameworkinterfaceimplement.h"
#include "global_process_define.h"
#include <QWidget>
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget w;
    w.show();

    FrameworkIntance::instance()->initInstance();

    QDir pluginDir(QApplication::applicationDirPath());
    pluginDir.cd("plugins");
    FrameworkIntance::instance()->pluginsManager()->initPlugins(pluginDir.absolutePath());

    FrameworkInterfaceImplement *framework = FrameworkIntance::instance()->framework();
    w.setSelfCheckWnd((QWidget*)framework->get(Plugin_SelfCheck, Cmd4SelfCheck_GetMainWnd).toInt());

    return a.exec();
}
