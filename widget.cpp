#include "widget.h"
#include "ui_widget.h"
#include "dial-button.h"
#include "lcd-digits.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{

    m_layout = new QGridLayout(this);
    m_button = new DialButton(Qt::AlignCenter, 0, 0);
    m_lcd = new InputLcd;
    m_layout->addWidget(m_lcd);

    ((QGridLayout*)m_layout)->addWidget(m_button, 1, 0, Qt::AlignCenter);
}

Widget::~Widget()
{
}

const QLayout* Widget::getLayout()
{
    return m_layout;
}
