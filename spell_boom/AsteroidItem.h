//
// Created by Sergile Nyouvop on 2024-07-27.
//

#ifndef SPELL_BOOM_ASTEROIDITEM_H
#define SPELL_BOOM_ASTEROIDITEM_H

#include <QtGui>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QtMath>
#include <QObject>
#include <QTimer>

class AsteroidItem : public QObject, public QGraphicsItem
{
Q_OBJECT

public:
    AsteroidItem(qreal x, qreal y, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    void startMoving(int interval = 16);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private slots:
    void move();

private:
    QPolygonF asteroid;
    QTimer *timer;
    qreal dx;
    qreal dy;
};


#endif //SPELL_BOOM_ASTEROIDITEM_H
