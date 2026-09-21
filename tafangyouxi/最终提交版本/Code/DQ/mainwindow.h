#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include "explain.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~MainWindow();

    mybutton * changescenebutton;
    mybutton * exitbutton;
    mybutton * explainbutton;

    QTimer * mytimer;
    game* mygame;
    explain* myexplain;

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
