#ifndef MESSAGEBUTTON_H
#define MESSAGEBUTTON_H

#include <QPushButton>

class MessageButton : public QPushButton
{
    Q_OBJECT
public:
    MessageButton(QWidget *parent = nullptr);
    int dish_id=-1;
public slots:
    void goDetail();
signals:
    void sendId(const int& dish_id);
};

#endif // MESSAGEBUTTON_H
