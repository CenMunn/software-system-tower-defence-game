#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>
#include <QPoint>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QSize>
#include "config.h"
class game;

class actor
{
public:
    actor(){}
    actor(class game* g,QPixmap draw,int damage,int gold,QPoint cen=QPoint(0,0));

    State _state;
    QPoint _pos;
    QPoint _center;
    QPixmap _draw;
    int   _damage;
    int   _gold;
    qreal _rotate;
    game * _game;

signals:

public slots:
};

#endif // ACTOR_H
