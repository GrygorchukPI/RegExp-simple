#-------------------------------------------------
#
# Project created by QtCreator 2018-06-07T20:24:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Text_Analysis_v_-_0_1
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

INCLUDEPATH += /home/pasha/Development/Third_Party/boost/include
LIBS +=  -L/home/pasha/Development/Third_Party/boost/lib -lboost_timer -lboost_chrono -lboost_system

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    RegExp.cpp

HEADERS += \
        mainwindow.h \
    RegExp.h

FORMS += \
        mainwindow.ui
