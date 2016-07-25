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

#include "dijkstradialog.h"
#include "ui_dijkstradialog.h"

DijkstraDialog::DijkstraDialog(AbstractGraph *gr, const DijkstraResult &res, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DijkstraDialog),
	Result(res), Graph(gr)
{
	ui->setupUi(this);
	ResetGraph(Graph);

	for(int i=1; i<Result.count(); ++i){			// Fill list of distances
		QTreeWidgetItem *it = new QTreeWidgetItem;
		it->setData(0, Qt::DisplayRole, i);
		if(Result[i].distance < RIB_INF_WEIGHT)
			{it->setData(1, Qt::DisplayRole, Result[i].distance);}
		else
			{it->setData(1, Qt::DisplayRole, tr("No path"));}
		ui->treeWidget->addTopLevelItem(it);
	}

	ui->treeWidget->sortByColumn(0, Qt::AscendingOrder);
}

DijkstraDialog::~DijkstraDialog(){delete ui;}

void DijkstraDialog::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *prev){
	if(prev)
		ResetVerPath(prev->data(0, Qt::DisplayRole).toInt(), Qt::green, Qt::black);
	if(current)
		ResetVerPath(current->data(0, Qt::DisplayRole).toInt(), Qt::blue, Qt::red);
}

void DijkstraDialog::ResetVerPath(int ver, QColor Cver, QColor Crib){
	int i = ver;
	AG_CHANGE_VER_PARAM((*Graph), i, color, Cver);

	while(Result[i].from){
		AG_CHANGE_VER_PARAM((*Graph), Result[i].from, color, Cver);
		AG_CHANGE_RIB_PARAM((*Graph), ABrib(Result[i].from, i), color, Crib);
		i = Result[i].from;
	}
}
