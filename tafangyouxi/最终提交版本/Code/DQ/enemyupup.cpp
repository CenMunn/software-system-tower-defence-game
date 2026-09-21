#include "enemyupup.h"
#include "enemy.h"
#include "game.h"

enemyUpUp::enemyUpUp(game *game,waypoint *start, QPixmap draw, int damage, int gold)
    :basicenemy (game,start, draw,damage,gold)
{
    _maxHp=20;
    _speed=1.0;
    _count=0;
    _maxHp=20;
}

enemyUpUp::~enemyUpUp()
{
    _attacktower.clear();
    _waypoint = nullptr;
    _game = nullptr;
}

void enemyUpUp::check()
{
    if (_state!=Active)
        return;
    _count++;
    if(_count==200)
    {
       basicenemy *e =new enemyUpUp(_game,_waypoint);
       e->_state=Active;
       _game->addenemy(e);
       _count=0;
    }
}

void enemyUpUp::begin()
{
    _state=Active;
}


