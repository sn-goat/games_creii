//
// Created by Sergile Nyouvop on 2024-07-27.
//

#include "AsteroidItem.h"

AsteroidItem::AsteroidItem(qreal x, qreal y, QGraphicsItem *parent)
        : QGraphicsItem(parent), dx(0), dy(3.5) {
    // Create an irregular asteroid shape

    setPos(x, y);
    timer = new QTimer(this);

    int num_points = 20;
    qreal radius = 40;
    for (int i = 0; i < num_points; ++i) {
        qreal angle = 2 * M_PI * i / num_points;
        qreal r = radius + QRandomGenerator::global()->bounded(qint64(-radius * 0.5), qint64(radius * 0.5));
        qreal x = r * qCos(angle);
        qreal y = r * qSin(angle);
        asteroid << QPointF(x, y);
    }

    connect(timer, SIGNAL (timeout()) , this, SLOT  (move()));
}


QRectF AsteroidItem::boundingRect() const{
    return QRectF(-55, -60, 105, 110);
}

void AsteroidItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPen pen(Qt::black);
    QBrush brush(Qt::darkRed);

    painter->setPen(pen);
    painter->setBrush(brush);

    painter->drawPolygon(asteroid);
}

void AsteroidItem::startMoving(int interval)
{
    timer->start(interval);
}

void AsteroidItem::move()
{
    if (!scene()) { return; }


    moveBy(dx, dy);
}