#ifndef GAME_H
#define GAME_H

#include "mybutton.h"
#include "tower.h"
#include "waypoint.h"
#include "bullet.h"
#include "towerup.h"
#include "enemyup.h"
#include "enemyupup.h"
#include "basicenemy.h"
#include <QTimer>
#include <ctime>
#include <QMainWindow>
#include <QVector>
#include <QList>
using std::vector;
using std::list;

namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT
public:
    explicit game(QWidget *parent = nullptr);    
    void init();
    void playgame(QTimer * timer);
   // void updategame();

    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *event);

    void addbullet(bullet *b);
    void addenemy(basicenemy *e);
    void removebullet(bullet *b);
    void removedEnemy(basicenemy *e);
    void pausetower(int x);
    void activeTower(int x);
    void pauseEnemy(basicenemy *e);
    void getHpDamage(int damage);
    void gainGold(int gain);
    void loadEnemyWay();
    bool loadEnemy();

    QTimer *mytimer;
    mybutton * pausebutton;

    QVector<QPoint> myemptytower;
    QVector<basictower *> mytower;
    QList<waypoint *> myway;
    QVector<basicenemy *> myenemy;
    QVector<bullet *> mybullet;

    int	myHp;
    int	myGold;
    int mywave;
    State mystate;

signals:

public slots:
    void start();
    void basicupdate();
};

#endif // GAME_H

