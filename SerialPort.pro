#-------------------------------------------------
#
# Project created by QtCreator 2017-06-12 11:59:53
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPort
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp

HEADERS  += Widget.h

FORMS    += Widget.ui

QMAKE_CXXFLAGS += -std=gnu++14
