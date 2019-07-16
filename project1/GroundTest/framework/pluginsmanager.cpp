#include "pluginsmanager.h"
#include "plugininterface.h"
#include "frameworkintance.h"
#include "frameworkinterfaceimplement.h"
#include <QDir>
#include <QPluginLoader>

PluginsManager::PluginsManager(QObject *parent) :
    QObject(parent)
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
            PluginInterface *pluginInterface = dynamic_cast<PluginInterface*>(plugin);

            // 自检插件
            if (0 != pluginInterface)
            {
                int iPluginID = pluginInterface->id();
                if (!m_hashPlugins.contains(iPluginID))
                {
                    FrameworkInterface *frameworkInterface = FrameworkIntance::instance()->framework();
                    pluginInterface->setFramework(frameworkInterface);
                    m_hashPlugins[iPluginID] = pluginInterface;
                }
            }
        }
    }
}

PluginInterface *PluginsManager::getPluginInterface(int id) const
{
    PluginInterface *result = 0;

    if (m_hashPlugins.contains(id))
        result = m_hashPlugins[id];

    return result;
}

bool PluginsManager::hasPluginInterface(int id) const
{
    PluginInterface *result = 0;

    if (m_hashPlugins.contains(id))
        result = m_hashPlugins[id];

    if (0 != result)
        return true;

    return false;
}
