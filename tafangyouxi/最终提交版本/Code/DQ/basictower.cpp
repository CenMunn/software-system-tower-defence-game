#include "basictower.h"
#include <QColor>
#include <QVector2D>
#include <QtMath>
#include "game.h"

basictower::basictower(QObject *parent) : QObject(parent){}

basictower::basictower(game* g,QPoint cen,QPixmap draw,int damage,int gold)
    :actor(g,draw,damage,gold,cen), _range(200),_target(nullptr)
{
    _recorder=0;
    _rotate=180.0;
    _bullinterval=1000;
    _pos=cen;
    _center=QPoint(_center.x()+35,_center.y()+35);
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(shoot()));
}

basictower::~basictower()
{
    delete _timer;
    _timer = nullptr;
}

void basictower::draw(QPainter *painter) const
{
    if(_state==Dead)
        return;
    if(_state==Active)
    {
        painter->save();
        painter->drawPixmap(_pos,_draw);
        painter->setPen(Qt::white);
        painter->drawEllipse(_center, _range, _range);
        painter->restore();
    }
    if(_state==Pause)
    {
        QPixmap draw=QPixmap(FroTower_Path);
        painter->save();
        painter->drawPixmap(_pos,_draw);
        painter->drawPixmap(_pos,draw);
        painter->setPen(Qt::white);
      //  painter->drawEllipse(_center, _range, _range);
        painter->restore();
    }
}

void basictower::getPause()
{
    _state=Pause;
}

void basictower::getActive()
{
    _state=Active;
}



