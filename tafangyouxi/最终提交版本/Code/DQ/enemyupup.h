#ifndef ENEMYUPUP_H
#define ENEMYUPUP_H

#include "basicenemy.h"
#include "basictower.h"
#include <QObject>

class basictower;
class enemy;

class enemyUpUp : public basicenemy
{
     Q_OBJECT
public:
    enemyUpUp(game* game,waypoint *start,QPixmap draw=QPixmap(EnemyUpUp_Path),int damage=10,int gold=50);
    ~enemyUpUp();
    void check();
    int _count;

public slots:
    void begin();
};

#endif // ENEMYUPUP_H
