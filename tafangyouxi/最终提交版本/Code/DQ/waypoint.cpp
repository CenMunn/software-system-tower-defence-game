#include "waypoint.h"
#include <QColor>

waypoint::waypoint(QPoint p): _waypoint(p), _nextpoint(nullptr){}

void waypoint::setNextPoint(waypoint *next)
{
    _nextpoint=next;
}

void waypoint::draw(QPainter *painter) const
{
    painter->setPen(QColor(0,255,0));
    painter->drawEllipse(_waypoint, 6, 6);

    if (_nextpoint)
        painter->drawLine(_waypoint, _nextpoint->_waypoint);
}
