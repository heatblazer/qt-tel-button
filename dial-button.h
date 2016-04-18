#ifndef DIALBUTTON_H
#define DIALBUTTON_H
#include <QPushButton>
#include <QGridLayout>
#include <QTime>

class Widget;

class DialButton : public QPushButton
{
    Q_OBJECT
private:
    Qt::Alignment m_align;
    QTime       m_timer;

    QChar       m_letters[4];
    quint32     m_lettersIndex;
    void        moveIndex(void);


    int m_interval;
    int m_step;
signals:
    void signalDisplay(QChar c);

public slots:
    void clicked() ;
    void label();
public:
     explicit DialButton(Qt::Alignment align, QChar buttons[4], int interval, int step, QWidget* parent=0);

private:
    QWidget* m_parentWidget;
};

#endif // DIALBUTTON_H
