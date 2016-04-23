#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T11:32:43
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MDB-project
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_features2d -lopencv_flann -lopencv_nonfree

SOURCES += main.cpp\
        mainwindow.cpp \
    matching.cpp

HEADERS  += mainwindow.h \
    matching.h

FORMS    += mainwindow.ui
