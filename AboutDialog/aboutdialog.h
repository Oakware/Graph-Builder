/*****************************************************************************
 * Copyright © 2015 Oakware - All Rights Reserved
 *
 * Github : <https://github.com/Oakware>
 * Authors: Ivan Kondratuk <i.o.kondratuk@gmail.com>
 *
 * This file is part of Graph Builder.
 *
 * Graph Builder is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Graph Builder is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Graph Builder.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QDesktopServices>
#include <QUrl>
#include "ui_aboutdialog.h"

class AboutDialog : public QDialog{
	Q_OBJECT
public:
	explicit AboutDialog(QWidget *parent = 0):
		QDialog(parent),
		ui(new Ui::AboutDialog)
	{
		ui->setupUi(this);
		resize(0, 0);
		setFixedSize(size());
	}

	~AboutDialog(){delete ui;}

private slots:
	void on_label_linkActivated(const QString &link){
		QDesktopServices::openUrl(link);
	}

private:
	Ui::AboutDialog *ui;

};

#endif // ABOUTDIALOG_H
