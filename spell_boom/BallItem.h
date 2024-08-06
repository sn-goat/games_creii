//
// Created by Sergile Nyouvop on 2024-07-07.
//

#ifndef SPELL_BOOM_BALLITEM_H
#define SPELL_BOOM_BALLITEM_H

#include <QtGui>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "AsteroidItem.h"
#include <QGraphicsEllipseItem>



class BallItem :  public QObject, public QGraphicsEllipseItem
{
Q_OBJECT

public:
    explicit BallItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    void startMoving(int interval = 16); // Starts the timer with the given interval (default 60 FPS)

private slots:
    void move();

private:
    QTimer *timer;
    qreal dx;
    qreal dy;

};


#endif //SPELL_BOOM_BALLITEM_H
