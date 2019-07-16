#ifndef SELFCHECKPLUGIN_H
#define SELFCHECKPLUGIN_H

#include <QObject>
#include "interface4selfcheck.h"

class SelfCheckPlugin : public QObject, public Interface4SelfCheck
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QGenericPluginFactoryInterface" FILE "SelfCheck.json")
#endif // QT_VERSION >= 0x050000
    Q_INTERFACES(Interface4SelfCheck)
public:
    SelfCheckPlugin(QObject *parent = 0);

    // inherite from interface
    void selfCheck() const;
    QWidget *gui4selfCheck() const;
};

#endif // SELFCHECKPLUGIN_H
