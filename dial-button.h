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
    QTime       m_timestop;

    QChar       m_letters[4];
    quint32     m_lettersIndex;
    void        moveIndex(void);

signals:
    void signalDisplay(QChar c);
    void signalParent(int id);
public slots:
    void clicked() ;
    void label();
public:
    virtual QChar   getCurrentSymbol(void);
    explicit DialButton(Qt::Alignment align, QChar buttons[4], int id, QWidget* parent=0);

private:
    QWidget* m_parentWidget;
    int m_id;
};

#endif // DIALBUTTON_H
