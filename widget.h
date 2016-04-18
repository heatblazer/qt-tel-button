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


    const QLayout*    getLayout();
private:
    DialButton*     m_button1;
    DialButton*     m_button2;
    DialButton*     m_button3;
    DialButton*     m_button4;
    DialButton*     m_button5;
    DialButton*     m_button6;
    DialButton*     m_button7;
    DialButton*     m_button8;
    DialButton*     m_button9;

    InputLcd*       m_lcd;

    QLayout*        m_layout;
};

#endif // WIDGET_H
