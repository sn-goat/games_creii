#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QList>
#include <QThread>
#include <QFont>

#include "question.h"

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};



class GameLogic : public QWidget
{
    Q_OBJECT
public:
    explicit GameLogic(QWidget* parent = 0);

    void setQuestions();
    void setButtons();
    void setRadioButtons();
    void setConnections();

    void setAllHidden(bool boolean);
    void setPushButtonHidden(bool boolean);

    void restart();

    const QString& getScore();

    const QList<bool> getIsGoodAnswers();

signals:
    void endOfGame();


private slots:
    void slotNextPushButtonClicked(bool checked);
    void slotPreviousPushButtonClicked(bool checked);
    void slotRadioButtonsClicked(bool checked);


private:

    QList<Question*> questions_;

    QList<Question*>::iterator itQuestion;

    QList<bool> isGoodAnswers_;

    QWidget* ui_;

    QList<RadioButton*> radioButtons_;
    QPushButton* nextPushButton_;
    QPushButton* previousPushButton_;

    QFont nextPushButtonFont_;

    bool previousClicked_;

    int counterRB_;

    int goodAnswerCounter_;


};

#endif // GAMELOGIC_H
