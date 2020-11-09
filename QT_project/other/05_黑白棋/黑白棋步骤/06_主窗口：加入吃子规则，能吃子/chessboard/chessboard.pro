#-------------------------------------------------
#
# Project created by QtCreator 2015-06-30T20:36:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chessboard
TEMPLATE = app


SOURCES += main.cpp\
        chesswidget.cpp \
    mainwidget.cpp

HEADERS  += chesswidget.h \
    mainwidget.h

RESOURCES += \
    image.qrc

FORMS += \
    mainwidget.ui
