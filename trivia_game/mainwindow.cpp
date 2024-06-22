#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    question = new Question ("Qui est le boos?", "C", this);

    question->answers.append(new Answer(
        "A) PAPA?", this));
    question->answers.append(new Answer(
        "B) MAMAN?", this));
    question->answers.append(new Answer(
        "C) SERGILE!", this));
    question->answers.append(new Answer(
        "D) TALA", this));
    question->answers.append(new Answer(
        "E) JEMIMA", this));

    question->setAllHidden(true);

    Question* q = new Question("salut", "E", this);

    q->answers.append(new Answer(
        "A) PAPA?", this));
    q->answers.append(new Answer(
        "B) MAMAN?", this));
    q->answers.append(new Answer(
        "C) SERGILE!", this));
    q->answers.append(new Answer(
        "D) TALA", this));
    q->answers.append(new Answer(
        "E) JEMIMA", this));

    q->setAllHidden(true);

    question->setAllHidden(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}
