#include "mybutton.h"

mybutton::mybutton(int w,int h,QString initImg,QString lastImg)
{
    initImgPath=initImg;
    lastImgPath=lastImg;
    now=initImgPath;

    height=h;
    width=w;
    mypix=QPixmap(now);

}

void mybutton::myload()
{
    mypix=QPixmap(now);
    setFixedSize(width,height);
    setStyleSheet("QPushButton{border:0px;}");
    setIcon(mypix);
    setIconSize(QSize(width,height));
}


