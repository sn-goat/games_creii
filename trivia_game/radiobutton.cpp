#include "radiobutton.h"

int RadioButton::radioButtonCounter_ = 0;

RadioButton::RadioButton(const QString& letter, QWidget* parent) : QRadioButton(letter, parent), letter_(letter)  {
    setCheckable(true);
    ++radioButtonCounter_;

    setGeometry(100*(radioButtonCounter_%5 + 1) + 100, parent->height() * 0.85, 100, 20);
}

const QString& RadioButton::getLetter() {
    return letter_;
}

int RadioButton::getRadioButtonCounter(){
    return radioButtonCounter_;
}
