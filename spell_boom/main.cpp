
#include <QGraphicsView>
#include <QApplication>

#include "Scene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Scene scene;

    QGraphicsView view;
    view.setScene(&scene);
    view.setRenderHint(QPainter::Antialiasing);

    view.show();

    return a.exec();
}
