#include <QtGui>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsSceneMouseEvent>



class CannonItem : public QGraphicsItem
{
public:
    explicit CannonItem(QGraphicsItem* parent = nullptr) : QGraphicsItem(parent) {
        barrel << QPointF(-20, 0) << QPointF(20, 0) << QPointF(20, -100) << QPointF(-20, -100);
        base << QPointF(-40, 0) << QPointF(40, 0) << QPointF(40, 20) << QPointF(-40, 20);
        leftWheel << QPointF(-40, -10) << QPointF(40, -10) << QPointF(40, 0) << QPointF(-40, 0);
        rightWheel << QPointF(-40, 20) << QPointF(40, 20) << QPointF(40, 30) << QPointF(-40, 30);
    }

    QRectF boundingRect() const override {
        return QRectF(-40, -100, 80, 130);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
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


private:
    QPolygonF barrel;
    QPolygonF base;
    QPolygonF leftWheel;
    QPolygonF rightWheel;
};

class Scene : public QGraphicsScene
{
public:
    explicit Scene(QGraphicsScene* parent = nullptr) : QGraphicsScene(parent) {}

protected:
    void keyPressEvent(QKeyEvent * event){
        if(event->key() == Qt::Key_Right) {
            if(!selectedItems().empty()){
                qDebug() << "The Square is Cannon right!";
                if(selectedItems()[0]->x() >= width() - 40){
                    selectedItems()[0]->setX(width() - 40);
                } else {
                    selectedItems()[0]->setX(selectedItems()[0]->x() + 20);
                }
            }
        } else if(event->key() == Qt::Key_Left) {
            if(!selectedItems().empty()){
                qDebug() << "The Square is Cannon left!";
                if(selectedItems()[0]->x() <= 40){
                    selectedItems()[0]->setX(40);
                } else {
                    selectedItems()[0]->setX(selectedItems()[0]->x() - 20);
                }
            }
        }
        else {
            QGraphicsScene::keyPressEvent(event);
        }
    }
};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CannonItem* cannon = new CannonItem();
    cannon->setPos(40 + 260, 600 - 30);
    cannon->setFlags(QGraphicsItem::ItemIsSelectable|
                      QGraphicsItem::ItemIsMovable);


    Scene scene;
    scene.setSceneRect(0, 0, 600, 600);
    scene.addItem(cannon);

    QGraphicsView view;
    view.setScene(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.show();

    view.show();

    return a.exec();
}
