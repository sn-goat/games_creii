#ifndef QUESTION_H
#define QUESTION_H

#include <QTextEdit>
#include <QString>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QList>

#include "answer.h"

class Question : public QTextEdit
{
    Q_OBJECT
public:
    explicit Question(const QString& question, const QString& ImagePath, QString trueAnswer, QWidget* parent = nullptr);

    void setImage(const QString& path);
    void setAllHidden(bool boolean);

    const QString& getTrueAnswer();

    QList<Answer*> answers;

private:
    QString question_;
    QString trueAnswer_;

    QPixmap* image_;
    QLabel* label_;

    QWidget* ui_;

};

#endif // QUESTION_H
