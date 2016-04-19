#include "widget.h"
#include "dial-button.h"
#include "lcd-digits.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{

    m_layout = new QGridLayout(this);
    //fixed dialpad
    QChar abc1[9][4] = {{'1', 'A', 'B', 'C' },
                        {'2', 'D', 'E', 'F'},
                        {'3', 'G', 'H', 'I'},
                        {'4', 'J', 'K', 'L'},
                        {'5', 'M', 'N', 'O'},
                        {'6', 'P', 'Q', 'R'},
                        {'7', 'S', 'T', 'U'},
                        {'8', 'U', 'V', 'W'},
                        {'9', 'X', 'Y', 'Z'}};

    m_button1 = new DialButton(Qt::AlignCenter, abc1[0], 0, 0, this);
    m_button2 = new DialButton(Qt::AlignCenter, abc1[1], 0, 0, this);
    m_button3 = new DialButton(Qt::AlignCenter, abc1[2], 0, 0, this);
    m_button4 = new DialButton(Qt::AlignCenter, abc1[3], 0, 0, this);
    m_button5 = new DialButton(Qt::AlignCenter, abc1[4], 0, 0, this);
    m_button6 = new DialButton(Qt::AlignCenter, abc1[5], 0, 0, this);
    m_button7 = new DialButton(Qt::AlignCenter, abc1[6], 0, 0, this);
    m_button8 = new DialButton(Qt::AlignCenter, abc1[7], 0, 0, this);
    m_button9 = new DialButton(Qt::AlignCenter, abc1[8], 0, 0, this);

    m_lcd = new InputLcd;
    m_layout->addWidget(m_lcd);

    ((QGridLayout*)m_layout)->addWidget(m_button1, 0, 1, Qt::AlignTop | Qt::AlignLeft);
    ((QGridLayout*)m_layout)->addWidget(m_button2, 0, 1, Qt::AlignTop | Qt::AlignCenter);
    ((QGridLayout*)m_layout)->addWidget(m_button3, 0, 1, Qt::AlignTop | Qt::AlignRight);

    ((QGridLayout*)m_layout)->addWidget(m_button4, 0, 1, Qt::AlignCenter | Qt::AlignLeft);
    ((QGridLayout*)m_layout)->addWidget(m_button5, 0, 1, Qt::AlignCenter | Qt::AlignCenter);
    ((QGridLayout*)m_layout)->addWidget(m_button6, 0, 1, Qt::AlignCenter | Qt::AlignRight);

    ((QGridLayout*)m_layout)->addWidget(m_button7, 0, 1, Qt::AlignBottom | Qt::AlignLeft);
    ((QGridLayout*)m_layout)->addWidget(m_button8, 0, 1, Qt::AlignBottom | Qt::AlignCenter);
    ((QGridLayout*)m_layout)->addWidget(m_button9, 0, 1, Qt::AlignBottom | Qt::AlignRight);

}

Widget::~Widget()
{
}

const QLayout* Widget::getLayout()
{
    return m_layout;
}
