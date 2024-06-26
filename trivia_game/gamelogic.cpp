#include "gamelogic.h"

GameLogic::GameLogic(QWidget* parent) : QWidget(parent), ui_(parent){
    setQuestions();
    setButtons();
    setConnections();

    itQuestion = questions_.begin();


}

void GameLogic::setButtons(){
    for(auto&& answer : questions_[0]->answers){
        radioButtons_.append(answer->getRadioButton());
    }

    nextPushButton_ = new QPushButton("NEXT", ui_);
    nextPushButton_->setCheckable(true);
    nextPushButton_->setGeometry(ui_->width() - ui_->width()*0.20, ui_->height() * 0.90, ui_->width()*0.14, 30);

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
}


void GameLogic::slotNextPushButtonClicked(bool checked){
    // QFont font;


    if (checked){
        // font.setWeight(QFont::Bold);
        // nextPushButton_->setFont(font);

        (*itQuestion)->setAllHidden(true);
        ++itQuestion;
        if (itQuestion == questions_.end()){
            itQuestion = questions_.begin();
        }
        (*itQuestion)->setAllHidden(false);
    }
    Sleeper::msleep(100);
    nextPushButton_->setChecked(false);
}

void GameLogic::slotPreviousPushButtonClicked(bool checked){
    if (checked){
        (*itQuestion)->setAllHidden(true);
        if (itQuestion == questions_.begin()){
            itQuestion = --(questions_.end());
        } else{
            --itQuestion;
        }
        (*itQuestion)->setAllHidden(false);
    }
    Sleeper::msleep(100);
    previousPushButton_->setChecked(false);
}
