#-------------------------------------------------
#
# Project created by QtCreator 2019-07-08T09:34:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mynotepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    about.h

FORMS    += mainwindow.ui \
    about.ui

RESOURCES += \
    image/res.qrc

RC_FILE = myapp.rc
