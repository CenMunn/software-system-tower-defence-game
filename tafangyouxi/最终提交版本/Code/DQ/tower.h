#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include "basictower.h"
#include "bullet.h"

class game;
class tower :public basictower
{
    Q_OBJECT
public:
    tower(game* g,QPoint cen,QPixmap draw=QPixmap(BasicTower_Path),int damage=10,int gold=100);
    ~tower();
    void check();
    void Killed();

public slots:
    void shoot();
};

#endif // TOWER_H
