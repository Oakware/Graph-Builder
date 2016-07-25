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

#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

///			<Includes>
#include "AbstractGraph/abstractgraph.h"
#include "reset_graph.h"

#include "bfs.h"
#include "dfs.h"
#include "dijkstra.h"
#include "minost_prim.h"
#include "minost_kruskal.h"
///			</Includes>

///			<AlgoList>
#define GR_ALGO_LIST \
	X(BFS) X(DFS) X(Dijkstra) X(MinOstP) X(MinOstK)
///			</AlgoList>

///			<Template>
enum GraphAlgorithms{
#define X(A) A##GA,
	GR_ALGO_LIST
#undef X
};

inline void RunGraphAlgorithm(int algo, AbstractGraph *gr, const int &Stime){
	ResetGraph(gr);
	switch(algo){
	#define X(A) case A##GA: RunGrAlgo##A(gr, Stime); break;
		GR_ALGO_LIST
	#undef X
	}
}
///			</Template>

#endif // GRAPH_ALGORITHMS_H
