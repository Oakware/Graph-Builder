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

#ifndef BFS_H
#define BFS_H

#include <QMessageBox>
#include "GetVertex/getvertex.h"

#include <QQueue>
#include "AbstractGraph/abstractgraph.h"

void RunGrAlgoBFS(AbstractGraph *gr, const int &Stime){
	VectorListGS sgr = gr->GetGraphModel().ToVectorList();	// Return if
	if(sgr.count() <= 1){return;}							//  no vertexes

	int start = GetVertex::GetStartVertex(sgr.count()-1);	// Get start vertex
	if(!start){return;}

	QBitArray vis(sgr.count());		// Variables
	QQueue <int> qe;
	int ConComp = 1;

	qe << start; vis[start] = true;
	AG_CHANGE_VER_PARAM((*gr), start, color, Qt::blue)

	while(!qe.empty()){
		sleep(Stime);

		int v = qe.first();
		for(int i=0; i<sgr[v].count(); ++i){
			int to = sgr[v][i].to;
			if(!vis[to]){
				vis[to] = true;
				qe << to;
				AG_CHANGE_VER_PARAM((*gr), to, color, Qt::red)
				AG_CHANGE_RIB_PARAM((*gr), ABrib(v,to), color, Qt::blue)
			}
		}

		AG_CHANGE_VER_PARAM((*gr), v, color, Qt::gray)
		qe.dequeue();

		if(qe.empty()){
			for(int i=1; i<sgr.count(); ++i){
				if(!vis[i]){
					qe << i; vis[i] = true;
					AG_CHANGE_VER_PARAM((*gr), i, color, Qt::red)
					++ConComp; break;
				}
			}
		}else{
			AG_CHANGE_VER_PARAM((*gr), qe.head(), color, Qt::blue)
		}
	}

	if(gr->IsOriented()){
		QMessageBox::information(NULL, QObject::tr("BFS"), QObject::tr("Finished."));
	}else{
		QMessageBox::information(NULL, QObject::tr("BFS"), QObject::tr("Finished.") + "\n" +
				QObject::tr("Connected components count: ") + QString::number(ConComp));
	}
}

#endif // BFS_H
