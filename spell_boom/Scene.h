//
// Created by Sergile Nyouvop on 2024-07-07.
//

#ifndef SPELL_BOOM_SCENE_H
#define SPELL_BOOM_SCENE_H

#include <QtGui>
#include <QObject>
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include "BallItem.h"
#include "CannonItem.h"
#include "AsteroidItem.h"

class Scene : public QGraphicsScene
{
Q_OBJECT

public:
    explicit Scene(QGraphicsScene* parent = nullptr);
    void setCannon();

    void startSpawningAsteroids(int interval = 1600);

private slots:
    void spawnAsteroids();

private:
    QTimer *timer;
    CannonItem* cannon;

protected:
    void keyPressEvent(QKeyEvent * event);
};




#endif //SPELL_BOOM_SCENE_H
