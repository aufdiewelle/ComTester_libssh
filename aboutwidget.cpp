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

#include "aboutwidget.h"
#include "version.h"

#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QFont>

AboutWidget::AboutWidget(QWidget *parent) : QWidget(parent)
{
    Version *version = new Version();
    strSoftwareRelease = version -> getVersion();

    this -> setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    QSpacerItem *spiTabWidget1 = new QSpacerItem(10,10);

    QFont times20Bold("Times", 20, QFont::Bold);
    QFont times14Bold("Times", 14, QFont::Bold);
    QFont times12("Times", 12);
    QFont times10("Times", 10);

    lblImage = new QLabel();
    lblImage -> setAlignment(Qt::AlignCenter);

    lblSoftwareName = new QLabel(strSoftwareName);
    lblSoftwareName -> setFont(times20Bold);
    lblSoftwareName -> setAlignment(Qt::AlignCenter);

    lblSoftwareRelease = new QLabel(strSoftwareRelease);
    lblSoftwareRelease -> setFont(times14Bold);
    lblSoftwareRelease -> setAlignment(Qt::AlignCenter);

    lblHyperlink = new QLabel(strHyperlink);
    lblHyperlink -> setFont(times12);
    lblHyperlink -> setAlignment(Qt::AlignCenter);
    lblHyperlink -> setTextInteractionFlags(Qt::TextBrowserInteraction);
    lblHyperlink -> setOpenExternalLinks(true);

    lblGitRepo = new QLabel(strGitRepoLink);
    lblGitRepo -> setFont(times12);
    lblGitRepo -> setAlignment(Qt::AlignCenter);
    lblGitRepo -> setTextInteractionFlags(Qt::TextBrowserInteraction);
    lblGitRepo -> setOpenExternalLinks(true);

    lblEmailAdress = new QLabel(strEmailAdress);
    lblEmailAdress -> setFont(times12);
    lblEmailAdress -> setAlignment(Qt::AlignCenter);
    lblEmailAdress -> setOpenExternalLinks(true);

    lblDevelopedBy = new QLabel(strDevelopedBy);
    lblDevelopedBy -> setFont(times10);
    lblDevelopedBy -> setAlignment(Qt::AlignCenter);

    lblDeveloper1 = new QLabel(strDeveloper1);
    lblDeveloper1 -> setFont(times10);
    lblDeveloper1 -> setAlignment(Qt::AlignCenter);

    lblDeveloper2 = new QLabel(strDeveloper2);
    lblDeveloper2 -> setFont(times10);
    lblDeveloper2 -> setAlignment(Qt::AlignCenter);

    lblDeveloper3 = new QLabel(strDeveloper3);
    lblDeveloper3 -> setFont(times10);
    lblDeveloper3 -> setAlignment(Qt::AlignCenter);

    QVBoxLayout *vboMain = new QVBoxLayout();

    QPixmap pxmMainImage(":/resource/serial2net.png");
    lblImage -> setPixmap(pxmMainImage);
    lblHyperlink -> setOpenExternalLinks(true);

    vboMain -> addWidget(lblImage);
    vboMain -> addItem(spiTabWidget1);
    vboMain -> addWidget(lblSoftwareName);
    vboMain -> addWidget(lblSoftwareRelease);
    vboMain -> addItem(spiTabWidget1);
    vboMain -> addWidget(lblHyperlink);
    vboMain -> addItem(spiTabWidget1);
    vboMain -> addWidget(lblEmailAdress);
    vboMain -> addItem(spiTabWidget1);
    vboMain -> addWidget(lblGitRepo);
    vboMain -> addItem(spiTabWidget1);
    vboMain -> addWidget(lblDevelopedBy);
    vboMain -> addWidget(lblDeveloper1);
    vboMain -> addWidget(lblDeveloper2);
    vboMain -> addWidget(lblDeveloper3);
    vboMain -> setMargin(0);

    this -> setLayout(vboMain);
    this -> show();
}

