#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLayout>


namespace Ui {
class Widget;
}

class DialButton;
class InputLcd;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


public slots:
    void onButtonClick(int id);

    const QLayout*    getLayout();
private:
    DialButton*     m_buttons[9];

    InputLcd*       m_lcd;

    QLayout*        m_layout;
};

#endif // WIDGET_H
