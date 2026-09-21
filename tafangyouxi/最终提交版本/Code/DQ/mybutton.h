#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>

class mybutton:public QPushButton
{
    Q_OBJECT
public:
    mybutton(int w,int h,QString initImg,QString lastImg="");
    void myload();

    QString initImgPath;
    QString lastImgPath;
    QString now;
    int height;
    int width;
    QPixmap mypix;

signals:

public slots:
};

#endif // MYBUTTON_H
