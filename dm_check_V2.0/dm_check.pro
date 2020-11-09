#-------------------------------------------------
#
# Project created by QtCreator 2019-07-12T16:55:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dm_check
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
CONFIG += C++11

# *************************Qt配置Halcon*****************************
# MacOS specific settings. Note that while dyld will search under
# /Library/Frameworks by default, the preprocessor/compiler/linker will not
# and need to be told explicitly.
macx {
  QMAKE_CXXFLAGS += -F/Library/Frameworks
  QMAKE_LFLAGS   += -F/Library/Frameworks
  LIBS           += -framework HALCONCpp
}
else {
  #defines
  win32:DEFINES += WIN32

  #includes
  INCLUDEPATH   += "$$(HALCONROOT)/include"
  INCLUDEPATH   += "$$(HALCONROOT)/include/halconcpp"

  #libs
  QMAKE_LIBDIR  += "$$(HALCONROOT)/lib/$$(HALCONARCH)"
  unix:LIBS     += -lhalconcpp -lhalcon -lXext -lX11 -ldl -lpthread
  win32:LIBS    += "$$(HALCONROOT)/lib/$$(HALCONARCH)/halconcpp.lib" \
                   "$$(HALCONROOT)/lib/$$(HALCONARCH)/halcon.lib"
}
