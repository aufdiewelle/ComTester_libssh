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

#ifndef SSHTUNNEL_H
#define SSHTUNNEL_H

#include <libssh/libssh.h>
#include <QString>

class sshtunnel
{
    public:
        sshtunnel(int varTimeoutTunnel, int varTimeoutCommand);
        int getTunnelData(int sshPort,
                          char *sshHost,
                          char *sshUser,
                          char *sshPassword,
                          char *TunnelHost,  //TODO: not used
                          int tunnelClientPort,
                          int tunnelServerPort,
                          char *socketHost,
                          int socketPort);
        int doConnectDisconnectTunnel(bool stateBtnConnectTunnel);
        int direct_forwarding_connect(ssh_session session);
        int direct_forwarding_send_reveive(QString strCommand);
        int direct_forwarding_disconnect();
        int verify_knownhost(ssh_session mySshSession);
        QString getCommand();

    private:
        ssh_session mySshSession;
        int rc;
        ssh_channel forwarding_channel;
        int sshPort = -1;
        const char *sshHost = "";
        const char *sshUser = "";
        const char *sshPassword = "";
        const char *TunnelHost = "";
        int tunnelClientPort = -1;
        int tunnelServerPort = -1; //TODO: not used
        const char *socketHost = "";
        int socketPort = -1;
        QString strCommand = "";
        QString strCommandReturn = "";
        char *chrCommand;
        bool stateBtnConnectTunnel = false;
        bool stateBtnConnectSocket = false;
        int varTimeoutTunnel; // not in use bacause libssh has internal delays
        int varTimeoutCommand; // not in use bacause libssh has internal delays
};

#endif // SSHTUNNEL_H
