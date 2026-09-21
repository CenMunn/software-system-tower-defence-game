#include "bullet.h"
#include "game.h"

bullet::bullet(QPoint pos, int damage, basicenemy *target,game *g,const QPixmap &draw)
    : _pos(pos),_end(target->_pos),_draw(draw), _target(target), _game(g),_damage(damage)
{
    _speed=0.0;
    _start=pos;
}

void bullet::draw(QPainter *painter) const
{
    painter->drawPixmap(_pos.x(),_pos.y(),10,10, _draw);
}

void bullet::move()
{
    static const int duration = 100;
    QPropertyAnimation *animation = new QPropertyAnimation(this, "_pos");
    animation->setDuration(duration);
    animation->setStartValue(_start);
    animation->setEndValue(_end);
    connect(animation, SIGNAL(finished()), this, SLOT(hit()));
    animation->start();
}

void bullet::moveUp()
{
    static const int duration = 100;
    QPropertyAnimation *animation = new QPropertyAnimation(this, "_pos");
    animation->setDuration(duration);
    animation->setStartValue(_start);
    animation->setEndValue(_end);
    connect(animation, SIGNAL(finished()), this, SLOT(hitUp()));
    animation->start();
}

void bullet::hit()
{
    if (_game->myenemy.indexOf(_target) != -1)
        _target->getDamage(_damage);
    _game->removebullet(this);
}

void bullet::hitUp()
{
    if (_game->myenemy.indexOf(_target) != -1)
        _target->pause();
    _game->removebullet(this);
}

void bullet::setCurrentPos(QPoint pos)
{
    _pos= pos;
}

QPoint bullet::currentPos() const
{
    return _pos;
}
