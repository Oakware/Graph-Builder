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

#ifndef GRAPVIEW_HEADER_H
#define GRAPVIEW_HEADER_H

///			<Includes>
#include <QWidget>
#include <QScrollArea>
#include <QLayout>

#include <QPainter>
#include <QTimer>

#include <QMenu>
#include <QAction>

#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>

#include <QDataStream>
#include "math.h"
///			</Includes>

///			<Defines>
#define GV_DEF_TIMER_INTERVAL 400
#define GV_DEF_ARROW_ALPHA M_PI/8
#define GV_DEF_ARROW_LEN 20
///			</Defines>

#endif // GRAPVIEW_HEADER_H
