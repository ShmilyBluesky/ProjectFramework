#include "selfcheckplugin.h"
#include "selfcheckmainwnd.h"

SelfCheckPlugin::SelfCheckPlugin(QObject *parent) :
    QObject(parent)
{
}

void SelfCheckPlugin::selfCheck() const
{

}

QWidget *SelfCheckPlugin::gui4selfCheck() const
{
    QWidget *pWnd = 0;

    pWnd = new SelfCheckMainWnd();

    return pWnd;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(SelfCheck, SelfCheckPlugin)
#endif // QT_VERSION < 0x050000
