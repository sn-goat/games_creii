#include "endui.h"

EndUI::EndUI(QWidget* parent) :
    QWidget(parent),
    ui_(parent),
    text_(new QTextEdit(parent))
{

    setPushButton();
    setConnections();
    setAllHidden(true);

}

void EndUI::setPushButton(){
    restartPushButton_ = new QPushButton("RESTART", ui_);
    restartPushButton_->setCheckable(true);
    restartPushButton_->setGeometry(ui_->width()*0.50 - 200, ui_->height() * 0.50 - 65, 400, 130);
    restartPushButtonFont_.setWeight(QFont::Bold);
    restartPushButton_->setFont(restartPushButtonFont_);

    quitPushButton_ = new QPushButton("QUIT", ui_);
    quitPushButton_->setCheckable(true);
    quitPushButton_->setGeometry(ui_->width()*0.50 - 200, ui_->height() * 0.50 - 65 + 130, 400, 130);
}

void EndUI::setText(const QString& str){
    static QString score = "Score: ";

    text_->setText(score + str);
    text_->setReadOnly(true);
    text_->setGeometry(ui_->width() * 0.50 - 40,ui_->height()* 0.30,  80, 50);


}

void EndUI::setAllHidden(bool boolean){
    restartPushButton_->setHidden(boolean);
    quitPushButton_->setHidden(boolean);
    text_->setHidden(boolean);
}

void EndUI::setConnections(){
    connect(restartPushButton_, SIGNAL (clicked(bool)), this, SLOT (slotRestartPushButtonClicked(bool)));
    connect(quitPushButton_, SIGNAL (clicked(bool)), this, SLOT (quitPushButtonClicked(bool)));
}

void EndUI::slotRestartPushButtonClicked(bool checked){
    if(checked){
        setAllHidden(true);
        restartPushButton_->setChecked(false);
        emit restartGame();
    }
}

void EndUI::quitPushButtonClicked(bool checked){
    if(checked){
        setAllHidden(true);
        emit quitGame();
    }
}
