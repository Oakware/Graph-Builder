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

#ifndef SLEEP_H
#define SLEEP_H

#include <QCoreApplication>
#include <QObject>
#include <QTimer>

class SLEEP_HELPER: public QObject{
	Q_OBJECT
public:
	SLEEP_HELPER(){
		connect(&SleepTimer, SIGNAL(timeout()),
				this, SLOT(SleepEnd()));
	}

private:
	QTimer SleepTimer;		// Sleep timer
	bool SleepFlag;			// Sleep flag
	friend void sleep(int);

private slots:
	void SleepEnd(){SleepFlag = false;}

};

static SLEEP_HELPER SL_HELPER;

inline void sleep(int t){
	SL_HELPER.SleepFlag = true;
	SL_HELPER.SleepTimer.setInterval(t);
	SL_HELPER.SleepTimer.start();
	while(SL_HELPER.SleepFlag){
		QCoreApplication::processEvents();
	}
}

#endif // SLEEP_H
