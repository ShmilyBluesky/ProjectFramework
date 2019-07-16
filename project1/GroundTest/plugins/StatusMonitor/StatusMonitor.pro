#-------------------------------------------------
#
# Project created by QtCreator 2019-07-15T22:16:13
#
#-------------------------------------------------
include($$PWD/../../framework/interface/interface.pri)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StatusMonitor
TEMPLATE = lib
DESTDIR = $$PLUGINDIR
CONFIG += plugin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        statusmonitorplugin.cpp

HEADERS += \
        statusmonitorplugin.h
DISTFILES += StatusMonitor.json 

unix {
    target.path = /usr/lib
    INSTALLS += target
}