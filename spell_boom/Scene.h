//
// Created by Sergile Nyouvop on 2024-07-07.
//

#ifndef SPELL_BOOM_SCENE_H
#define SPELL_BOOM_SCENE_H

#include <QtGui>
#include <QGraphicsScene>
#include "BallItem.h"
#include "CannonItem.h"
#include "AsteroidItem.h"

class Scene : public QGraphicsScene
{
public:
    explicit Scene(QGraphicsScene* parent = nullptr);
    void setCannon();

private:
    CannonItem* cannon;

protected:
    void keyPressEvent(QKeyEvent * event);
};




#endif //SPELL_BOOM_SCENE_H
