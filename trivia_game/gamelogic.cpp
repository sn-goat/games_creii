#include "gamelogic.h"
#include <QDebug>

GameLogic::GameLogic(QWidget* parent) : QWidget(parent), ui_(parent){
    setQuestions();
    setButtons();
    setConnections();

    itQuestion = questions_.begin();


}
void GameLogic::setRadioButtons(){
    // qDebug() << "SETTING BUTTONS";
    // qDebug() << (*itQuestion)->getTrueAnswer();
    if(radioButtons_.isEmpty()){
        for(auto&& answer : (*itQuestion)->answers){
            radioButtons_.append(answer->getRadioButton());
        }
    } else {
        radioButtons_.clear();
        for(auto&& answer : (*itQuestion)->answers){
            radioButtons_.append(answer->getRadioButton());
        }
    }
}

void GameLogic::setButtons(){

    nextPushButton_ = new QPushButton("NEXT", ui_);
    nextPushButton_->setCheckable(true);
    nextPushButton_->setGeometry(ui_->width() - ui_->width()*0.20, ui_->height() * 0.90, ui_->width()*0.14, 30);
    nextPushButtonFont_.setWeight(QFont::Normal);
    nextPushButton_->setFont(nextPushButtonFont_);

    previousPushButton_ = new QPushButton("PREVIOUS", ui_);
    previousPushButton_->setCheckable(true);
    previousPushButton_->setGeometry(ui_->width() - ((ui_->width()*0.14) + ui_->width()*0.20) , ui_->height() * 0.90, ui_->width()*0.14, 30);
}

void GameLogic::setQuestions(){
    questions_.append(new Question ("Qui est le boos?","/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/Flag_of_Cameroon.svg.png", "C", ui_));
    questions_[0]->answers.append(new Answer(
        "A) PAPA?", ui_));
    questions_[0]->answers.append(new Answer(
        "B) MAMAN?", ui_));
    questions_[0]->answers.append(new Answer(
        "C) SERGILE!", ui_));
        questions_[0]->answers.append(new Answer(
                "D) TALA", ui_));
    questions_[0]->answers.append(new Answer(
        "E) JEMIMA", ui_));
    questions_[0]->setAllHidden(false);


    questions_.append(new Question ("D'où vient cette image?", "/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/output-onlinepngtools.png", "A", ui_));
    questions_[1]->answers.append(new Answer(
        "A) Montréal", ui_));
    questions_[1]->answers.append(new Answer(
        "B) France", ui_));
    questions_[1]->answers.append(new Answer(
        "C) Laval", ui_));
    questions_[1]->answers.append(new Answer(
        "D) Québec", ui_));
    questions_[1]->answers.append(new Answer(
        "E) Sainte-Catherine", ui_));
    questions_[1]->setAllHidden(true);

}

void GameLogic::setConnections(){
    connect(nextPushButton_, SIGNAL (clicked(bool)), this, SLOT (slotNextPushButtonClicked(bool)));
    connect(previousPushButton_, SIGNAL (clicked(bool)), this, SLOT (slotPreviousPushButtonClicked(bool)));
    for(auto&& question: questions_){
        for(auto&& answer: question->answers){
            connect(answer->getRadioButton(), SIGNAL (clicked(bool)), this, SLOT (slotRadioButtonsClicked(bool)));
        }
    }
}

void GameLogic::slotRadioButtonsClicked(bool checked){
    if(checked){
        nextPushButtonFont_.setWeight(QFont::Bold);
        nextPushButton_->setFont(nextPushButtonFont_);
    }

}


void GameLogic::slotNextPushButtonClicked(bool checked){
    setRadioButtons();

    if (checked){
        for(auto&& radioButton: radioButtons_){
            if(radioButton->isChecked()){
                if(radioButton->getLetter() == (*itQuestion)->getTrueAnswer()){
                    if(!previousClicked_){
                        ++goodAnswerCounter_;
                        qDebug() << goodAnswerCounter_;
                    }
                }
                (*itQuestion)->setAllHidden(true);
                ++itQuestion;
                if (itQuestion == questions_.end()){ // This will change soon...
                    itQuestion = questions_.begin();
                }
                (*itQuestion)->setAllHidden(false);
            }
        }

    }

    Sleeper::msleep(50);
    nextPushButton_->setChecked(false);
    previousClicked_ = false;
    nextPushButtonFont_.setWeight(QFont::Normal);
    nextPushButton_->setFont(nextPushButtonFont_);
}

void GameLogic::slotPreviousPushButtonClicked(bool checked){
    if (checked){
        for(auto&& radioButton: radioButtons_){
            if(radioButton->isChecked()){
                nextPushButtonFont_.setWeight(QFont::Bold);
                nextPushButton_->setFont(nextPushButtonFont_);
                break;
            }
        }
        previousClicked_ =  true;
        (*itQuestion)->setAllHidden(true);
        if (itQuestion == questions_.begin()){
            itQuestion = --(questions_.end());
        } else{
            --itQuestion;
        }
        (*itQuestion)->setAllHidden(false);
    }
    Sleeper::msleep(50);
    previousPushButton_->setChecked(false);
}
