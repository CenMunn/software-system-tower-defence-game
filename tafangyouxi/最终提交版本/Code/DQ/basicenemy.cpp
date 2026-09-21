#include "basicenemy.h"
#include "game.h"

basicenemy::basicenemy(QObject *parent) : QObject(parent){}

basicenemy::basicenemy(game *game,waypoint *start, QPixmap draw, int damage, int gold)
    :actor(game,draw,damage,gold), _maxHp(40), _Hp(40), _speed(2.0)
{
    _pos=start->_waypoint;
    _waypoint=start->_nextpoint;
    _center=start->_waypoint;
}

basicenemy::~basicenemy()
{
    _attacktower.clear();
    _waypoint = nullptr;
    _game = nullptr;
}

void basicenemy::draw(QPainter *painter) const
{
    if (_state==Dead)
        return;
    painter->save();
    QPoint healthBarPoint = _pos + QPoint(0, -10);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect BackRect(healthBarPoint, QSize(20, 2));
    painter->drawRect(BackRect);
    painter->setBrush(Qt::green);
    QRect BarRect(healthBarPoint, QSize(_Hp*2000/(_maxHp*100), 2));
    painter->drawRect(BarRect);
    painter->drawPixmap(_pos, _draw);
    painter->restore();
}

void basicenemy::getDamage(int d)
{
     _Hp=_Hp-d;
     if (_Hp <= 0)
     {
         _state=Dead;
         _game->gainGold(_gold);
         if (_attacktower.empty())
             return;
         foreach (basictower *attacker, _attacktower)
             attacker->Killed();
         _game->removedEnemy(this);
     }
}

void basicenemy::getPause()
{
    if(_state==Active)
        _state=Pause;
}

void basicenemy::move()
{
    if (_state!=Active)
        return;
    if (CC(_pos, 4, _waypoint->_waypoint, 4))
    {
        if (_waypoint->_nextpoint)
        {
            _pos = _waypoint->_waypoint;
            _waypoint = _waypoint->_nextpoint;
        }
        else
        {
            _game->getHpDamage(_damage);
            _game->removedEnemy(this);
            return;
        }
    }
    QPoint t = _waypoint->_waypoint;
    QVector2D normalized(t- _pos);
    normalized.normalize();
    _pos = _pos + normalized.toPoint() * _speed;
    _rotate = qRadiansToDegrees(qAtan2(normalized.y(), normalized.x())) + 180;
}

void basicenemy::pause()
{
    _state=Pause;
}

void basicenemy::getmove()
{
    _state=Active;
}

void basicenemy::removetower(basictower *t)
{
    _attacktower.push_back(t);
}
