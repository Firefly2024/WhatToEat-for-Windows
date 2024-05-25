#ifndef LISTITEMWIDGET_2_H
#define LISTITEMWIDGET_2_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class ListItemWidget_2 : public QWidget
{
    Q_OBJECT
public:
    explicit ListItemWidget_2(int initialLikes, int _cm_id , QWidget *parent = nullptr);
signals:
    void sendSelf(ListItemWidget_2* widget);
private slots:
    void increaseLikes();
    void deleteSelf();
private:
    QLabel *label;
    QLabel *label_like;
    QPushButton *likeButton;
    QPushButton *deleteButton;
    int likes;
    int cm_id;
};

#endif // LISTITEMWIDGET_2_H
