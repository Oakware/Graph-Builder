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

#ifndef GRAPHALGOBFS_H
#define GRAPHALGOBFS_H

#include <QDialog>
#include "ui_getvertex.h"

class GetVertex: public QDialog{
	Q_OBJECT
public:
	explicit GetVertex(int count, QWidget *parent = 0):
		QDialog(parent),
		ui(new Ui::GetVertex)
	{
		ui->setupUi(this);
		resize(0,0); setFixedSize(size());
		ui->spinBox->setMinimum(1);
		ui->spinBox->setMaximum(count);
	}

	~GetVertex(){delete ui;}

	static int GetStartVertex(int count, QWidget *par = 0){
		GetVertex gv(count, par);
		gv.exec();

		if(gv.result() == QDialog::Rejected){		// Return 0 if cancel
			return 0;
		}
		return gv.ui->spinBox->value();
	}

private:
	Ui::GetVertex *ui;
};

#endif // GRAPHALGOBFS_H
