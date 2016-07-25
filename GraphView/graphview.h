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

#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#define M_PI 3.14159265358979323846
#include "../project_global.h"
#include "../AbstractGraph/abstractgraph.h"
#include "graphview_header.h"

///			<Class>
class GraphView: public QWidget{
	Q_OBJECT
public:
	explicit GraphView(QWidget *parent = 0);
	~GraphView();

///				<Enums>
private:			// Current state
	enum CState{Normal, VertexMoving, RibAdd, RibRemove};
///				</Enums>

///				<MainData>
private:
	bool isEditable;				// Edit enable

	CState CurrentState;			// GraphEngine status
	QTimer MoveTimer;				// Timer for vertex moving
	int CurX, CurY;					// Cursor coordinates

	TvertexInfo StdVertex;			// Standard vertex
	TribInfo StdRib;				// Standard rib

#define GV_MAIN_DATA_INIT \
	isEditable = true;\
	CurrentState = Normal;
///				</MainData>

///				<GraphViewControls>
public:
	void SetEditable(bool ie);		// Set edit enable

									// Set standard vertex/rib
	void SetStdVertex(const TvertexInfo &vi);
	void SetStdRib(const TribInfo &ri);

	int GetSelectedVertex();			// Get selected
	ABrib GetSelectedRib();
///				</GraphViewControls>

///				<Graph>
private:
	AbstractGraph *Graph;			// Graph
	int VSelected;					// Selected vertex
	ABrib RSelected;				// Selected rib

public:
	void SetGraph(AbstractGraph *gr);	// Set graph
	AbstractGraph* GetGraph();			// Get graph

private slots:
	void GraphVertexUpdate(int ver);	// Updates
	void GraphVertexRemove(int ver);

	void GraphRibUpdate(ABrib r);
	void GraphRibRemove(ABrib r);

	void GraphDestroyed();				// Graph destroyed

#define GV_GRAPH_INIT \
	Graph = NULL;\
	VSelected = 0;
///				</Graph>

///				<HelperFunctions>
private:
	bool BorderCross(int x, int y, int r);	// Border cross by vertex

	void SetRVSelected(int px, int py);		// Set R/V selected
	void SetVertexSelected(int v);			// Set selected vertex
	void SetRibSelected(const ABrib &r);	// Set selected rib

private slots:
	void ResetMinimumSize();				// Reset minimum size
	void StopEditing();						// Stop editing graph
///				</HelperFunctions>

///				<PaintEvent>
private:
	void paintEvent(QPaintEvent*);
	void drawVertex(QPainter &painter, int ver);
	void drawRib(QPainter &painter, int ver, int rib);
	void drawArrow(QPainter &painter, const QLine &line,
				   int aLen = GV_DEF_ARROW_LEN,
				   double alpha = GV_DEF_ARROW_ALPHA);
///				</PaintEvent>

///				<EditEvents>
private:
	void mousePressEvent(QMouseEvent *ev);			// Press
	void mouseReleaseEvent(QMouseEvent *ev);		// Release

	void mouseDoubleClickEvent(QMouseEvent *ev);	// Double click
	void keyPressEvent(QKeyEvent *ev);				// Key

private:
	void mouseMoveEvent(QMouseEvent *ev);			// Move
private slots:
	void MoveStart();	// Move vertex
	void MoveEnd();

private: int RibFromVer;

///					<ContextMenu>
private:
	void contextMenuEvent(QContextMenuEvent *ev);
private slots:
	void CMAddVertex();			// Add vertex
	void CMRemoveVertex();		// Remove vertex

	void CMAddRibBegin();		// Add rib
	void CMAddRibEnd();

	void CMRemoveRibBegin();	// Remove rib
	void CMRemoveRibEnd();
	void CMRemoveRib();
///					</ContextMenu>
///				</EditEvents>

///				<Signals>
signals:
	void VertexSelected(int=0);
	void RibSelected(ABrib=ABrib());
///				</Signals>

};
///			</Class>

#endif // GRAPHVIEW_H
