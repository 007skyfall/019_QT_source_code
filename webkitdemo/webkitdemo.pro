#-------------------------------------------------
#
# Project created by QtCreator 2019-07-10T14:25:01
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = webkitdemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui
