#/* serial2net SSH - ComTester
# *
# * The Software "ComTester" is a handling tool for the diploma project
# * "serial2net" of hf-ict and should provide the possibility to users
# * testing there serial-ethernet converter installations.
# *
# * Copyright (C) 2016 Michael Ramstein 	<m.mislin@serial2net.ch>
# * Copyright (C) 2016 Michael Mislin 	<m.ramstein@serial2net.ch>
# * Copyright (C) 2016 Pascal Probst 	<p.probst@serial2net.ch>
# *
# * The software includes the libssh library https://www.libssh.org
# * libssh is open source licensed under the GNU Library (or: Lesser)
# * General Public License (LGPL).
# *
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
# *
# * This program is distributed in the hope that it will be useful, but
# * WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# * General Public License for more details.
# *
# * You should have received a copy of the GNU General Public License
# * along with this program; if not, see <http://www.gnu.org/licenses/>.
# */

QT      += core gui
QT      += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += c++11

#with TARGET the name of the deployed file will set
TARGET = ComTester0.0.1.9
TEMPLATE = app

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

DEFINES += LIBSSH_STATIC
LIBS += -L$$PWD/lib/ -Wl,-Bstatic -lssh -Wl,-Bdynamic -lws2_32 -lz -lssleay32 -llibeay32 -lgdi32

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

#set properties of deployed execute file
win32:
    QMAKE_TARGET_DESCRIPTION = Communication test serial2net
    VERSION = 0.0.1.9
    QMAKE_TARGET_PRODUCT = ComTester
    QMAKE_TARGET_COMPANY = www.serial2net.ch
    QMAKE_TARGET_COPYRIGHT = serial2net(C)
    RC_ICONS = resource/serial2netIco.ico

unix:

