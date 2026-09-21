#ifndef EXPLAIN_H
#define EXPLAIN_H

#include <QMainWindow>
#include "config.h"

class explain : public QMainWindow
{
    Q_OBJECT
public:
    explicit explain(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // EXPLAIN_H
