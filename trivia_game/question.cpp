#include "question.h"

Question::Question(const QString& question, const QString& path, QString trueAnswer, QWidget* parent) :
    QTextEdit(question, parent),
    question_(question),
    trueAnswer_(trueAnswer),
    ui_(parent)
{
    setImage(path);

    setReadOnly(true);
    setGeometry(parent->width() * 0.50 - 300,parent->height()* 0.55,  600, 20);
}


void Question::setImage(const QString& path){
    image_ = new QPixmap(path);

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
