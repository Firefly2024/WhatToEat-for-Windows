#ifndef MORETHINGMENU_H
#define MORETHINGMENU_H

#include <QWidget>
#include "listitemwidget.h"
#include "listitemwidget_2.h"
#include "detailcard.h"

namespace Ui {
class MoreThingMenu;
}

class MoreThingMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MoreThingMenu(const int& dish_id,DetailCard* dcparent,QWidget *parent = nullptr);
    ~MoreThingMenu();

signals:
    void resetParent();

private slots:
    void addTags();
    void addComments();
    void deleteTags(ListItemWidget *widget);
    void deleteComments(ListItemWidget_2 *widget);
    void starZero();
    void starOne();
    void starTwo();
    void starThree();
    void starFour();
    void starFive();
    void Selecteddisconnect();
    void emitScore();
private:
    DetailCard* dcWindow;
    Ui::MoreThingMenu *ui;
    int dish_id;
    int scores=0;
};

#endif // MORETHINGMENU_H
