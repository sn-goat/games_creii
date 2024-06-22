#include "question.h"

Question::Question(const QString& question, QString trueAnswer, QWidget* parent) :
    QTextEdit(question, parent),
    question_(question),
    trueAnswer_(trueAnswer),
    ui_(parent)
{
    setImage();

    setReadOnly(true);
    setGeometry(parent->width() * 0.50 - 300,parent->height()* 0.55,  600, 20);
}


void Question::setImage(){
    image_ = new QPixmap("/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/Flag_of_Cameroon.svg.png");

    label_ = new QLabel(ui_);

    label_->setPixmap(image_->scaled(600, 300));
    label_->setGeometry(ui_->width() * 0.50 -  300, ui_->height() * 0.025, 600, 300);

}

void Question::setAllHidden(bool boolean){
    if (boolean){
        setHidden(true);
        label_->setHidden(true);
        for(auto answer : answers){
            answer->setAllHidden(true);
        }
    } else {
        setHidden(false);
        label_->setHidden(false);
        for(auto answer : answers){
            answer->setAllHidden(false);
        }
    }
}

const QString& Question::getTrueAnswer(){
    return trueAnswer_;
}
