#ifndef LCDDIGITS_H
#define LCDDIGITS_H
#include <QLCDNumber>

class InputLcd : public QLCDNumber
{
    Q_OBJECT

public:

    explicit InputLcd(QWidget* parent = 0);

public slots:
//    void updateLcd(void);

};

#endif // LCDDIGITS_H
