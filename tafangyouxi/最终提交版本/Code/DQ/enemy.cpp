#include "enemy.h"
#include "game.h"

enemy::enemy(game *game,waypoint *start, QPixmap draw, int damage, int gold)
    :basicenemy (game,start, draw,damage,gold)
{}

enemy::~enemy()
{
    _attacktower.clear();
    _waypoint = nullptr;
    _game = nullptr;
}

void enemy::begin()
{
    _state=Active;
}
