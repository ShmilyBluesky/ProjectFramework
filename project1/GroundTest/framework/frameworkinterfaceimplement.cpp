#include "frameworkinterfaceimplement.h"
#include "pluginsmanager.h"
#include "plugininterface.h"

FrameworkInterfaceImplement::FrameworkInterfaceImplement(PluginsManager *pluginManager) :
    m_pluginManager(pluginManager)
{

}

FrameworkInterfaceImplement::~FrameworkInterfaceImplement()
{

}

ProcessResult FrameworkInterfaceImplement::process(PluginID id, int iCmd,
                                                   const QVariant &arg1,
                                                   const QVariant &arg2,
                                                   const QVariant &arg3,
                                                   const QVariant &arg4,
                                                   const QVariant &arg5,
                                                   const QVariant &arg6)
{
    ProcessResult result = Process_NoPlugin;

    if (m_pluginManager->hasPluginInterface(id))
        result = m_pluginManager->getPluginInterface(id)->process(iCmd, arg1, arg2, arg3, arg4, arg5, arg6);

    return result;
}

QVariant FrameworkInterfaceImplement::get(PluginID id, int iCmd, const QVariant &arg)
{
    QVariant result;

    if (m_pluginManager->hasPluginInterface(id))
        return m_pluginManager->getPluginInterface(id)->get(iCmd, arg);

    return result;
}
