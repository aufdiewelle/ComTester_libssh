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

#include "textinterface.h"

TextInterface::TextInterface()
{

}

QString TextInterface::getTextSocketInfo()
{
    TextSocketInfo =    "Source: Wikipedia \r\n"
                        "https://en.wikipedia.org/wiki/Network_socket \r\n"
                        "\r\n"
                        "A network socket is an endpoint for sending or "
                        "receiving data at a single node in a computer "
                        "network. Concretely, it is an internal representation "
                        "of this endpoint in the networking software "
                        "(protocol stack), such as an entry in a table ("
                        "listing communication protocol, destination, status, "
                        "etc.), and is a form of system resource. \r\n"
                        "\r\n"
                        "In practice \"socket\" usually refers to a socket "
                        "in an Internet Protocol (IP) network (where "
                        "sockets may be called Internet sockets), in "
                        "particular for the Transmission Control Protocol "
                        "(TCP), which is a protocol for one-to-one "
                        "connections. \r\n"
                        "In this context, sockets are assumed "
                        "to be associated with a specific socket address, "
                        "namely the IP address and a port number for the "
                        "local node, and there is a corresponding socket "
                        "address at the foreign node (other node), which "
                        "itself has an associated socket, used by the "
                        "foreign process\r\n"
                        "\r\n";


    return TextSocketInfo;
}

QString TextInterface::getTextTunnelInfo()
{
    TextTunnelInfo =    "Source: Wikipedia \r\n"
                        "https://en.wikipedia.org/wiki/Tunneling_protocol \r\n"
                        "\r\n"
                        "A Secure Shell (SSH) tunnel consists of an "
                        "encrypted tunnel created through an SSH "
                        "protocol connection. Users may set up SSH "
                        "tunnels to transfer unencrypted traffic over "
                        "a network through an encrypted channel. \r\n"
                        "\r\n"
                        "To set up a local SSH tunnel, one configures "
                        "an SSH client to forward a specified local port "
                        "to a port on the remote machine. Once the SSH tunnel "
                        "has been established, the user can connect to the "
                        "specified local port to access the network service. "
                        "The local port does not have to be the same as "
                        "the remote port. \r\n"
                        "\r\n"
                        "SSH tunnels provide a means to bypass firewalls that "
                        "prohibit certain Internet services – so long "
                        "as a site allows outgoing connections. For example, "
                        "an organization may prohibit a user from accessing "
                        "Internet web pages (port 80) directly without passing "
                        "through the organization's proxy filter (which provides "
                        "the organization with a means of monitoring and "
                        "controlling what the user sees through the web). "
                        "But users may not wish to have their web traffic "
                        "monitored or blocked by the organization's proxy "
                        "filter. If users can connect to an external SSH "
                        "server, they can create an SSH tunnel to forward "
                        "a given port on their local machine to port 80 on "
                        "a remote web server. To access the remote web server, "
                        "users would point their browser to the local port "
                        "at http://localhost/ \r\n"
                        "\r\n"
                        "The ComTester includes the open source library "
                        "libssh2 >https://www.libssh2.org> \r\n"
                        "\r\n";

    return TextTunnelInfo;
}

QString TextInterface::getTextScannerInfo()
{
    TextScannerInfo = "Scanner will provide the possibility "
                      "to scan the host for open port. Open "
                      "ports will be indicated by the text "
                      "\"! n Port open\". \r\n"
                      "\r\n"
                      "However, the port scanner tool is "
                      "not thought for do wide range scanning. \r\n"
                      "\r\n"
                      "The Software will be blocked during "
                      "scanning take place! \r\n"
                      "\r\n";


    return TextScannerInfo;
}

QString TextInterface::getTextCommandInfo()
{
    TextCommandInfo = "Stop sign for the serial communication "
                      "according technical manual of target "
                      "interface. \r\n"
                      "\r\n"
                      "Follwoing control signs are implemented "
                      "as follow: \r\n"
                      "\\a as <BEL>\t(bel) \r\n"
                      "\\b as <BS>\t(backspace) \r\n"
                      "\\t as <HT>\t(horizontal tab) \r\n"
                      "\\n as <LF>\t(new line) \r\n"
                      "\\v as <VT>\t(vertical tab) \r\n"
                      "\\f as <FF>\t(form feed) \r\n"
                      "\\r as <CR>\t(carriage return) \r\n"
                      "\r\n"
                      "Example: use \"<CR>\" instead of \"\\n\" \r\n"
                      "\r\n";

    return TextCommandInfo;
}

QString TextInterface::getTextLicense()
{
    TextLicense =     "serial2net SSH - ComTester\r\n"
                      "\r\n"
                      "The Software \"ComTester\" is a handling tool for the diploma project "
                      "\"serial2net\" of hf-ict and should provide the possibility to users "
                      "testing there serial-ethernet converter installations. \r\n"
                      "\r\n"
                      "Copyright (C) 2016 Michael Ramstein\r\n"
                      "   <m.mislin@serial2net.ch> \r\n"
                      "Copyright (C) 2016 Michael Mislin\r\n"
                      "   <m.ramstein@serial2net.ch> \r\n"
                      "Copyright (C) 2016 Pascal Probst\r\n"
                      "   <p.probst@serial2net.ch> \r\n"
                      "\r\n"
                      "The software is free for private persons to use at non-enterpriser "
                      "and non profit purpose only! \r\n"
                      "\r\n"
                      "The software includes the libssh2 library >https://www.libssh.org>. \r\n"
                      "libssh is open source licensed under the GNU Library (or: Lesser) "
                      "General Public License (LGPL). \r\n"
                      "\r\n"
                      "This program is free software; you can redistribute it and/or modify "
                      "it under the terms of the GNU General Public License as published by "
                      "the Free Software Foundation; either version 3 of the License, or "
                      "(at your option) any later version. \r\n"
                      "\r\n"
                      "This program is distributed in the hope that it will be useful, but "
                      "WITHOUT ANY WARRANTY; without even the implied warranty of "
                      "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU "
                      "General Public License for more details. \r\n"
                      "\r\n"
                      "You should have received a copy of the GNU General Public License "
                      "along with this program; if not, see <http://www.gnu.org/licenses/>. \r\n"
                      "\r\n";

    return TextLicense;
}

QString TextInterface::getTextEncyption()
{
    TextEncyption =   "The encryption is based at libssh which in this case "
                      "does use Libgcrypt."
                      "\r\n"
                      "For further infomation please check out: \r\n"
                      ">https://www.gnu.org/software/libgcrypt/>"
                      "\r\n";

    return TextEncyption;
}


QString TextInterface::getTextHelp()
{
    TextHelp =        "For help hover the cursor over a input field and the ToolTip will "
                      "show the purpose of it."
                      "\r\n"
                      "Some fields are holding additional informations about how to use."
                      "\r\n";

    return TextHelp;
}

