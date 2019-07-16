include($$PWD/interface/interface.pri)

SOURCES += \
    $$PWD/pluginsmanager.cpp \
    $$PWD/frameworkinterfaceimplement.cpp \
    $$PWD/frameworkintance.cpp

	
HEADERS += \
    $$PWD/pluginsmanager.h \
    $$PWD/frameworkinterface.h \
    $$PWD/frameworkinterfaceimplement.h \
    $$PWD/frameworkintance.h

	
INCLUDEPATH += $$PWD
