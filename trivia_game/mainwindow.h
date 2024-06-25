#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "radiobutton.h"
#include "answer.h"
#include "question.h"
#include "gamelogic.h"

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

private:
    Ui::MainWindow *ui;

    GameLogic* gameLogic;

    // Question* question;

    // Answer* answer1;
    // Answer* answer2;
    // Answer* answer3;
    // Answer* answer4;
    // Answer* answer5;


};
#endif // MAINWINDOW_H
