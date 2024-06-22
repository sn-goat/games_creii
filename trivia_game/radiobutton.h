#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include <QRadioButton>
#include <QString>
#include <QWidget>

class RadioButton : public QRadioButton
{
    Q_OBJECT
public:
    explicit RadioButton(const QString& letter, QWidget *parent = nullptr);
    static int getRadioButtonCounter();
    const QString& getLetter();

private:
    QString letter_;

    static int radioButtonCounter_;
};

#endif // RADIOBUTTON_H
