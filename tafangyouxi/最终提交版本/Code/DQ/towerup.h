#ifndef TOWERUP_H
#define TOWERUP_H

#include <QObject>
#include "basictower.h"

class towerUp : public basictower
{
    Q_OBJECT
public:
    towerUp(game* g,QPoint cen,QPixmap draw=QPixmap(TowerUp_Path),int damage=0,int gold=120);
    ~towerUp();
    void check();
    void Killed(){}

    int count;
    int interval;

public slots:
    void shoot();
};

#endif // TOWERUP_H
