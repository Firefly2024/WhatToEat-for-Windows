#ifndef DETAILCARD_H
#define DETAILCARD_H

#include <QWidget>
#include <QStandardItemModel>
#include "tujianwindow.h"


namespace Ui {
class DetailCard;
}

class DetailCard : public QWidget
{
    Q_OBJECT

public:
    explicit DetailCard(const int& _dish_id,int _mode,TujianWindow* tjparent=nullptr,QWidget *parent = nullptr);
    ~DetailCard();


public slots:
    void reset();

private slots:
    void moreThings();
    void backward();
private:
    TujianWindow* tjWindow;
    Ui::DetailCard *ui;
    QStandardItemModel* model;
    int mode;//mode为0是图鉴模式，mode为1是盲盒模式
    int dish_id;
};

#endif // DETAILCARD_H
