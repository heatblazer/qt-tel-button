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

    m_buttons[0] = new DialButton(Qt::AlignCenter, abc1[0], 0,  this);
    m_buttons[1] = new DialButton(Qt::AlignCenter, abc1[1], 1,  this);
    m_buttons[2] = new DialButton(Qt::AlignCenter, abc1[2], 2,  this);
    m_buttons[3] = new DialButton(Qt::AlignCenter, abc1[3], 3,  this);
    m_buttons[4] = new DialButton(Qt::AlignCenter, abc1[4], 4,  this);
    m_buttons[5] = new DialButton(Qt::AlignCenter, abc1[5], 5,  this);
    m_buttons[6] = new DialButton(Qt::AlignCenter, abc1[6], 6,  this);
    m_buttons[7] = new DialButton(Qt::AlignCenter, abc1[7], 7,  this);
    m_buttons[8] = new DialButton(Qt::AlignCenter, abc1[8], 8,  this);

    m_lcd = new InputLcd;

    ((QGridLayout*)m_layout)->addWidget(m_buttons[0], 0, 1, Qt::AlignTop | Qt::AlignLeft);
    ((QGridLayout*)m_layout)->addWidget(m_buttons[1], 0, 1, Qt::AlignTop | Qt::AlignCenter);
    ((QGridLayout*)m_layout)->addWidget(m_buttons[2], 0, 1, Qt::AlignTop | Qt::AlignRight);

    ((QGridLayout*)m_layout)->addWidget(m_buttons[3], 0, 1, Qt::AlignCenter | Qt::AlignLeft);
    ((QGridLayout*)m_layout)->addWidget(m_buttons[4], 0, 1, Qt::AlignCenter | Qt::AlignCenter);
    ((QGridLayout*)m_layout)->addWidget(m_buttons[5], 0, 1, Qt::AlignCenter | Qt::AlignRight);

    ((QGridLayout*)m_layout)->addWidget(m_buttons[6], 0, 1, Qt::AlignBottom | Qt::AlignLeft);
    ((QGridLayout*)m_layout)->addWidget(m_buttons[7], 0, 1, Qt::AlignBottom | Qt::AlignCenter);
    ((QGridLayout*)m_layout)->addWidget(m_buttons[8], 0, 1, Qt::AlignBottom | Qt::AlignRight);

    ((QGridLayout*)m_layout)->addWidget(m_lcd, 1,1, Qt::AlignAbsolute);

    connect(m_buttons[0], SIGNAL(signalParent(int)), this, SLOT(onButtonClick(const DialButton*)));
    connect(m_buttons[1], SIGNAL(signalParent(int)), this, SLOT(onButtonClick(const DialButton*)));
    connect(m_buttons[2], SIGNAL(signalParent(int)), this, SLOT(onButtonClick(const DialButton*)));
    connect(m_buttons[3], SIGNAL(signalParent(int)), this, SLOT(onButtonClick(const DialButton*)));
    connect(m_buttons[4], SIGNAL(signalParent(int)), this, SLOT(onButtonClick(const DialButton*)));
    connect(m_buttons[5], SIGNAL(signalParent(int)), this, SLOT(onButtonClick(const DialButton*)));
    connect(m_buttons[6], SIGNAL(signalParent(int)), this, SLOT(onButtonClick(const DialButton*)));
    connect(m_buttons[7], SIGNAL(signalParent(int)), this, SLOT(onButtonClick(const DialButton*)));
    connect(m_buttons[8], SIGNAL(signalParent(int)), this, SLOT(onButtonClick(const DialButton*)));




}

Widget::~Widget()
{
}

const QLayout* Widget::getLayout()
{
    return m_layout;
}


void Widget::onButtonClick(DialButton* button)
{
   m_lcd->setText(QString(button->getCurrentSymbol()));
}
