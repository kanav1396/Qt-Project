#-------------------------------------------------
#
# Project created by QtCreator 2015-12-19T15:15:46
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = try
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jsonget.cpp

HEADERS  += mainwindow.h \
    jsonget.h

FORMS    += mainwindow.ui

INCLUDE += /home/zootorg/Documents/cpr_main/include
