#include "lcd-digits.h"
#include "widget.h"

InputLcd::InputLcd(QWidget *parent)
    : QTextEdit(parent)
{
    setMinimumHeight(30);
    setMaximumHeight(30);
    setMinimumWidth(100);
    setMaximumWidth(100);
    m_widget = (Widget*) parent;
}
