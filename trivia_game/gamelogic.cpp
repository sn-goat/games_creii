#include "gamelogic.h"

GameLogic::GameLogic(QWidget* parent) : QWidget(parent), ui_(parent){
    setQuestions();
    setButtons();


}

void GameLogic::setButtons(){
    for(auto&& answer : questions_[0]->answers){
        radioButtons_.append(answer->getRadioButton());
    }

    nextPushButton_ = new QPushButton("NEXT", ui_);
    nextPushButton_->setCheckable(true);
    nextPushButton_->setGeometry(ui_->width() - 150, ui_->height() * 0.90, 125, 30);

    nextPushButton_ = new QPushButton("PREVIOUS", ui_);
    nextPushButton_->setCheckable(true);
    nextPushButton_->setGeometry(ui_->width() - 275, ui_->height() * 0.90, 125, 30);
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
