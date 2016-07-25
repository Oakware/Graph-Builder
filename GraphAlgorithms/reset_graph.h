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

#ifndef RESET_GRAPH_H
#define RESET_GRAPH_H

#include "../AbstractGraph/abstractgraph.h"

inline void ResetGraph(AbstractGraph *gr, QColor Cver = Qt::green,
					   QColor Crib = Qt::black)
{
	GraphModel gm = gr->GetGraphModel();

	for(int i=1; i<=gr->VertexCount(); ++i){
		AG_CHANGE_VER_PARAM((*gr), i, color, Cver)
	}

	for(int i=0; i<gm.ribs.count(); ++i){
		AG_CHANGE_RIB_PARAM((*gr), ABrib(gm.ribs[i].from, gm.ribs[i].to), color, Crib)
	}
}

#endif // RESET_GRAPH_H
