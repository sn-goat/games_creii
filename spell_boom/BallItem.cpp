//
// Created by Sergile Nyouvop on 2024-07-07.
//

#include "BallItem.h"

BallItem::BallItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
        : QGraphicsEllipseItem(x, y, width, height, parent), dx(0), dy(-10.0)
{
    setBrush(Qt::blue);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &BallItem::move);
}

BallItem::~BallItem()
{
    delete timer;
}

void BallItem::startMoving(int interval)
{
    timer->start(interval);
}

void BallItem::move()
{
    if (!scene())
        return;
//
//    QRectF bounds = sceneBoundingRect();
//    QPointF pos = this->pos();

//    if (pos.x() + rect().width() >= bounds.right() || pos.x() <= bounds.left())
//        dx = -dx;
//    if (pos.y() + rect().height() >= bounds.bottom() || pos.y() <= bounds.top())
//        dy = -dy;
    moveBy(dx, dy);
}