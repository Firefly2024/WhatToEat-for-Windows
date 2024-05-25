#ifndef LISTITEMWIDGET_H
#define LISTITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class ListItemWidget : public QWidget
{
    Q_OBJECT
public:
   explicit ListItemWidget(int initialLikes, int _dish_id, int _tag_id, QWidget *parent = nullptr);
signals:
   void sendSelf(ListItemWidget* self);
private slots:
    void increaseLikes();
    void deleteSelf();
private:
    QLabel *label;
    QLabel *label_like;
    QPushButton *likeButton;
    QPushButton *deleteButton;
    int likes;
    int dish_id;
    int tag_id;
};

#endif // LISTITEMWIDGET_H
