#ifndef MYCOLL_H
#define MYCOLL_H

#include <QtMath>
#include <QPoint>

inline bool CC(QPoint p1, int r1, QPoint p2, int r2)
{
    const int xx = p1.x() - p2.x();
    const int yy = p1.y() - p2.y();
    const double distance = qSqrt(xx * xx + yy * yy);

    if (distance <= r1 + r2)
        return true;

    return false;
}

#endif // MYCOLL_H
