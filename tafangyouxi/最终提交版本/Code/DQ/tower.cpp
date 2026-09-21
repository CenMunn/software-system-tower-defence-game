#include "tower.h"

#include <QColor>
#include <QVector2D>
#include <QtMath>
#include "game.h"

tower::tower(game* g,QPoint cen,QPixmap draw,int damage,int gold)
    :basictower(g,cen,draw,damage,gold)
{
    _drawUp=QPixmap(TowerOne_Path);
}

tower::~tower()
{
    delete _timer;
    _timer = nullptr;
}

void tower::shoot()
{
    if(_state!=Active)
        return;
    bullet *b = new bullet(_center,_damage, _target,_game);
    b->move();
    _game->addbullet(b);
}

void tower::check()
{
    if (_target) {
            QVector2D normalized(_target->_pos - _pos);
            normalized.normalize();
            _rotate = qRadiansToDegrees(qAtan2(normalized.y(), normalized.x())) + 90;
            if (CC(_target->_pos,30,_pos,_range)==false){
                _target->removetower(this);
                if (_target)
                    _target = nullptr;
                _timer->stop();
            }
        }
      else{
            QVector<basicenemy *> myList = _game->myenemy;
            foreach (basicenemy *enemy, myList)
            {
                if (CC(_pos,_range, enemy->_pos, 100))
                {
                    _target = enemy;
                    _timer->start(_bullinterval);
                    _target->removetower(this);
                    break;
                }
            }
        }
}

void tower::Killed()
{
    if (_target)
        _target = nullptr;

    _timer->stop();
    _rotate = 0.0;
}

