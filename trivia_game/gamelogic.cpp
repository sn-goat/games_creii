#include "gamelogic.h"
#include <QDebug>
#include <QLocale>

GameLogic::GameLogic(QWidget* parent) : QWidget(parent), ui_(parent){
    setQuestions();
    setButtons();
    setConnections();

    itQuestion = questions_.begin();

    setAllHidden(true);


}
void GameLogic::setRadioButtons(){
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
    questions_.append(new Question ("Quel est ce pays?","/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/Flag_of_Cameroon.svg.png", "C", ui_));
    questions_[0]->answers.append(new Answer(
        "A) Allemagne", ui_));
    questions_[0]->answers.append(new Answer(
        "B) Congo", ui_));
    questions_[0]->answers.append(new Answer(
        "C) Cameroune", ui_));
        questions_[0]->answers.append(new Answer(
                "D) Ghana", ui_));
    questions_[0]->answers.append(new Answer(
        "E) Kenya", ui_));
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

    questions_.append(new Question ("Dans quel cas l'algorithme de recherche binaire est-il le plus efficace?","/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/download.png", "B", ui_));
    questions_[2]->answers.append(new Answer(
        "A) Lorsque la liste est non triée.", ui_));
    questions_[2]->answers.append(new Answer(
        "B) Lorsque la liste est triée en ordre croissant ou décroissant.", ui_));
    questions_[2]->answers.append(new Answer(
        "C) Lorsque la liste contient des éléments en double.", ui_));
    questions_[2]->answers.append(new Answer(
        "D) Lorsque la liste est vide.", ui_));
    questions_[2]->answers.append(new Answer(
        "E) Toutes ces réponses.", ui_));
    questions_[2]->setAllHidden(true);

    questions_.append(new Question ("Quel est cette province?", "/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/Flag_of_Quebec.svg", "D", ui_));
    questions_[3]->answers.append(new Answer(
        "A) Alberta", ui_));
    questions_[3]->answers.append(new Answer(
        "B) Manitoba", ui_));
    questions_[3]->answers.append(new Answer(
        "C) Ontario", ui_));
    questions_[3]->answers.append(new Answer(
        "D) Québec", ui_));
    questions_[3]->answers.append(new Answer(
        "E) saskatchewan", ui_));
    questions_[3]->setAllHidden(true);

    questions_.append(new Question ("De quoi sont fait les champions?","/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/hi-res-160623023_crop_north.jpg", "E", ui_));
    questions_[4]->answers.append(new Answer(
        "A) D'un désir", ui_));
    questions_[4]->answers.append(new Answer(
        "B) D'une vision", ui_));
    questions_[4]->answers.append(new Answer(
        "C) D'un rêve", ui_));
    questions_[4]->answers.append(new Answer(
        "D) D'une passion", ui_));
    questions_[4]->answers.append(new Answer(
        "E) Toutes ces réponses", ui_));
    questions_[4]->setAllHidden(true);


    questions_.append(new Question ("Quel est cette équipe?","/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/image.jpg", "D", ui_));
    questions_[5]->answers.append(new Answer(
        "A) Toronto Argonauts", ui_));
    questions_[5]->answers.append(new Answer(
        "B) Edmonton Elks", ui_));
    questions_[5]->answers.append(new Answer(
        "C) Ottawa Rouge et Noir", ui_));
    questions_[5]->answers.append(new Answer(
        "D) Montréal Alouette", ui_));
    questions_[5]->answers.append(new Answer(
        "E) Calgary Stampeders", ui_));
    questions_[5]->setAllHidden(true);

    questions_.append(new Question ("Quel est le rôle principal du CPU dans un ordinateur?","/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/pexels-andrey-matveev-5766819-1024x683.jpg", "B", ui_));
    questions_[6]->answers.append(new Answer(
        "A) Stocker les données et les programmes.", ui_));
    questions_[6]->answers.append(new Answer(
        "B) Exécuter les instructions des programmes.", ui_));
    questions_[6]->answers.append(new Answer(
        "C) Gérer les périphériques d'entrée et de sortie.", ui_));
    questions_[6]->answers.append(new Answer(
        "D) Maintenir l'alimentation électrique de l'ordinateur.", ui_));
    questions_[6]->answers.append(new Answer(
        "E) Contrôler la connectivité réseau.", ui_));
    questions_[6]->setAllHidden(true);

    questions_.append(new Question ("Quel est l'ordre correct des planètes dans le système solaire en partant du Soleil?","/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/Solar_System_true_color.jpg", "C", ui_));
    questions_[7]->answers.append(new Answer(
        "A) Vénus, Mars, Terre, Mercure, Jupiter, Saturne, Uranus, Neptune.", ui_));
    questions_[7]->answers.append(new Answer(
        "B) Mercure, Jupiter, Vénus, Terre, Mars, Uranus, Saturne, Neptune.", ui_));
    questions_[7]->answers.append(new Answer(
        "C) Mercure, Vénus, Terre, Mars, Jupiter, Saturne, Uranus, Neptune.", ui_));
    questions_[7]->answers.append(new Answer(
        "D) Jupiter, Saturne, Uranus, Neptune, Mercure, Vénus, Terre, Mars.", ui_));
    questions_[7]->answers.append(new Answer(
        "E) Mars, Vénus, Mercure, Terre, Jupiter, Saturne, Uranus, Neptune.", ui_));
    questions_[7]->setAllHidden(true);

    questions_.append(new Question ("Dans quel cas l'algorithme de recherche en largeur (BFS) est-il le plus efficace?","/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/bfs.jpeg", "C", ui_));
    questions_[8]->answers.append(new Answer(
        "A) Pour trouver le chemin le plus long dans un graphe non pondéré.", ui_));
    questions_[8]->answers.append(new Answer(
        "B) Pour explorer les chemins dans un graphe pondéré avec des cycles.", ui_));
    questions_[8]->answers.append(new Answer(
        "C) Pour trouver le plus court chemin dans un graphe non pondéré.", ui_));
    questions_[8]->answers.append(new Answer(
        "D) Pour trier les éléments d'un graphe acyclique.", ui_));
    questions_[8]->answers.append(new Answer(
        "E) Pour rechercher un élément spécifique dans une liste triée.", ui_));
    questions_[8]->setAllHidden(true);

    questions_.append(new Question ("Dans quel cas l'algorithme de recherche en profondeur (DFS) est-il le plus efficace?","/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/download.jpeg", "B", ui_));
    questions_[9]->answers.append(new Answer(
        "A) Pour trouver le plus court chemin dans un graphe non pondéré.", ui_));
    questions_[9]->answers.append(new Answer(
        "B) Pour détecter des cycles dans un graphe.", ui_));
    questions_[9]->answers.append(new Answer(
        "C) Pour rechercher un élément spécifique dans une liste triée.", ui_));
    questions_[9]->answers.append(new Answer(
        "D) Pour trier les éléments d'un graphe acyclique.", ui_));
    questions_[9]->answers.append(new Answer(
        "E) Pour explorer tous les voisins immédiats d'un sommet dans un graphe.", ui_));
    questions_[9]->setAllHidden(true);

}

void GameLogic::setPushButtonHidden(bool boolean){
    nextPushButton_->setHidden(boolean);
    previousPushButton_->setHidden(boolean);
}


void GameLogic::setAllHidden(bool boolean){
    (*itQuestion)->setAllHidden(boolean);
    setPushButtonHidden(boolean);
}


const QString& GameLogic::getScore(){
    static QString str;

    return str.setNum((double(goodAnswerCounter_)/double(questions_.size())) * 100.00);

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
                    }
                }
                (*itQuestion)->setAllHidden(true);
                ++itQuestion;
                if (itQuestion == questions_.end()){
                    emit endOfGame();
                } else {
                    (*itQuestion)->setAllHidden(false);
                }
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
                ++counterRB_;
                nextPushButtonFont_.setWeight(QFont::Bold);
                nextPushButton_->setFont(nextPushButtonFont_);
                break;
            }
        }
        if (counterRB_ > 0){
            previousClicked_ =  true;
            (*itQuestion)->setAllHidden(true);
            if (itQuestion != questions_.begin()){
                --itQuestion;
            }
            (*itQuestion)->setAllHidden(false);
        }
    }
    counterRB_ = 0;
    Sleeper::msleep(50);
    previousPushButton_->setChecked(false);
}

void GameLogic::restart(){
    itQuestion = questions_.begin();
    counterRB_ = 0;
    goodAnswerCounter_ = 0;
    setAllHidden(false);
}
