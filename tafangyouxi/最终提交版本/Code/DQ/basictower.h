#ifndef BASICTOWER_H
#define BASICTOWER_H

#include <QObject>
#include "actor.h"
#include "bullet.h"

class game;
class basictower : public QObject,public actor
{
    Q_OBJECT
public:
    explicit basictower(QObject *parent = nullptr);
    basictower(game* g,QPoint cen,QPixmap draw=QPixmap(BasicTower_Path),int damage=10,int gold=70);
    ~basictower();
    void draw(QPainter *painter) const;
    virtual void check()=0;
    virtual void Killed()=0;
    void getPause();
    void getActive();

    int	_range;
    int	_bullinterval;
    int _recorder;
    QTimer * _timer;
    basicenemy * _target;
    QPixmap _drawUp;

public slots:
    virtual void shoot()=0;
};

#endif // BASICTOWER_H
