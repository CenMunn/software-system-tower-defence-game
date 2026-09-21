#include "mainwindow.h"
#include "config.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(BeginScene_width,BeginScene_height);
    setWindowIcon(QIcon(MyIcon_Path));
    setWindowTitle(Game_title);
    mytimer = new QTimer(this);

        changescenebutton = new mybutton(304,232,StartButton_Path);
        changescenebutton->setParent(this);
        changescenebutton->move(1000,0);
        changescenebutton->myload();
        mygame = new game;
        connect(changescenebutton,&mybutton::clicked,[=](){
                     this->hide();
                     mygame->show();
                     mygame->playgame(mytimer);
     });

        exitbutton = new mybutton(304,232,ExitButton_Path);
        exitbutton->setParent(this);
        exitbutton->move(1000,218);
        exitbutton->myload();
        connect(exitbutton,&mybutton::clicked,[=](){
                int ret = QMessageBox::question(this,"EXIT","是否退出游戏");
                switch(ret)
                {
                case QMessageBox::Yes:
                    exit(1);
                case QMessageBox::No:
                    break;
                default:
                    break;
                }
     });

        explainbutton = new mybutton(304,232,ClaimButton_Path);
        explainbutton->setParent(this);
        explainbutton->move(1000,400);
        explainbutton->myload();
        myexplain=new explain;
        connect(explainbutton,&mybutton::clicked,[=](){
                     myexplain->show();
     });

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap beginscene;
    beginscene.load(BeginScene_Path);
    painter.drawPixmap(0,0,this->width(),this->height(),beginscene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
