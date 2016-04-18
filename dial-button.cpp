#include "dial-button.h"
#include "widget.h"
#include <QDebug>


void DialButton::moveIndex()
{
    if ( m_lettersIndex >= 3 ) {
        m_lettersIndex = 0;
    } else {
        m_lettersIndex++;
    }
}

DialButton::DialButton(Qt::Alignment align, QChar buttons[4], int interval, int step,QWidget *parent)
    : QPushButton(parent), m_interval(interval), m_step(step),
      m_align(align), m_lettersIndex(0)
{

    m_parentWidget = parent;
    m_letters[0] = buttons[0];
    m_letters[1] = buttons[1];
    m_letters[2] = buttons[2];
    m_letters[3] = buttons[3];

    connect(this, SIGNAL(clicked(bool)), this, SLOT(clicked()));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_timer.start();
    label();

}


void DialButton::clicked()
{
    //m_align ^= Qt::AlignCenter;
    //parentWidget()->layout()->setAlignment(this, m_align);
    qDebug() << "clicked button" ;
    static int click = 0;
    {


        int timed_input = m_timer.elapsed() - QTime::currentTime().elapsed();

        int dtime =  m_timer.elapsed() - QTime::currentTime().elapsed();

        if ( dtime <= 1000){
            moveIndex();
        } else {
            m_lettersIndex = 0;
            m_timer.restart();

            //put to screen or insert to the textbox
        }

        qDebug() << "LETTER: " << m_letters[m_lettersIndex];
    }

    label();
}

void DialButton::label()
{
    setText(QString("%1\n%2%3%4").arg(m_letters[0]).arg(m_letters[1]).arg(m_letters[2]).arg(m_letters[3]));
}
