#include "answer.h"

int Answer::answerCounter_ = 0;

Answer::Answer(const QString &text, QWidget* parent) : QTextEdit(text, parent), text_(text), ui_(parent)  {

    setReadOnly(true);
    ++answerCounter_;

    setGeometry(parent->width() * 0.50 - 200, parent->height() * 0.55 + 30*(answerCounter_%5 + 1), 400, 20);
    setRadioButton();
}

void Answer::setRadioButton(){
    switch (RadioButton::getRadioButtonCounter() % 5) {
    case 0:
        radioButton_ = new RadioButton("A", ui_);
        break;
    case 1:
        radioButton_ = new RadioButton("B", ui_);
        break;
    case 2:
        radioButton_ = new RadioButton("C", ui_);
        break;
    case 3:
        radioButton_ = new RadioButton("D", ui_);
        break;
    case 4:
        radioButton_ = new RadioButton("E", ui_);
        break;
    default:
        radioButton_ = new RadioButton("~", ui_);
        break;
    }
}




const QString& Answer::getText(){
    return text_;
}

int Answer::getAnswerCounter(){
    return answerCounter_;
}

void Answer::setAllHidden(bool boolean){
    if (boolean) {
        setHidden(true);
        radioButton_->setHidden(true);
    } else {
        setHidden(false);
        radioButton_->setHidden(false);
    }
}
