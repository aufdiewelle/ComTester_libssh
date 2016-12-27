#-------------------------------------------------
#
# Project created by QtCreator 2016-11-11T12:35:00
#
#-------------------------------------------------

QT      += core gui
QT      += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += c++11

#TARGET = Name der Execute Datei
TARGET = ComTester0.0.0.1
TEMPLATE = app

#Einbinden der externe Library "libssh.h"
DEFINES += LIBSSH_STATIC
DEFINES += LIBSSH_STATIC
LIBS += -L$$PWD/lib/ -Wl,-Bstatic -lssh -Wl,-Bdynamic -lws2_32 -lz -lssleay32 -llibeay32 -lgdi32
#unix|win32: LIBS += -L$$PWD/lib/ -lssh

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

LIBS += -lws2_32

RESOURCES += resource.qrc

SOURCES += main.cpp\
        widget.cpp \
    sshtunnel.cpp \
    tcpsocket.cpp \
    textinterface.cpp \
    aboutdialog.cpp \
    aboutwidget.cpp \
    splashscreen.cpp \
    version.cpp

HEADERS  += widget.h \
    sshtunnel.h \
    tcpsocket.h \
    textinterface.h \
    aboutdialog.h \
    aboutwidget.h \
    splashscreen.h \
    version.h

FORMS +=

#Setzen der Eigenschaften der Deplyoment-Datei
win32:
    QMAKE_TARGET_DESCRIPTION = Communication test serial2net
    VERSION = 0.0.0.1
    QMAKE_TARGET_PRODUCT = ComTester
    QMAKE_TARGET_COMPANY = www.serial2net.ch
    QMAKE_TARGET_COPYRIGHT = serial2net(C)
    RC_ICONS = resource/serial2netIco.ico

unix:

