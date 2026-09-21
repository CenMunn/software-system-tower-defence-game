#-------------------------------------------------
#
# Project created by QtCreator 2020-05-29T22:55:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DQ-1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    game.cpp \
    tower.cpp \
    waypoint.cpp \
    mybutton.cpp \
    actor.cpp \
    bullet.cpp \
    enemy.cpp \
    basicenemy.cpp \
    basictower.cpp \
    towerup.cpp \
    enemyup.cpp \
    enemyupup.cpp \
    explain.cpp

HEADERS += \
        mainwindow.h \
    config.h \
    game.h \
    tower.h \
    mycoll.h \
    waypoint.h \
    mybutton.h \
    actor.h \
    bullet.h \
    enemy.h \
    basicenemy.h \
    basictower.h \
    towerup.h \
    enemyup.h \
    enemyupup.h \
    explain.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

CONFIG += console
