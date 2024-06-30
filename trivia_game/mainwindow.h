#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include "radiobutton.h"
#include "answer.h"
#include "question.h"
#include "gamelogic.h"
#include "startui.h"
#include "endui.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setConnections();

private slots:
    void slotStartGame();
    void slotEndGame();
    void slotRestartGame();

private:
    Ui::MainWindow *ui;


    QPixmap image;
    QIcon icon;

    StartUi* startUi;
    EndUI* endUI;

    GameLogic* gameLogic;


};
#endif // MAINWINDOW_H
