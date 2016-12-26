/* serial2net SSH - ComTester
 *
 * The Software "ComTester" is a handling tool for the diploma project
 * "serial2net" of hf-ict and should provide the possibility to users
 * testing there serial-ethernet converter installations.
 *
 * Copyright (C) 2016 Michael Ramstein 	<m.mislin@serial2net.ch>
 * Copyright (C) 2016 Michael Mislin 	<m.ramstein@serial2net.ch>
 * Copyright (C) 2016 Pascal Probst 	<p.probst@serial2net.ch>
 *
 * The software includes the libssh library https://www.libssh.org
 * libssh is open source licensed under the GNU Library (or: Lesser)
 * General Public License (LGPL).
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "tcpsocket.h"
#include <QDebug>

tcpsocket::tcpsocket(int varTimeoutSocket, int varTimeoutCommand)
{
    iolanSocket = new QTcpSocket();
    this -> varTimeoutSocket = varTimeoutSocket;
    qDebug() << "varTimeoutSocket" << varTimeoutSocket;
    this -> varTimeoutCommand = varTimeoutCommand;
    qDebug() << "varTimeoutCommand" << varTimeoutCommand;
}

bool tcpsocket::doConnect(QString host, int port, int varTimeoutSocket)
{
    this -> varTimeoutSocket = varTimeoutSocket;
    qDebug() << "varTimeoutSocket" << varTimeoutSocket;

    iolanSocket -> connectToHost(host, port, QIODevice::ReadWrite);

    if(iolanSocket -> waitForConnected(varTimeoutSocket))
    {
        qDebug() << "Connected!";
        return true;
    }
    else
    {
        qDebug() << "Not connected!";
        return false;
    }
}


QString tcpsocket::doWriteRead(QString var, int varTimeoutCommand)
{
    this -> varTimeoutCommand = varTimeoutCommand;
    qDebug() << "varTimeoutCommand" << varTimeoutCommand;

    QByteArray array (var.toStdString().c_str());

    // send
        qDebug() << "Send: " << array;
        iolanSocket -> write(array);
        iolanSocket -> waitForBytesWritten(varTimeoutCommand);
        iolanSocket -> waitForReadyRead(varTimeoutCommand);

        qDebug() << "Number of Reading ASCII signs: " << iolanSocket -> bytesAvailable();

    // get the data
        var = iolanSocket -> readAll();
        return var;
}

bool tcpsocket::doDisconnect()
{
    // close the connection
    iolanSocket -> close();
    return true;
}

