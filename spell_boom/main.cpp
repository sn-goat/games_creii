
#include <QGraphicsView>
#include <QApplication>


#include "CannonItem.h"
#include "Scene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CannonItem* cannon = new CannonItem();
    cannon->setPos(40 + 260, 600 - 30);
    cannon->setFlags(QGraphicsItem::ItemIsSelectable);


    Scene scene;
    scene.setSceneRect(0, 0, 600, 600);
    scene.addItem(cannon);

    QGraphicsView view;
    view.setScene(&scene);
    view.setRenderHint(QPainter::Antialiasing);

    view.show();

    return a.exec();
}
