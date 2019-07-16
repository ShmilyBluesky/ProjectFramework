#include "pluginsmanager.h"
#include "interface4selfcheck.h"
#include <QDir>
#include <QPluginLoader>

PluginsManager::PluginsManager(QObject *parent) :
    QObject(parent),
    m_plugin4SelfCheck(0)
{

}

PluginsManager::~PluginsManager()
{

}

void PluginsManager::initPlugins(const QString &dir)
{
    QDir plugindir(dir);

    foreach (const QString& fileName, plugindir.entryList(QStringList() << "*.dll", QDir::Files))
    {
        QPluginLoader pluginLoader(plugindir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
            Interface4SelfCheck *plugin4selfCheck = dynamic_cast<Interface4SelfCheck*>(plugin);

            // 自检插件
            if (0 != plugin4selfCheck)
            {
                if (0 == m_plugin4SelfCheck)
                    m_plugin4SelfCheck = plugin4selfCheck;
            }
        }
    }
}

Interface4SelfCheck *PluginsManager::getPlugin4SelfCheck() const
{
    return m_plugin4SelfCheck;
}
