#-------------------------------------------------
#
# Project created by QtCreator 2019-07-01T17:07:27
#
-------------------------------------------------
INCLUDEPATH +=$$PWD/include\
$$PWD/include/halconcpp
LIBS +=$$PWD/lib/x64-win64/halcon.lib\
$$PWD/lib/x64-win64/halconc.lib\
$$PWD/lib/x64-win64/halconcpp.lib\
$$PWD/lib/x64-win64/halconcppxl.lib\
$$PWD/lib/x64-win64/halconcxl.lib\
$$PWD/lib/x64-win64/halconxl.lib\
$$PWD/lib/x64-win64/hdevenginecpp.lib\
$$PWD/lib/x64-win64/hdevenginecppxl.lib
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo_halconcpp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
