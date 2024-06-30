#ifndef ENDUI_H
#define ENDUI_H

#include <QWidget>
#include <QTextEdit>
#include <QString>
#include <QPushButton>


class EndUI : public QWidget
{
    Q_OBJECT
public:
    explicit EndUI(QWidget* parent = 0);

    void setPushButton();
    void setConnections();
    void setText(const QString& str);
    void setAllHidden(bool boolean);



signals:
    void quitGame();
    void restartGame();

private slots:
    void slotRestartPushButtonClicked(bool checked);
    void quitPushButtonClicked(bool checked);

private:
    QWidget* ui_;

    QString score_;

    QPushButton* restartPushButton_;
    QFont restartPushButtonFont_;

    QPushButton* quitPushButton_;

    QTextEdit* text_;


};

#endif // ENDUI_H
