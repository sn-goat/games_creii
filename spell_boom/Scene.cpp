//
// Created by Sergile Nyouvop on 2024-07-07.
//

#include "Scene.h"


Scene::Scene(QGraphicsScene* parent) : QGraphicsScene(parent) {
    setSceneRect(0, 0, 600 , 600);
    setBackgroundBrush(Qt::black);
    setCannon();

    timer = new QTimer(this);

    connect(timer, SIGNAL (timeout()) , this, SLOT  (spawnAsteroids()));

}

void Scene::startSpawningAsteroids(int interval)
{
    timer->start(interval);
}

void Scene::spawnAsteroids(){
    AsteroidItem* asteroid = new AsteroidItem(QRandomGenerator::global()->bounded(50, 550),-100);
    addItem(asteroid);
    asteroid->startMoving();
}


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
            BallItem* ball = new BallItem(pt.x() - 20, pt.y() - 130, 40, 40);
            ball->setFlags(QGraphicsItem::ItemIsSelectable);
            addItem(ball);
            ball->startMoving();


        } else {
            QGraphicsScene::keyPressEvent(event);
        }
    }
}

void Scene::setCannon() {
    cannon = new CannonItem();
    cannon->setPos(width()/2, height() - 30);
    cannon->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    addItem(cannon);


}