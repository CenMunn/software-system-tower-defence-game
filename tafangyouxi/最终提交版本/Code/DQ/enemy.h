#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include "mycoll.h"
#include <QPainter>
#include <QColor>
#include <QMatrix4x4>
#include <QVector2D>
#include <QtMath>
#include "basicenemy.h"

class basictower;

class enemy : public basicenemy
{
    Q_OBJECT
public:
    enemy(game* game,waypoint *start,QPixmap draw=QPixmap(BasicEnemy_Path),int damage=20,int gold=70);
    ~enemy();
    void check(){}

public slots:
    void begin();
};

#endif // ENEMY_H
