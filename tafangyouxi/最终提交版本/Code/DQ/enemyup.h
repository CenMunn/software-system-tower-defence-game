#ifndef ENEMYUP_H
#define ENEMYUP_H
#include "basicenemy.h"
#include "basictower.h"
#include <QObject>
#include <QtGlobal>
#include <QTime>

class basictower;

class enemyUp :public basicenemy
{
    Q_OBJECT
public:
    enemyUp(game* game,waypoint *start,QPixmap draw=QPixmap(EnemyUp_Path),int damage=30,int gold=120);
    ~enemyUp();
    void check();

     int _count;
     int _num;

public slots:
    void begin();
};

#endif // ENEMYUP_H
