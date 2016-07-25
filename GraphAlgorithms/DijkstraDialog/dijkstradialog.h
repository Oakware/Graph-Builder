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

#ifndef DIJKSTRADIALOG_H
#define DIJKSTRADIALOG_H

#include <QDialog>
#include <QTreeWidget>

#include "../../AbstractGraph/abstractgraph.h"
#include "../reset_graph.h"

#define RIB_INF_WEIGHT 1000000

namespace Ui{class DijkstraDialog;}

struct DijkstraPath{
	DijkstraPath(unsigned dist=0, int fr=0):
		distance(dist), from(fr){}

	unsigned distance;
	int from;
};

typedef QVector<DijkstraPath> DijkstraResult;

class DijkstraDialog: public QDialog{
	Q_OBJECT
public:
	explicit DijkstraDialog(AbstractGraph *gr,
							const DijkstraResult &res,
							QWidget *parent = 0);
	~DijkstraDialog();

private slots:
	void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *prev);

private:
	void ResetVerPath(int ver, QColor Cver, QColor Crib);

private:
	Ui::DijkstraDialog *ui;

	DijkstraResult Result;
	AbstractGraph *Graph;
};

#endif // DIJKSTRADIALOG_H
