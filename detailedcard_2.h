#ifndef DETAILEDCARD_2_H
#define DETAILEDCARD_2_H

#include <QWidget>
#include <QStandardItemModel>
#include "manghewindow.h"


namespace Ui {
class DetailCard_2;
}

class DetailCard_2 : public QWidget
{
    Q_OBJECT

public:
    explicit DetailCard_2(const int& _dish_id,Ui_MangheWindow* tjparent,QWidget *parent = nullptr);
    ~DetailCard_2();


public slots:
    void reset();

private slots:
    void moreThings();
    void backward();
private:
    Ui_MangheWindow* mhWindow;
    Ui::DetailCard_2 *ui;
    QStandardItemModel* model;
    int dish_id;
};

#endif // DETAILEDCARD_2_H
