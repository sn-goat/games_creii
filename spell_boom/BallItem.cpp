//
// Created by Sergile Nyouvop on 2024-07-07.
//

#include "BallItem.h"

BallItem::BallItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
        : QGraphicsEllipseItem(x, y, width, height, parent), dx(0), dy(-10.0)
{
    setBrush(Qt::blue);
    timer = new QTimer(this);

    connect(timer, SIGNAL (timeout()) , this, SLOT  (move()));
}


void BallItem::startMoving(int interval)
{
    timer->start(interval);
}


void BallItem::move()
{
    if (!scene()) { return; }


    moveBy(dx, dy);

    if(!collidingItems().isEmpty()){
        for(auto elem : collidingItems()){
            if(auto asteroid = dynamic_cast<AsteroidItem*>(elem)){
                qDebug() << "dead :/";
                scene()->removeItem(asteroid);
            }
        }
    }
}