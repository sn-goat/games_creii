#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), image("/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/Question_Mark_Logo_2021_September.png")
{
    ui->setupUi(this);
    icon = QIcon(image);

    setFixedSize(900, 700);

    setWindowTitle("Trivia Game");


    startUi = new StartUi(this);
    gameLogic = new GameLogic(this);
    endUI = new EndUI(this);


    setConnections();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setConnections(){
    connect(gameLogic, SIGNAL (endOfGame()), this , SLOT (slotEndGame()));

    connect(endUI, SIGNAL (quitGame()), QApplication::instance() , SLOT (quit()));
    connect(endUI, SIGNAL (restartGame()), this , SLOT (slotRestartGame()));


    connect(startUi, SIGNAL (quitGame()), QApplication::instance(), SLOT (quit()));
    connect(startUi, SIGNAL (startGame()), this, SLOT (slotStartGame()));

}

void MainWindow::slotStartGame(){
    gameLogic->setAllHidden(false);
}

void MainWindow::slotEndGame(){
    gameLogic->setPushButtonHidden(true);

    endUI->setText(gameLogic->getScore());
    endUI->setAllHidden(false);

}

void MainWindow::slotRestartGame(){
    gameLogic->restart();
}



