#include "question.h"

Question::Question(const QString& question, const QString& path, QString trueAnswer, QWidget* parent) :
    QTextEdit(question, parent),
    question_(question),
    trueAnswer_(trueAnswer),
    ui_(parent)
{
    setImage(path);

    setReadOnly(true);
    setGeometry(parent->width() * 0.50 - 300,parent->height()* 0.55,  parent->width()*0.66, parent->height()* 0.030);
}


void Question::setImage(const QString& path){
    image_ = new QPixmap(path);

    label_ = new QLabel(ui_);

    label_->setPixmap(image_->scaled(ui_->width()* 0.65, ui_->height() * 0.50));
    label_->setGeometry(ui_->width() * 0.50 -  (ui_->width()* 0.65)/2, ui_->height() * 0.025, ui_->width()* 0.65, ui_->height() * 0.50);

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
