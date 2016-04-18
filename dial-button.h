#ifndef DIALBUTTON_H
#define DIALBUTTON_H
#include <QPushButton>
#include <QGridLayout>
#include <QTime>



class DialButton : public QPushButton
{
    Q_OBJECT
    Qt::Alignment m_align;
    QTime       m_timer;

    QChar       m_letters[4];
    quint32     m_lettersIndex;
    void        moveIndex(void);


    int m_interval;
    int m_step;
public slots:
    void clicked() ;
    void label();
public:
     explicit DialButton(Qt::Alignment align, int interval, int step, QWidget* parent=0);
};

#endif // DIALBUTTON_H
