#include "startui.h"

StartUi::StartUi(QWidget* parent) : QWidget(parent), ui_(parent) {
    setImage();
    setPushButton();
    setConnections();
}

void StartUi::setImage(){
    image_ = new QPixmap("/Users/sergilenyouvop/Desktop/SUMMER_WORK_24/games_creii/trivia_game/images/360_F_461021871_UOigFOGXVkfXZp31YS78F4mxdqoEPT6A.jpg");

    label_ = new QLabel(ui_);
    label_->setPixmap(image_->scaled(ui_->width()* 0.80, ui_->height() * 0.40));
    label_->setGeometry(ui_->width() * 0.50 -  (ui_->width()* 0.80)/2, ui_->height() * 0.025, ui_->width()* 0.80, ui_->height() * 0.40);

}

void StartUi::setPushButton(){
    startPushButton_ = new QPushButton("START", ui_);
    startPushButton_->setCheckable(true);
    startPushButton_->setGeometry(ui_->width()*0.50 - 150, ui_->height() * 0.50, 300, 100);
    startPushButtonFont_.setWeight(QFont::Bold);
    startPushButton_->setFont(startPushButtonFont_);

    quitPushButton_ = new QPushButton("QUIT", ui_);
    quitPushButton_->setCheckable(true);
    quitPushButton_->setGeometry(ui_->width()*0.50 - 150, ui_->height() * 0.50 + 100, 300, 100);


}

void StartUi::setAllHidden(bool boolean){
    label_->setHidden(boolean);
    startPushButton_->setHidden(boolean);
    quitPushButton_->setHidden(boolean);
}

void StartUi::setConnections(){
    connect(startPushButton_, SIGNAL (clicked(bool)), this, SLOT (slotStartPushButtonClicked(bool)));
    connect(quitPushButton_, SIGNAL (clicked(bool)), this, SLOT (quitPushButtonClicked(bool)));
}

void StartUi::slotStartPushButtonClicked(bool checked){
    if(checked){
        setAllHidden(true);
        emit startGame();
    }
}

void StartUi::quitPushButtonClicked(bool checked){
    if(checked){
        setAllHidden(true);
        emit quitGame();
    }
}


