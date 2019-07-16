#ifndef INTERFACE4SELFCHECK_H
#define INTERFACE4SELFCHECK_H

#include "qglobal.h"
class QWidget;

class Interface4SelfCheck
{
public:
    Interface4SelfCheck()
    {
    }

    ~Interface4SelfCheck()
    {
    }

    virtual void selfCheck() const = 0;
    virtual QWidget *gui4selfCheck() const = 0;
};

QT_BEGIN_NAMESPACE

#define Interface4SelfCheck_iid "org.qt-project.Qt.Interface4SelfCheck"

Q_DECLARE_INTERFACE(Interface4SelfCheck, Interface4SelfCheck_iid)
QT_END_NAMESPACE

#endif // INTERFACE4SELFCHECK_H
