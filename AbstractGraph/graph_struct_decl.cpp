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

#include "graph_struct_decl.h"

Trib::Trib(int w, const QColor &col):
	To(NULL), Weight(w),
	Color(col), isHidden(false){}

Trib::Trib(const TribInfo &ri):
	To(NULL)
{
	SetProperties(ri);
}

void Trib::SetProperties(const TribInfo &ri){
	Weight = ri.weight;
	Color = ri.color;
	isHidden = ri.hidden;
}


Tvertex::Tvertex(int r, const QColor &col):
	x(0), y(0), Radius(r),
	Color(col), isHidden(false){}

Tvertex::Tvertex(const TvertexInfo &vi){
	SetProperties(vi);
}

void Tvertex::SetProperties(const TvertexInfo &vi){
	Radius = vi.radius;
	Color = vi.color;
	isHidden = vi.hidden;
}


TribInfo::TribInfo(int w, const QColor &col):
	from(0), to(0), weight(w),
	color(col), hidden(false){}

TribInfo::TribInfo(const Trib &rib, int From, int To):
	from(From), to(To)
{
	GetProperties(rib);
}

void TribInfo::GetProperties(const Trib &rib){
	weight = rib.Weight;
	color = rib.Color;
	hidden = rib.isHidden;
}


TvertexInfo::TvertexInfo(int r, const QColor &col):
	x(0), y(0), radius(r), color(col),
	number(0), degree(0), hidden(false){}

TvertexInfo::TvertexInfo(const Tvertex &ver, int n):
	number(n)
{
	GetProperties(ver);
}

void TvertexInfo::GetProperties(const Tvertex &ver){
	x = ver.x;
	y = ver.y;
	radius = ver.Radius;
	color = ver.Color;
	degree = ver.Ribs.count();
	hidden = ver.isHidden;
}
