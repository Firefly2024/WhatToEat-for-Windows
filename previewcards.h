#ifndef PREVIEWCARDS_H
#define PREVIEWCARDS_H

#include <QWidget>
#include "tujianwindow.h"

namespace Ui {
class PreviewCards;
}

class PreviewCards : public QWidget
{
    Q_OBJECT

public:
    explicit PreviewCards(int ids[6],int size,TujianWindow* tjparent,QWidget *parent = nullptr);
    ~PreviewCards();
public slots:


private slots:
    void showDetail(const int &dish_id);
private:
    TujianWindow* tjWindow;
    Ui::PreviewCards *ui;
};

#endif // PREVIEWCARDS_H
