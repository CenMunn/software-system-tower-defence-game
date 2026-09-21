#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <QPoint>
#include <QPainter>
#include "config.h"

class waypoint
{
public:
    waypoint(QPoint p);
    void setNextPoint(waypoint *next);
    void draw(QPainter *painter) const;

    QPoint		_waypoint;
    waypoint *	_nextpoint;

};

#endif // WAYPOINT_H
