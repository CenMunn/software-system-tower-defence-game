#include "actor.h"
#include "game.h"

actor::actor(game *g,QPixmap draw,int damage,int gold,QPoint cen)
{
    _state=Dead;
    _rotate=180.0;
    _game=g;
    _draw=draw;
    _damage=damage;
    _gold=gold;
    _center=cen;
}
