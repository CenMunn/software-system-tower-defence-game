#ifndef BASICENEMY_H
#define BASICENEMY_H

#include <QObject>
#include "waypoint.h"
#include "actor.h"

class basictower;
class game;
class basicenemy : public QObject,public actor
{
    Q_OBJECT
public:
    explicit basicenemy(QObject *parent = nullptr);
    basicenemy(game* game,waypoint *start,QPixmap draw=QPixmap(BasicEnemy_Path),int damage=10,int gold=70);
    ~basicenemy();

    void draw(QPainter *painter) const;
    void getDamage(int d);
    void getPause();
    void move();
    void pause();
    void getmove();
    void removetower(basictower *t);
    virtual void check()=0;

    int _maxHp;
    int	_Hp;
    double _speed;
    waypoint *	_waypoint;
    QVector<basictower *>	_attacktower;

signals:

public slots:
    virtual void begin()=0;
};

#endif // BASICENEMY_H
