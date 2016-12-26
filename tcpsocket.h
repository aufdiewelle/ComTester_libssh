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

#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QString>
#include <QTcpSocket>

class QTcpSocket;


class tcpsocket
{
    public:
        tcpsocket(int varTimeoutSocket, int varTimeoutCommand);
        bool doConnect(QString host, int port, int varTimeoutSocket);
        QString doWriteRead(QString var, int varTimeoutCommand);
        bool doDisconnect();

    private:
        QTcpSocket *iolanSocket;
        QString host;
        int port;
        int varTimeoutSocket;
        int varTimeoutCommand;
};

#endif // TCPSOCKET_H
