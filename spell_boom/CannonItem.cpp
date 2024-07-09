//
// Created by Sergile Nyouvop on 2024-07-07.
//

#include "CannonItem.h"


CannonItem::CannonItem(QGraphicsItem* parent): QGraphicsItem(parent) {
    barrel << QPointF(-20, 0) << QPointF(20, 0) << QPointF(20, -100) << QPointF(-20, -100);
    base << QPointF(-40, 0) << QPointF(40, 0) << QPointF(40, 20) << QPointF(-40, 20);
    leftWheel << QPointF(-40, -10) << QPointF(40, -10) << QPointF(40, 0) << QPointF(-40, 0);
    rightWheel << QPointF(-40, 20) << QPointF(40, 20) << QPointF(40, 30) << QPointF(-40, 30);
}

QRectF CannonItem::boundingRect() const {
    return QRectF(-40, -100, 80, 130);
}

void CannonItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    QPen pen(Qt::black);
    QBrush brush(Qt::gray);

    painter->setPen(pen);
    painter->setBrush(brush);

    painter->drawPolygon(barrel);

    painter->drawPolygon(base);

    painter->setBrush(Qt::black);
    painter->drawPolygon(leftWheel);
    painter->drawPolygon(rightWheel);
}