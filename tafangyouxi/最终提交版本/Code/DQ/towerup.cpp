#include "towerup.h"
#include "game.h"

towerUp::towerUp(game* g,QPoint cen,QPixmap draw,int damage,int gold)
               :basictower(g,cen,draw,damage,gold),count(0),interval(80)
{
    _drawUp=QPixmap(TowerUp1_Path);
}

towerUp::~towerUp()
{
    delete _timer;
    _timer = nullptr;
}

void towerUp::shoot()
{
    if(_state!=Active)
        return;
   // count++;
    if(count<=interval)
    {
      bullet *b = new bullet(_center,_damage, _target,_game);
      b->moveUp();
      _game->addbullet(b);
    }
    else
    {
        if(_target!=nullptr){
            _target->getmove();
            _target=nullptr;
        }
       count=0;
    }
}

void towerUp::check()
{
    count++;
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
                for(int i=myList.size()-1;i>=0;i--)
               {
                  if (CC(_pos,_range, myList[i]->_pos, 100))
                  {
                    _target = myList[i];
                    _timer->start(_bullinterval);
                    _target->removetower(this);
                    break;
                  }
               }
            }
}


