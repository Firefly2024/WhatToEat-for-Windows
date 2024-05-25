#include "listitemwidget.h"
#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QHBoxLayout>



ListItemWidget::ListItemWidget(int initialLikes,int _dish_id,int _tag_id, QWidget *parent)
    : QWidget(parent), likes(initialLikes), dish_id(_dish_id),tag_id(_tag_id) {

    QSqlQuery query;
    QString sql=QString("SELECT name FROM tags WHERE id = %1").arg(tag_id);
    //qDebug()<<sql;
    if(!query.exec(sql)){
        qDebug()<<"error";
    }

    if(query.next()){
        label = new QLabel(query.value(0).toString());
    }

    label_like=new QLabel(QString::number(likes));

    likeButton = new QPushButton();
    likeButton->setIcon(QIcon("://images/thumbs-up.svg"));
    deleteButton = new QPushButton();
    deleteButton->setIcon(QIcon("://images/delete.svg"));
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(label);
    layout->addStretch();
    layout->addWidget(label_like);
    layout->addWidget(likeButton);
    layout->addWidget(deleteButton);

    setLayout(layout);

    connect(likeButton, &QPushButton::clicked, this, &ListItemWidget::increaseLikes);
    connect(deleteButton,&QPushButton::clicked,this,&ListItemWidget::deleteSelf);
}

void ListItemWidget::increaseLikes() {
    likes++;
    label_like->setText(QString::number(likes));
    QSqlQuery query;
    QString sql=QString("UPDATE dish_tags SET times = times + 1 WHERE dish_id = %1 AND tag_id = %2").arg(this->dish_id).arg(this->tag_id);
    if(!query.exec(sql)){
        qDebug() << "Error: Failed to execute query: " << query.lastError();
    }
}

void ListItemWidget::deleteSelf(){
    QSqlQuery query;
    QString sql=QString("DELETE FROM dish_tags WHERE dish_id = %1 AND tag_id = %2").arg(this->dish_id).arg(this->tag_id);
    if(!query.exec(sql)){
        qDebug() << "Error: Failed to delete " << query.lastError();
    }
    emit sendSelf(this);
}
