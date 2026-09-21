#include "game.h"

game::game(QWidget *parent) : QMainWindow(parent)
{
    setWindowIcon(QIcon(MyIcon_Path));
    setWindowTitle(Game_title);
    setFixedSize(BeginScene_width,BeginScene_height);
    init();
}

void game::init()
{
    myGold=800;
    myHp=500;
    mywave=0;
    mystate=Active;
    loadEnemyWay();
    QPoint empty[11]={QPoint(550,50),QPoint(850,50),QPoint(700,300),QPoint(400,300),QPoint(1000,300),
                      QPoint(180,500),QPoint(1200,500),QPoint(900,770),QPoint(500,770),QPoint(450,520),
                      QPoint(950,520)};

    for(int i=0;i<11;i++)
    {
        myemptytower.push_back(empty[i]);
        if(i%3!=0){
            basictower * t=new tower(this,empty[i]);
            mytower.push_back(t);
        }
        if(i%3==0){
            basictower * t=new towerUp(this,empty[i]);
            mytower.push_back(t);
        }
    }
    pausebutton = new mybutton(200,200,Pause_Path,Con_Path);
    pausebutton ->setParent(this);
    pausebutton ->move(1200,5);
}

void game::playgame(QTimer * timer)
{
    mytimer = new QTimer(timer);
    connect(mytimer, SIGNAL(timeout()), this, SLOT(basicupdate()));
    mytimer->start(30);
    QTimer::singleShot(300, this, SLOT(start()));
    pausebutton->myload();
    connect(pausebutton ,&mybutton::clicked,[=](){
           if(mytimer->isActive())
           {
               mytimer->stop();
               pausebutton->now=pausebutton->lastImgPath;
               pausebutton->myload();
           }
           else {
               mytimer->start();
               pausebutton->now=pausebutton->initImgPath;
               pausebutton->myload();
           }
 });
}

void game::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap Scene1;
    Scene1.load(Scene1_Path);
    painter.drawPixmap(0,0,BeginScene_width,BeginScene_height,Scene1);
    QPixmap LeftHP;
    LeftHP.load(LeftZTL_Path);
    painter.drawPixmap(30,30,200,110,LeftHP);

    if (mystate==Dead)
    {
        QPixmap theDead;
        theDead.load(Lost_Path);
        painter.drawPixmap(400,200,theDead);
        mytimer->stop();
        return;
    }
    if (mystate==Win)
    {
        QPixmap theWin;
        theWin.load(Win_Path);
        painter.drawPixmap(400,200,theWin);
        mytimer->stop();
        return;
    }

    for(int i=0;i<myemptytower.size();i++){
        painter.drawPixmap(myemptytower[i].x(),myemptytower[i].y(),EmptyTower_width,EmptyTower_width,QPixmap(EmptyTower_Path));
    }
    for(int l=0;l<mytower.size();l++){
        mytower[l]->draw(&painter);
    }
  //  for(int j=0;j<myway.size();j++){
  //      myway[j]->draw(&painter);
  //  }
    for(int k=0;k<myenemy.size();k++){
         myenemy[k]->draw(&painter);
    }
    for(int k=0;k<mybullet.size();k++){
        mybullet[k]->draw(&painter);
    }

    QFont font1("华文楷体",10,QFont::Bold,false);
    font1.setLetterSpacing(QFont::AbsoluteSpacing,5);
    painter.setFont(font1);
    painter.setPen(Qt::white);
    painter.drawText(QRect(50, 50, 200, 100), QString("WAVE : %1").arg(mywave + 1));
    painter.drawText(QRect(50, 75, 200, 100), QString("HP : %1").arg(myHp));
    painter.drawText(QRect(50, 100, 200, 100), QString("GOLD : %1").arg(myGold));
}

void game::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    if (event->button() == Qt::LeftButton)
    {
      for(int i=0;i<myemptytower.size();i++){
          if ((myGold>100)&& CC(myemptytower[i],0,pos,60) ){
              myGold -= mytower[i]->_gold;
              if(mytower[i]->_state==Dead){
                  mytower[i]->_state=Active;
              }
              else{
                  mytower[i]->_draw=mytower[i]->_drawUp;
                  mytower[i]->_damage+=50;
                  mytower[i]->_gold +=50;
              }
            update();
            return;
          }}
    }
    if (event->button() == Qt::RightButton)
    {
        for(int i=0;i<myemptytower.size();i++){
            if (CC(myemptytower[i],0,pos,60) && mytower[i]->_state!=Dead)
            {
                myGold+=mytower[i]->_gold;
                mytower[i]->_state=Dead;
                mytower[i]->_draw=QPixmap(BasicTower_Path);
                mytower[i]->_damage=10;
                mytower[i]->_gold=70;
                update();
                return;
             }
          }
    }
}

void game::addbullet(bullet *b)
{
    mybullet.push_back(b);
}

void game::addenemy(basicenemy *e)
{
    myenemy.push_back(e);
   // qDebug()<<myenemy.size()<<endl;
}

void game::removebullet(bullet *b)
{
    mybullet.removeOne(b);
    delete b;
}

void game::removedEnemy(basicenemy *e)
{
    myGold=myGold+e->_gold;
    myenemy.removeOne(e);
  //  delete e;
    if (myenemy.empty())
    {
        mywave=mywave+1;
        if (!loadEnemy())
        {
            mystate = Win;
        }
    }
}

void game::pauseEnemy(basicenemy *e)
{
    int i=-1;
    i=myenemy.indexOf(e);
    qDebug()<<i<<Qt::endl;
    myenemy[i]->_state=Pause;
}

void game::pausetower(int x)
{
    mytower[x]->_state=Pause;
}

void game::activeTower(int x)
{
    mytower[x]->_state=Active;
}

void game::getHpDamage(int damage)
{
    myHp = myHp -damage;
    if (myHp <= 0){
        if (mystate==Active){
            mystate = Dead;
        }       
    }
}

void game::gainGold(int gain)
{
    myGold=myGold+gain;
    update();
}

void game::loadEnemyWay()
{
    waypoint *way1=new waypoint(QPoint(740,900));
    myway.push_back(way1);
    waypoint *way2=new waypoint(QPoint(0,670));
    myway.push_back(way2);
    waypoint *way3=new waypoint(QPoint(1400,670));
    myway.push_back(way3);
    waypoint *way4=new waypoint(QPoint(700,670));
    myway.push_back(way4);
    waypoint *way5=new waypoint(QPoint(700,450));
    myway.push_back(way5);
    waypoint *way6=new waypoint(QPoint(300,450));
    myway.push_back(way6);
    waypoint *way7=new waypoint(QPoint(1150,450));
    myway.push_back(way7);
    waypoint *way8=new waypoint(QPoint(300,218));
    myway.push_back(way8);
    waypoint *way9=new waypoint(QPoint(1150,218));
    myway.push_back(way9);
    waypoint *way10=new waypoint(QPoint(730,218));
    myway.push_back(way10);
    waypoint *way11=new waypoint(QPoint(730,0));
    myway.push_back(way11);
    waypoint *way12=new waypoint(QPoint(210,330));
    myway.push_back(way12);
    waypoint *way13=new waypoint(QPoint(1220,330));
    myway.push_back(way13);
    waypoint *way14=new waypoint(QPoint(760,670));
    myway.push_back(way14);
    waypoint *way15=new waypoint(QPoint(740,450));
    myway.push_back(way15);

    myway[0]->setNextPoint(myway[13]);
    myway[1]->setNextPoint(myway[3]);
    myway[2]->setNextPoint(myway[13]);
    myway[3]->setNextPoint(myway[4]);
    myway[4]->setNextPoint(myway[6]);
    myway[5]->setNextPoint(myway[11]);
    myway[6]->setNextPoint(myway[12]);
    myway[7]->setNextPoint(myway[9]);
    myway[8]->setNextPoint(myway[9]);
    myway[9]->setNextPoint(myway[10]);
    myway[11]->setNextPoint(myway[7]);
    myway[12]->setNextPoint(myway[8]);
    myway[13]->setNextPoint(myway[14]);
    myway[14]->setNextPoint(myway[5]);
}

bool game::loadEnemy()
{
    if (mywave >= 6)
    {
        return false;
    }
    waypoint *start = myway[mywave%3];
    int enemyStartInterval[] = { 100,100, 500, 600, 1000,1000, 3000, 6000 };
    if(mywave==0)
    {
        for (int i = 0; i < 6; ++i)	{
            basicenemy *e = new enemy(this,start);
            myenemy.push_back(e);
            QTimer::singleShot(enemyStartInterval[i], e, SLOT(begin()));
        }
    }
    else if(mywave==1)
    {
        for (int i = 0; i < 4; ++i)	{
            basicenemy *e = new enemy(this,start);
            myenemy.push_back(e);
            QTimer::singleShot(enemyStartInterval[i], e, SLOT(begin()));
        }
        for (int i = 4; i < 6; ++i)	{
            basicenemy *e = new enemyUp(this,start);
            myenemy.push_back(e);
            QTimer::singleShot(enemyStartInterval[i], e, SLOT(begin()));
        }
    }
    else if(mywave==3||mywave==2)
    {
        for (int i = 0; i < 3; ++i)	{
            basicenemy *e = new enemy(this,start);
            myenemy.push_back(e);
            QTimer::singleShot(enemyStartInterval[i], e, SLOT(begin()));
        }
        for (int i = 3; i < 5; ++i)	{
            basicenemy *e = new enemyUp(this,start);
            myenemy.push_back(e);
            QTimer::singleShot(enemyStartInterval[i], e, SLOT(begin()));
        }
        for (int i = 5; i < 6; ++i)	{
            basicenemy *e = new enemyUpUp(this,start);
            myenemy.push_back(e);
            QTimer::singleShot(enemyStartInterval[i], e, SLOT(begin()));
        }
    }
    else if(mywave>3&&mywave<6)
    {
        for (int i = 0; i < 4; ++i)	{
            basicenemy *e = new enemy(this,start);
            myenemy.push_back(e);
            QTimer::singleShot(enemyStartInterval[i], e, SLOT(begin()));
        }
        for (int i = 4; i < 6; ++i)	{
            basicenemy *e = new enemyUp(this,start);
            myenemy.push_back(e);
            QTimer::singleShot(enemyStartInterval[i], e, SLOT(begin()));
        }
        for (int i = 6; i < 8; ++i)	{
            basicenemy *e = new enemyUpUp(this,start);
            myenemy.push_back(e);
            QTimer::singleShot(enemyStartInterval[i], e, SLOT(begin()));
        }
    }
    return true;
}

void game::start()
{
    loadEnemy();
}

void game::basicupdate()
{
    for(int i=0;i<myenemy.size();i++)
    {
        myenemy[i]->move();
        myenemy[i]->check();
    }
    for(int j=0;j<mytower.size();j++)
    {
        mytower[j]->check();
    }
    update();
}

