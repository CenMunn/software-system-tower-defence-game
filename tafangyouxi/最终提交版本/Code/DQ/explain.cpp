#include "explain.h"
#include <QPainter>

explain::explain(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(BeginScene_width,950);
}

void explain::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap Scene1;
    Scene1.load(explain_Path);
    painter.drawPixmap(0,0,BeginScene_width,950,Scene1);
}
