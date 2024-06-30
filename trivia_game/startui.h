#ifndef STARTUI_H
#define STARTUI_H

#include <QString>
#include <QPushButton>
#include <QWidget>
#include <QPixmap>
#include <QFont>
#include <QLabel>
#include <QWidget>

class StartUi : public QWidget
{
    Q_OBJECT
public:
    explicit StartUi(QWidget* parent = 0);

    void setImage();
    void setPushButton();

    void setConnections();

    void setAllHidden(bool boolean);

signals:
    void quitGame();
    void startGame();

private slots:
    void slotStartPushButtonClicked(bool checked);
    void quitPushButtonClicked(bool checked);

private:
    QWidget* ui_;

    QPixmap* image_;
    QLabel* label_;

    QPushButton* startPushButton_;
    QFont startPushButtonFont_;

    QPushButton* quitPushButton_;
};

#endif // STARTUI_H
