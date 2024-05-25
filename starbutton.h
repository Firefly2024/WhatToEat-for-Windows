#ifndef STARBUTTON_H
#define STARBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QCoreApplication>
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>




#include <QPushButton>

class StarButton : public QPushButton {
    Q_OBJECT

public:
    StarButton(QWidget *pu = nullptr);

    //信号
signals:
    void leaveEvent_1();
    void enterEvent_1();
protected:
    void leaveEvent(QEvent*event);//重写鼠标出去时的方法
   void enterEvent(QEnterEvent *event);

};
#endif // STARBUTTON_H
