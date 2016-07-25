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

#ifndef DFS_H
#define DFS_H

#include <QMessageBox>
#include "AbstractGraph/abstractgraph.h"

void RunGrAlgoDFS(AbstractGraph *gr, const int &Stime){
	VectorListGS sgr = gr->GetGraphModel().ToVectorList();	// Return if
	if(sgr.count() <= 1){return;}							//  no vertexes

	int start = GetVertex::GetStartVertex(sgr.count()-1);	// Get start vertex
	if(!start){return;}

	QBitArray vis(sgr.count());			// Variables
	QStack <int> st;
	int ConComp = 1;

	st << start; vis[start] = true;
	AG_CHANGE_VER_PARAM((*gr), start, color, Qt::red)

	while(!st.empty()){
		sleep(Stime);

		int i, v = st.top();
		for(i=0; i<sgr[v].count(); ++i){
			if(!vis[sgr[v][i].to]){break;}
		}

		if(i < sgr[v].count()){
			i = sgr[v][i].to;
			st << i;
			vis[i] = true;

			AG_CHANGE_VER_PARAM((*gr), i, color, Qt::red)
			AG_CHANGE_VER_PARAM((*gr), v, color, Qt::gray)
			AG_CHANGE_RIB_PARAM((*gr), ABrib(v,i), color, Qt::blue)
		}else{
			st.pop();
			AG_CHANGE_VER_PARAM((*gr), v, color, Qt::black)
			if(!st.empty()){
				AG_CHANGE_VER_PARAM((*gr), st.top(), color, Qt::red)
			}
		}

		if(st.empty()){
			for(int i=1; i<sgr.count(); ++i){
				if(!vis[i]){
					st << i; vis[i] = true;
					AG_CHANGE_VER_PARAM((*gr), i, color, Qt::red)
					++ConComp; break;
				}
			}
		}
	}

	if(gr->IsOriented()){
		QMessageBox::information(NULL, QObject::tr("DFS"), QObject::tr("Finished."));
	}else{
		QMessageBox::information(NULL, QObject::tr("DFS"), QObject::tr("Finished.") + "\n" +
				QObject::tr("Connected components count: ") + QString::number(ConComp));
	}
}

#endif // DFS_H
