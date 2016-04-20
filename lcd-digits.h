#ifndef LCDDIGITS_H
#define LCDDIGITS_H
#include <QLCDNumber>
#include <QTextEdit>
class Widget;

class InputLcd : public QTextEdit
{
    Q_OBJECT

public:

    explicit InputLcd(QWidget* parent = 0);

public slots:
//    void updateLcd(void);

private:
    Widget* m_widget;
};

#endif // LCDDIGITS_H
