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

#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QWidget>
#include <QString>
#include <QSpacerItem>

class QLabel;

class AboutWidget : public QWidget
{
    public:
        AboutWidget(QWidget *parent = 0);

    private:
        QString strSoftwareName = "ComTester (C) 2016";
        QString strSoftwareRelease = "V0.0.0.1";
        QString strHyperlink = "<a href=\"http://www.serial2net.ch\">www.serial2net.ch</a>";
        QString strEmailAdress = "<a href='mailto:info@serial2net.ch'>info@serial2net.ch</a>";
        QString strDevelopedBy = "Entwickelt von:";
        QString strDeveloper1 = "Michael Ramstein";
        QString strDeveloper2 = "Pascal Probst";
        QString strDeveloper3 = "Michael Mislin";

        QLabel *lblImage;
        QLabel *lblSoftwareName;
        QLabel *lblSoftwareRelease;
        QLabel *lblHyperlink;
        QLabel *lblEmailAdress;
        QLabel *lblDevelopedBy;
        QLabel *lblDeveloper1;
        QLabel *lblDeveloper2;
        QLabel *lblDeveloper3;
};

#endif // ABOUTWIDGET_H
