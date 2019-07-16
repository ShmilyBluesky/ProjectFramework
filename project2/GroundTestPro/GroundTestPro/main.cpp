#include "mainwidget.h"
#include "pluginsmanager.h"
#include "interface4selfcheck.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget w;
    w.show();

    PluginsManager pluginMgr;
    QDir pluginDir(QApplication::applicationDirPath());
    pluginDir.cd("plugins");
    pluginMgr.initPlugins(pluginDir.absolutePath());

    w.setSelfCheckWnd(pluginMgr.getPlugin4SelfCheck()->gui4selfCheck());

    return a.exec();
}
