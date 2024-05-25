#include "morethingmenu.h"
#include "ui_morethingmenu.h"
#include <QLabel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "listitemwidget.h"
#include "listitemwidget_2.h"


MoreThingMenu::MoreThingMenu(const int& _dish_id,DetailCard* dcparent,QWidget *parent)
    : QWidget(parent)
    , dcWindow(dcparent)
    , ui(new Ui::MoreThingMenu)
    , dish_id(_dish_id)
{
    ui->setupUi(this);
    this->setWindowTitle("");
    ui->lwTags->setSelectionMode(QAbstractItemView::NoSelection);
    ui->lwComments->setSelectionMode(QAbstractItemView::NoSelection);
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dishes.db");
    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }


    QSqlQuery query;
    QString sql=QString("SELECT tag_id, times FROM dish_tags WHERE dish_id = %1 AND tag_id >= 19 ORDER BY times DESC" ).arg(this->dish_id);
    if(!query.exec(sql)){
        qDebug()<<"error:"<<query.lastError();
        return;
    }
    while(query.next()){
        QListWidgetItem *item = new QListWidgetItem(ui->lwTags);
        //qDebug()<<query.value(1).toInt()<<" "<<dish_id<<" "<<query.value(0).toInt();
        ListItemWidget* widget = new ListItemWidget(query.value(1).toInt(),dish_id,query.value(0).toInt());
        connect(widget,&ListItemWidget::sendSelf,this,&MoreThingMenu::deleteTags);
        item->setSizeHint(widget->sizeHint());
        ui->lwTags->setItemWidget(item,widget);
    }

    sql=QString("SELECT id, times FROM dish_comments WHERE dish_id = %1 ORDER BY times DESC").arg(this->dish_id);
    if(!query.exec(sql)){
        qDebug()<<"error:"<<query.lastError();
        return;
    }
    while(query.next()){
        QListWidgetItem *item = new QListWidgetItem(ui->lwComments);
        //qDebug()<<query.value(1).toInt()<<" "<<dish_id<<" "<<query.value(0).toInt();
        ListItemWidget_2* widget = new ListItemWidget_2(query.value(1).toInt(),query.value(0).toInt());
        connect(widget,&ListItemWidget_2::sendSelf,this,&MoreThingMenu::deleteComments);
        item->setSizeHint(widget->sizeHint());
        ui->lwComments->setItemWidget(item,widget);
    }

    connect(ui->btAddTag,&QPushButton::clicked,this,&MoreThingMenu::addTags);
    connect(ui->btnAddComment,&QPushButton::clicked,this,&MoreThingMenu::addComments);

    connect(ui->btnStar1,&QPushButton::clicked,this,&MoreThingMenu::starOne);
    connect(ui->btnStar2,&QPushButton::clicked,this,&MoreThingMenu::starTwo);
    connect(ui->btnStar3,&QPushButton::clicked,this,&MoreThingMenu::starThree);
    connect(ui->btnStar4,&QPushButton::clicked,this,&MoreThingMenu::starFour);
    connect(ui->btnStar5,&QPushButton::clicked,this,&MoreThingMenu::starFive);
    connect(ui->btnStar1,&StarButton::enterEvent_1,this,&MoreThingMenu::starOne);
    //connect(ui->btnStar1,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    connect(ui->btnStar2,&StarButton::enterEvent_1,this,&MoreThingMenu::starTwo);
    //connect(ui->btnStar2,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    connect(ui->btnStar3,&StarButton::enterEvent_1,this,&MoreThingMenu::starThree);
    //connect(ui->btnStar3,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    connect(ui->btnStar4,&StarButton::enterEvent_1,this,&MoreThingMenu::starFour);
    //connect(ui->btnStar4,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    connect(ui->btnStar5,&StarButton::enterEvent_1,this,&MoreThingMenu::starFive);
    //connect(ui->btnStar5,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    connect(ui->btnStar1,&QPushButton::clicked,this,&MoreThingMenu::Selecteddisconnect);
    connect(ui->btnStar2,&QPushButton::clicked,this,&MoreThingMenu::Selecteddisconnect);
    connect(ui->btnStar3,&QPushButton::clicked,this,&MoreThingMenu::Selecteddisconnect);
    connect(ui->btnStar4,&QPushButton::clicked,this,&MoreThingMenu::Selecteddisconnect);
    connect(ui->btnStar5,&QPushButton::clicked,this,&MoreThingMenu::Selecteddisconnect);

    connect(ui->btnCommitStar,&QPushButton::clicked,this,&MoreThingMenu::emitScore);

    connect(this,&MoreThingMenu::resetParent,dcWindow,&DetailCard::reset);
}

MoreThingMenu::~MoreThingMenu()
{
    delete ui;
}

void MoreThingMenu::addTags(){
    if(ui->lineNewTag->text()==""){
        return;
    }
    QSqlQuery query;
    QString nametext=ui->lineNewTag->text();

    query.prepare("INSERT OR IGNORE INTO tags (name) VALUES (:name)");
    query.bindValue(":name", nametext);

    // if (!query.exec()) {
    //     qDebug() << "Failed to add tag:" << query.lastError().text();
    // }

    if (!query.exec()) {
        qDebug() << "Failed to add tag:" << query.lastError().text();
    } else {
        qDebug() << "Tag added successfully!";
    }

    query.prepare("SELECT id FROM tags WHERE name = (:name)");
    query.bindValue(":name",nametext);
    if(!query.exec()){
        qDebug() << "Failed to get tag_id:" << query.lastError().text();
    }
    int tagId=0;
    if(query.next()){
        tagId = query.value(0).toInt();
    }

    query.prepare("INSERT INTO dish_tags (dish_id, tag_id, times) VALUES (:dish_id, :tag_id, :times)" );
    query.bindValue(":dish_id", this->dish_id);
    query.bindValue(":tag_id", tagId);
    query.bindValue(":times",1);
    qDebug()<<this->dish_id<<"  "<<tagId;
    if (!query.exec()) {
        qDebug() << "Failed to add dish-tag relation:" << query.lastError().text();
    } else {
        qDebug() << "Dish-tag relation added successfully!";
    }

    QListWidgetItem *item = new QListWidgetItem(ui->lwTags);
    ListItemWidget* widget = new ListItemWidget(1,this->dish_id,tagId);
    item->setSizeHint(widget->sizeHint());
    ui->lwTags->setItemWidget(item,widget);

    emit resetParent();
}

void MoreThingMenu::addComments(){
    if(ui->textComment->toPlainText()==""){
        return;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO dish_comments (dish_id, comment, times) VALUES (:dish_id, :comment, :times)" );
    query.bindValue(":dish_id", this->dish_id);
    query.bindValue(":comment", ui->textComment->toPlainText());
    query.bindValue(":times",1);

    if (!query.exec()) {
        qDebug() << "Failed to add dish-comment relation:" << query.lastError().text();
    } else {
        qDebug() << "Dish-comment relation added successfully!";
    }

    int newId = query.lastInsertId().toInt();

    QListWidgetItem *item = new QListWidgetItem(ui->lwComments);
    ListItemWidget_2* widget = new ListItemWidget_2(1,newId);
    item->setSizeHint(widget->sizeHint());
    ui->lwComments->setItemWidget(item,widget);

    emit resetParent();
}

void MoreThingMenu::deleteTags(ListItemWidget* widget){
    for (int i = 0; i < ui->lwTags->count(); ++i) {
        QListWidgetItem *item = ui->lwTags->item(i);
        if (ui->lwTags->itemWidget(item) == widget) {
            ui->lwTags->removeItemWidget(item);
            delete widget;
            delete item;
            break;
        }
    }
    emit resetParent();

}

void MoreThingMenu::deleteComments(ListItemWidget_2* widget){
    for (int i = 0; i < ui->lwComments->count(); ++i) {
        QListWidgetItem *item = ui->lwComments->item(i);
        if (ui->lwComments->itemWidget(item) == widget) {
            ui->lwComments->removeItemWidget(item);
            delete widget;
            delete item;
            break;
        }
    }
    emit resetParent();
}

void MoreThingMenu::emitScore(){
    QSqlQuery query;
    QString sql = QString("UPDATE dishes SET rating = %1 WHERE id = %2").arg(scores).arg(this->dish_id);
    if(!query.exec(sql)){
        qDebug() << "Error: Failed to execute query: " << query.lastError();
    }

    emit resetParent();
}

void MoreThingMenu::starZero()
{
    ui->btnStar1->setIcon(QIcon("://images/star.svg"));
    ui->btnStar2->setIcon(QIcon("://images/star.svg"));
    ui->btnStar3->setIcon(QIcon("://images/star.svg"));
    ui->btnStar4->setIcon(QIcon("://images/star.svg"));
    ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    scores=0;
}

void MoreThingMenu::starOne()
{
    ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar2->setIcon(QIcon("://images/star.svg"));
    ui->btnStar3->setIcon(QIcon("://images/star.svg"));
    ui->btnStar4->setIcon(QIcon("://images/star.svg"));
    ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    scores=1;
}

void MoreThingMenu::starTwo()
{
    ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar2->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar3->setIcon(QIcon("://images/star.svg"));
    ui->btnStar4->setIcon(QIcon("://images/star.svg"));
    ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    scores=2;
}

void MoreThingMenu::starThree()
{
    ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar2->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar3->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar4->setIcon(QIcon("://images/star.svg"));
    ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    scores=3;
}

void MoreThingMenu::starFour()
{
    ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar2->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar3->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar4->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    scores=4;
}

void MoreThingMenu::starFive()
{
    ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar2->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar3->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar4->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar5->setIcon(QIcon("://images/star (full).svg"));
    scores=5;
}

void MoreThingMenu::Selecteddisconnect(){
    disconnect(ui->btnStar1,&StarButton::enterEvent_1,this,&MoreThingMenu::starOne);
    //disconnect(ui->btnStar1,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    disconnect(ui->btnStar2,&StarButton::enterEvent_1,this,&MoreThingMenu::starTwo);
    //disconnect(ui->btnStar2,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    disconnect(ui->btnStar3,&StarButton::enterEvent_1,this,&MoreThingMenu::starThree);
    //disconnect(ui->btnStar3,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    disconnect(ui->btnStar4,&StarButton::enterEvent_1,this,&MoreThingMenu::starFour);
    //disconnect(ui->btnStar4,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    disconnect(ui->btnStar5,&StarButton::enterEvent_1,this,&MoreThingMenu::starFive);
    //disconnect(ui->btnStar5,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
}


