#include "dial-button.h"
#include "widget.h"
#include <QDebug>
#include <QMutex>
#include <iostream>


void DialButton::moveIndex()
{
    if ( m_lettersIndex >= 3 ) {
        m_lettersIndex = 0;
    } else {
        m_lettersIndex++;
    }
}

DialButton::DialButton(Qt::Alignment align, QChar buttons[4], int id,QWidget *parent)
    : QPushButton(parent), m_id(id),
      m_align(align), m_lettersIndex(0)
{

    m_parentWidget = parent;
    m_letters[0] = buttons[0];
    m_letters[1] = buttons[1];
    m_letters[2] = buttons[2];
    m_letters[3] = buttons[3];
    m_timer.start();
    connect(this, SIGNAL(clicked(bool)), this, SLOT(clicked()));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label();
    m_parentWidget = (Widget*)parent;

}


void DialButton::clicked()
{
    //m_align ^= Qt::AlignCenter;
    //parentWidget()->layout()->setAlignment(this, m_align);
    static QMutex mutex;
    qDebug() << "clicked button" ;
    static int click = 0;
    mutex.lock();
   // m_timestop.start();
    {

        int dtime =  m_timer.elapsed() - QTime::currentTime().elapsed();//- m_timestop.elapsed();

        if ( dtime <= 1000){
            moveIndex();
            emit signalParent(m_lettersIndex);

        } else {
            m_lettersIndex = 0;
            m_timer.restart();
            emit signalParent(m_lettersIndex);
            //put to screen or insert to the textbox
        }
        qDebug() << "LETTER: " << m_letters[m_lettersIndex];
        std::cout << "LETTER:" << m_letters[m_lettersIndex].toLatin1()
                     << std::endl;
    }
    mutex.unlock();
    label();
}

void DialButton::label()
{
    setText(QString("%1\n%2%3%4").arg(m_letters[0]).arg(m_letters[1]).arg(m_letters[2]).arg(m_letters[3]));
}


QChar DialButton::getCurrentSymbol(void)
{
    return m_letters[m_lettersIndex];
}
