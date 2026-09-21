#ifndef CONFIG_H
#define CONFIG_H

#define Game_title "myQD"
#define myPie 0.01745

#define BeginScene_width 1400
#define BeginScene_height 900
#define EmptyTower_width 70
#define BasicEnermy_width 80
#define BasicBullet_width 20

#define BeginScene_Path ":/res/a.jpg"
#define Scene1_Path ":/res/c.png"
#define MyIcon_Path ":/res/b.png"
#define StartButton_Path ":/res/1.png"
#define ContinueButton_Path ":/res/2.png"
#define ExitButton_Path ":/res/6.png"
#define ClaimButton_Path ":/res/3.png"
#define HavesoundButton_Path ":/res/5.png"
#define NosoundButton_Path ":/res/4.png"
#define ExitButton1_Path ":/res/7.png"
#define PauseButton_Path ":/res/8.png"
#define LeftZTL_Path ":/res/9.png"
#define Win_Path ":/res/14.png"
#define Lost_Path ":/res/10.png"
#define Pause_Path ":/res/12.png"
#define Con_Path ":/res/13.png"
#define explain_Path ":/res/AAA.jpg"

#define EmptyTower_Path ":/res/d.png"
#define BasicTower_Path ":/res/j.png"
#define FroTower_Path ":/res/m.png"
#define TowerOne_Path ":/res/i.png"
#define BasicEnemy_Path ":/res/e.png"
#define EnemyUp_Path ":/res/n.png"
#define EnemyUpUp_Path ":/res/l.png"
#define BasicBullet_Path ":/res/k.png"

#define TowerUp_Path ":/res/o.png"
#define TowerUp1_Path ":/res/p.png"
#include <QDebug>

enum State
{
    Active,
    Pause,
    Dead,
    Win
};


#endif // CONFIG_H
