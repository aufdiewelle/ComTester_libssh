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

#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QThread>

#include "sshtunnel.h"

sshtunnel::sshtunnel(int varTimeoutTunnel, int varTimeoutCommand)
{
    this -> varTimeoutTunnel = varTimeoutTunnel; // not in use bacause libssh has internal delays
    this -> varTimeoutCommand = varTimeoutCommand; // not in use bacause libssh has internal delays
}

int sshtunnel::getTunnelData(int sshPort,
                             char *sshHost,
                             char *sshUser,
                             char *sshPassword,
                             char *TunnelHost,
                             int tunnelClientPort,
                             int tunnelServerPort, //TODO: not used
                             char *socketHost,
                             int socketPort)
{
    this -> sshPort = sshPort;
    this -> sshHost = sshHost;
    this -> sshUser = sshUser;
    this -> sshPassword = sshPassword;
    this -> TunnelHost = TunnelHost;
    this -> tunnelClientPort = tunnelClientPort;
    this -> tunnelServerPort = tunnelServerPort;  //TODO: not used
    this -> socketHost = socketHost;
    this -> socketPort = socketPort;

    qDebug() << this -> sshPort;
    qDebug() << this -> sshHost;
    qDebug() << this -> sshUser;
    qDebug() << this -> sshPassword;
    qDebug() << this -> TunnelHost;
    qDebug() << this -> tunnelClientPort;
    qDebug() << this -> tunnelServerPort; //TODO: not used
    qDebug() << this -> socketHost;
    qDebug() << this -> socketPort;
}

int sshtunnel::doConnectDisconnectTunnel(bool stateBtnConnectTunnel)
{
    this -> stateBtnConnectTunnel = stateBtnConnectTunnel;

    qDebug() << "enter doConnectDisconnectTunnel" << this -> stateBtnConnectTunnel;

    if(stateBtnConnectTunnel){
        int verbosity = SSH_LOG_PROTOCOL;

        mySshSession = ssh_new();
        if (mySshSession == NULL)
            exit(-1);

        ssh_options_set(mySshSession, SSH_OPTIONS_HOST, sshHost);
        ssh_options_set(mySshSession, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
        ssh_options_set(mySshSession, SSH_OPTIONS_PORT, &sshPort);
        ssh_options_set(mySshSession, SSH_OPTIONS_USER, sshUser);

        rc = ssh_connect(mySshSession);
        qDebug() << "Connect SSH" << rc;

        rc = ssh_userauth_password(mySshSession, NULL, sshPassword);
        qDebug() << "User authentificatiion" << rc;

        rc = direct_forwarding_connect(mySshSession);
        qDebug() << "Connect Tunnel" << rc;

        return rc;
    }

     if(!stateBtnConnectTunnel){

         rc = direct_forwarding_disconnect();

         ssh_disconnect(mySshSession);
         qDebug() << "Disconnect SSH" << rc;

         ssh_free(mySshSession);
         qDebug() << "Give SSH free" << rc;

        return rc;
     }
}

QString sshtunnel::getCommand()
{
    qDebug() << "getCommand: " << strCommandReturn;
    return strCommandReturn;
}


// Methode um SSH Tunnel zu erstellen
//siehe Link: http://api.libssh.org/master/libssh_tutor_forwarding.html
int sshtunnel::direct_forwarding_connect(ssh_session session)
{
    qDebug() << "enter direct_forwarding";

    forwarding_channel = ssh_channel_new(session);
    if (forwarding_channel == NULL) {
        qDebug() << "ssh_channel_free" << rc;
        return rc;
    }
    rc = ssh_channel_open_forward(forwarding_channel,
                                  TunnelHost, tunnelClientPort,
                                  socketHost, socketPort);
    qDebug() << "ssh_channel_open_forward" << rc;

    if (rc != SSH_OK)
    {
        ssh_channel_free(forwarding_channel);
        qDebug() << "ssh_channel_free" << rc;
        return rc;
    }

    return SSH_OK;
}

int sshtunnel::direct_forwarding_send_reveive(QString strCommand)
{
    qDebug() << "enter constructor sshtunnel" << this -> strCommand;

    QByteArray baCommand = strCommand.toLatin1();
    chrCommand = baCommand.data();
    qDebug() << chrCommand;

    int nbytes, nwritten, nread;


    // Schreiben auf Tunnel
    nbytes = strlen(chrCommand);

    nwritten = ssh_channel_write(forwarding_channel, chrCommand, nbytes); // Methode ssh_channel_write hat bei einem Fehler ein Timeout integriert!
    qDebug() << "nwritten: " << nwritten;

    // Lesen vom Tunnel
    char buffer[4096];

    nread = ssh_channel_read(forwarding_channel, buffer, sizeof(buffer), 0); // Methode ssh_channel_read hat bei einem Fehler ein Timeout integriert!
    qDebug() << "nread: " << nread;


    strCommand = "";
        for(int i = 0; i < nread; i++){
            strCommand = strCommand + buffer[i];
    }

    qDebug() << "SSH empfangen: " << strCommand;
    strCommandReturn = strCommand;

    if (nread < 0)
    {
        fprintf(stderr, "Error reading incoming data: %s\n",
        ssh_get_error(mySshSession));
        return SSH_ERROR;
    }
}

// Methode um den Server zu identifizieren, LIBSSH verwendet diese Methode
// ohne aufrufen immer dann, wenn der Server unbekannt ist.
// siehe Link: http://api.libssh.org/master/libssh_tutor_guided_tour.html
int sshtunnel::verify_knownhost(ssh_session mySshSession)
{
    qDebug() << "enter verify_knowhoat";
    int state, hlen;
    unsigned char *hash = NULL;
    char *hexa;
    char buf[10];

    state = ssh_is_server_known(mySshSession);
    hlen = ssh_get_pubkey_hash(mySshSession, &hash);
    if (hlen < 0)
    {
        qDebug() << "Error get pubkey hash.";
        return(-1);
    }
    switch (state)
    {
        case SSH_SERVER_KNOWN_OK:
            break; // ok
        case SSH_SERVER_KNOWN_CHANGED:
            qDebug() << "Host key for server changed: it is now:";
            ssh_print_hexa("Public key hash", hash, hlen);
            qDebug() << "For security reasons, connection will be stopped.";
            free(hash);
            return(-1);
        case SSH_SERVER_FOUND_OTHER:
            qDebug() << "The host key for this server was not found but an other type of key exists.";
            qDebug() << "An attacker might change the default server key to confuse your client into thinking the key does not exist.";
            free(hash);
            return(-1);
        case SSH_SERVER_FILE_NOT_FOUND:
            qDebug() << "Could not find known host file.";
            qDebug() << "If you accept the host key here, the file will be automatically created.";
        case SSH_SERVER_NOT_KNOWN: // fallback to SSH_SERVER_NOT_KNOWN behavior
            hexa = ssh_get_hexa(hash, hlen);
            qDebug() << "The server is unknown. Do you trust the host key ?";
            qDebug() << "Public key hash: " << hexa;
            free(hexa);
            if (fgets(buf, sizeof(buf), stdin) == NULL)
            {
                free(hash);
                return(-1);
            }
            if (strncasecmp(buf, "yes", 3) != 0)
            {
                free(hash);
                return(-1);
            }
            if (ssh_write_knownhost(mySshSession) < 0)
            {
                qDebug() << "Error " << strerror(errno);
                free(hash);
                return(-1);
            }
            break;
        case SSH_SERVER_ERROR:
            qDebug() << "Error " << ssh_get_error(mySshSession);
            free(hash);
            return(-1);
    }

    free(hash);
    return 0;
}

int sshtunnel::direct_forwarding_disconnect()
{
    ssh_channel_send_eof(forwarding_channel);
    ssh_channel_free(forwarding_channel);
}

