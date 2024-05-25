#include "messagebutton.h"

MessageButton::MessageButton(QWidget *parent):QPushButton(parent) {
    connect(this,&QPushButton::clicked,this,&MessageButton::goDetail);
}
void MessageButton::goDetail(){
    //qDebug()<<this->dish_id;
    emit sendId(this->dish_id);
}
