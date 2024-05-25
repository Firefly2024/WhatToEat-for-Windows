#include "listitemwidget_2.h"

#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QHBoxLayout>



ListItemWidget_2::ListItemWidget_2(int initialLikes,int _cm_id, QWidget *parent)
    : QWidget(parent), likes(initialLikes),cm_id(_cm_id) {

    QSqlQuery query;
    QString sql=QString("SELECT comment FROM dish_comments WHERE id = %1").arg(cm_id);
    qDebug()<<sql;
    if(query.exec(sql)){
        qDebug()<<"called";
    }else{
        qDebug()<<"error";
    }
    if(query.next()){
        label = new QLabel(query.value(0).toString());
    }

    label->setWordWrap(true);
    label->setTextFormat(Qt::RichText);

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

    connect(likeButton, &QPushButton::clicked, this, &ListItemWidget_2::increaseLikes);
    connect(deleteButton,&QPushButton::clicked,this,&ListItemWidget_2::deleteSelf);
}

void ListItemWidget_2::increaseLikes() {
    likes++;
    label_like->setText(QString::number(likes));
    QSqlQuery query;
    QString sql=QString("UPDATE dish_comments SET times = times + 1 WHERE id = %1").arg(this->cm_id);
    if(!query.exec(sql)){
        qDebug() << "Error: Failed to execute query: " << query.lastError();
    }
}

void ListItemWidget_2::deleteSelf(){
    QSqlQuery query;
    QString sql=QString("DELETE FROM dish_comments WHERE id = %1").arg(this->cm_id);
    if(!query.exec(sql)){
        qDebug() << "Error: Failed to delete " << query.lastError();
    }
    emit sendSelf(this);
}
