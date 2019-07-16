#include "frameworkintance.h"
#include "pluginsmanager.h"
#include "frameworkinterfaceimplement.h"

FrameworkIntance *FrameworkIntance::m_instance = 0;

FrameworkIntance::FrameworkIntance(QObject *parent) :
    QObject(parent),
    m_pluginManager(0),
    m_frameworkInIm(0)
{

}

FrameworkIntance::~FrameworkIntance()
{
    if (0 != m_frameworkInIm)
        delete m_frameworkInIm;

    if (0 != m_pluginManager)
        m_pluginManager->deleteLater();
}

FrameworkIntance *FrameworkIntance::instance()
{
    if (0 == FrameworkIntance::m_instance)
        FrameworkIntance::m_instance = new FrameworkIntance();

    return FrameworkIntance::m_instance;
}

void FrameworkIntance::initInstance()
{
    m_pluginManager = new PluginsManager();

    m_frameworkInIm = new FrameworkInterfaceImplement(m_pluginManager);
}

PluginsManager *FrameworkIntance::pluginsManager() const
{
    return m_pluginManager;
}

FrameworkInterfaceImplement *FrameworkIntance::framework()
{
    return m_frameworkInIm;
}
