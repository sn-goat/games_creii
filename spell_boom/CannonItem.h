//
// Created by Sergile Nyouvop on 2024-07-07.
//

#ifndef SPELL_BOOM_CANNONITEM_H
#define SPELL_BOOM_CANNONITEM_H

#include <QtGui>
#include <QGraphicsItem>

class CannonItem : public QGraphicsItem
{
public:
    explicit CannonItem(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPolygonF barrel;
    QPolygonF base;
    QPolygonF leftWheel;
    QPolygonF rightWheel;
};


#endif //SPELL_BOOM_CANNONITEM_H
