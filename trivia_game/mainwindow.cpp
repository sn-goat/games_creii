#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(900, 700);

    gameLogic = new GameLogic(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}
