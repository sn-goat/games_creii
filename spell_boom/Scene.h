//
// Created by Sergile Nyouvop on 2024-07-07.
//

#ifndef SPELL_BOOM_SCENE_H
#define SPELL_BOOM_SCENE_H

#include <QtGui>
#include <QGraphicsScene>
#include "BallItem.h"

class Scene : public QGraphicsScene
{
public:
    explicit Scene(QGraphicsScene* parent = nullptr);


protected:
    void keyPressEvent(QKeyEvent * event);
};




#endif //SPELL_BOOM_SCENE_H
