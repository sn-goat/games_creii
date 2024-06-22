#ifndef ANSWER_H
#define ANSWER_H

#include <QTextEdit>
#include <QString>
#include <QWidget>

#include  "radiobutton.h"

class Answer : public QTextEdit
{
    Q_OBJECT
public:
    explicit Answer(const QString& text, QWidget* parent = nullptr);
    const QString& getText();

    void setRadioButton();
    void setAllHidden(bool boolean);

    static int getAnswerCounter();

private:
    QString text_;

    RadioButton* radioButton_;

    QWidget* ui_;

    static int answerCounter_;

};

#endif // ANSWER_H
