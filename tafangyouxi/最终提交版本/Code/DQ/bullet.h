#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QPainter>
#include <QPropertyAnimation>
#include "enemy.h"
#include "config.h"

class game;

class bullet : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint _pos READ currentPos WRITE setCurrentPos)
public:
    bullet(){}
    bullet(QPoint pos,int damage, basicenemy *target,game *g,const QPixmap &draw = QPixmap( BasicBullet_Path));
    void draw(QPainter *painter) const;
    void move();
    void moveUp();
    void setCurrentPos(QPoint pos);
    QPoint currentPos() const;

    QPoint  _start;
    QPoint	_pos;
    QPoint	_end;
    QPixmap	_draw;
    basicenemy *	_target;
    game *	_game;
    int	_damage;
    qreal _speed;

signals:

private slots:
    void hit();
    void hitUp();
};

#endif // BULLET_H

