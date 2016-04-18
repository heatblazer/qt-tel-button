#include "widget.h"
#include <QApplication>
#include <QWidget>
#include <QGridLayout>

#include "dial-button.h"
#include "lcd-digits.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //glayout->addWidget(new InputLcd());
    //glayout->addWidget(new DialButton(Qt::AlignCenter, 0, 0 ), 1, 0, Qt::AlignCenter);

    w.setMinimumSize(520,240);
    w.setMaximumSize(520,240);

    w.show();

    return a.exec();
}
