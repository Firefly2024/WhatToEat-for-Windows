#include "starbutton.h"

StarButton::StarButton(QWidget *pu):QPushButton(pu) {}


void StarButton::leaveEvent(QEvent*event)

{
    //qDebug()<<"1";
    emit leaveEvent_1();
}

//重写鼠标出去时的方法
void StarButton:: enterEvent(QEnterEvent *event)

{
    //qDebug()<<"1";
    emit enterEvent_1();
}
