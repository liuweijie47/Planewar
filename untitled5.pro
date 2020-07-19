#-------------------------------------------------
#
# Project created by QtCreator 2020-07-09T20:45:44
#
#-------------------------------------------------

QT       += core gui  multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled5
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    bullet.cpp \
    bomb.cpp \
    emeyplane.cpp \
    map.cpp \
    weplane.cpp \
    bomb1.cpp \
    mainwindow.cpp \
    wuqi.cpp \
    bigboos.cpp \
    bomb2.cpp

HEADERS += \
        widget.h \
    config.h \
    bullet.h \
    bomb.h \
    emeyplane.h \
    map.h \
    weplane.h \
    bomb1.h \
    mainwindow.h \
    wuqi.h \
    bigboos.h \
    bomb2.h

FORMS += \
        widget.ui \
    mainwindow.ui
