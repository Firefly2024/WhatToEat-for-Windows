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
    explicit DetailCard(const int& _dish_id,TujianWindow* tjparent,QWidget *parent = nullptr);
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
    int dish_id;
};

#endif // DETAILCARD_H
