//
// Created by Sergile Nyouvop on 2024-07-07.
//

#include "Scene.h"


Scene::Scene(QGraphicsScene* parent) : QGraphicsScene(parent) {}

void Scene::keyPressEvent(QKeyEvent * event){
    if(!selectedItems().empty()) {
        if (event->key() == Qt::Key_Right) {
            qDebug() << "The Cannon is moving right!";
            if (selectedItems()[0]->x() >= width() - 40) {
                selectedItems()[0]->setX(width() - 40);
            } else {

                selectedItems()[0]->moveBy(20, 0);
            }

        } else if (event->key() == Qt::Key_Left) {
            qDebug() << "The Cannon is moving left!";
            if (selectedItems()[0]->x() <= 40) {
                selectedItems()[0]->setX(40);
            } else {
                selectedItems()[0]->moveBy(-20, 0);
            }
        } else if (event->key() == Qt::Key_Space) {
            qDebug() << "The Cannon has fired!";
            QPointF pt = selectedItems()[0]->pos();
            BallItem *ball = new BallItem(pt.x() - 20, pt.y() - 130, 40, 40);
            ball->setFlags(QGraphicsItem::ItemIsSelectable);
            addItem(ball);
            ball->startMoving();

        } else {
            QGraphicsScene::keyPressEvent(event);
        }
    }
}