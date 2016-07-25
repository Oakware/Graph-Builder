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

#ifndef DIJKSTRA
#define DIJKSTRA

#include <QMessageBox>
#include <QBitArray>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#include "AbstractGraph/abstractgraph.h"
#include "DijkstraDialog/dijkstradialog.h"

struct DistanceToVertex{
	DistanceToVertex(unsigned _res, int _vertex):
		res(_res), vertex(_vertex){}

	bool operator < (const DistanceToVertex& other)const
		{return res > other.res;}

	unsigned res; int vertex;
};

void RunGrAlgoDijkstra(AbstractGraph *gr, const int &Stime){
	VectorListGS sgr = gr->GetGraphModel().ToVectorList();	// Return if
	if(sgr.count() <= 1){return;}							//  no vertexes

	int start = GetVertex::GetStartVertex(sgr.count()-1);	// Get start vertex
	if(!start){return;}

					// Variables
	const int vertex_number = sgr.count()-1;
	const unsigned MAX_INT = RIB_INF_WEIGHT;

	QBitArray is_closed(vertex_number+1);
	DijkstraResult res(vertex_number+1, DijkstraPath(MAX_INT));
	priority_queue< DistanceToVertex, vector< DistanceToVertex > > opened;

	int current_vertex = start;
	res[current_vertex] = 0;
	AG_CHANGE_VER_PARAM((*gr), current_vertex, color, Qt::blue)

	for (int i = 1; i <= vertex_number; ++i){
		if(i != start)
			{opened.push(DistanceToVertex(MAX_INT, i));}
	}
	opened.push(DistanceToVertex(0, start));

	int num_closed = 0;
	while(num_closed < vertex_number){
		sleep(Stime);

		do{
			AG_CHANGE_VER_PARAM((*gr), current_vertex, color, Qt::gray)
			current_vertex = opened.top().vertex;
			opened.pop();
		}while(is_closed[current_vertex]);

		AG_CHANGE_VER_PARAM((*gr), current_vertex, color, Qt::blue)

		++num_closed;
		is_closed[current_vertex] = true;

		const QVector <VLGraphRib> &edge_list = sgr[current_vertex];
		const unsigned current_dist = res[current_vertex].distance;
		for (int i=0; i<edge_list.count(); ++i){
			if(!is_closed[edge_list[i].to]){
				unsigned dist_through_current = current_dist + edge_list[i].weight;
				AG_CHANGE_VER_PARAM((*gr), edge_list[i].to, color, Qt::red)

				if(res[edge_list[i].to].distance > dist_through_current){
					AG_CHANGE_RIB_PARAM((*gr), ABrib(current_vertex, edge_list[i].to),
										color, Qt::red)
					res[edge_list[i].to].distance = dist_through_current;
					res[edge_list[i].to].from = current_vertex;
					opened.push(DistanceToVertex(dist_through_current, edge_list[i].to));
				}
			}
		}
	}
	AG_CHANGE_VER_PARAM((*gr), current_vertex, color, Qt::gray)

	DijkstraDialog DD(gr, res);
	DD.exec();
}

#endif // DIJKSTRA
