#include "enemyup.h"
#include "game.h"

enemyUp::enemyUp(game *game,waypoint *start, QPixmap draw, int damage, int gold)
    :basicenemy (game,start, draw,damage,gold)
{
    _maxHp=60;
    _speed=1.0;
    _count=0;
    _num=-1;
}

enemyUp::~enemyUp()
{
    _attacktower.clear();
    _waypoint = nullptr;
    _game = nullptr;
}

void enemyUp::check()
{
       if (_state!=Active)
          return;
       _count++;
       if(_count>=50&&_count<100)
       {
           if(_num==-1){
              QVector<basictower *> myList = _game->mytower;
               for(int i=myList.size()-1;i>=0;i--)
               {
                   if(myList[i]->_state==Active)
                   {
                       _num=i;
                       _game->pausetower(_num);
                       break;
                  }
               }
           }
       }
       else if(_count==100){
           if(_num!=-1){
               _game->activeTower(_num);
               _num=-1;
           }
           _count=0;
       }
}

void enemyUp::begin()
{
    _state=Active;
}

