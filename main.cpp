#include "widget.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QApplication>
void LoadSQL(){
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

    //QSqlQuery query;

    /*  //创建dishes表
    QString createDishesTable = R"(
     CREATE TABLE IF NOT EXISTS dishes (
             id INTEGER PRIMARY KEY AUTOINCREMENT,
             name TEXT NOT NULL,
             file_location TEXT NOT NULL,
             rating INTEGER NOT NULL CHECK (rating >= 0 AND rating <= 5),
             place,
             price
         )
     )";
     if (!query.exec(createDishesTable)) {
         qDebug() << "Failed to create dishes table:" << query.lastError().text();
     }

    // 创建tags表
     QString createTagsTable = R"(
         CREATE TABLE IF NOT EXISTS tags (
             id INTEGER PRIMARY KEY AUTOINCREMENT,
             name TEXT NOT NULL UNIQUE
         )
     )";
     if (!query.exec(createTagsTable)) {
         qDebug() << "Failed to create tags table:" << query.lastError().text();
     }

    // 创建dish_tags表
     QString createDishTagsTable = R"(
         CREATE TABLE IF NOT EXISTS dish_tags (
             dish_id INTEGER NOT NULL,
             tag_id INTEGER NOT NULL,
             times INTEGER NOT NULL,
             FOREIGN KEY (dish_id) REFERENCES dishes(id),
             FOREIGN KEY (tag_id) REFERENCES tags(id),
             PRIMARY KEY (dish_id, tag_id)
         )
     )";
     if (!query.exec(createDishTagsTable)) {
         qDebug() << "Failed to create dish_tags table:" << query.lastError().text();
     }

    //创建dish_comments表
    QString createDishCommentsTable = R"(
         CREATE TABLE IF NOT EXISTS dish_comments (
             id INTEGER PRIMARY KEY AUTOINCREMENT,
             dish_id INTEGER NOT NULL,
             comment TEXT NOT NULL,
             times INTEGER NOT NULL,
             FOREIGN KEY (dish_id) REFERENCES dishes(id)
         )
     )";
     if(!query.exec(createDishCommentsTable)){
         qDebug() << "Failed to create table:" << query.lastError().text();
     }else{
         qDebug() <<"success";
     }*/

    /*QString tagName = "无乳制品";
    QString insertStmt = QString("INSERT INTO tags (name) VALUES ('%1')").arg(tagName);

    QSqlQuery query;
    if (!query.exec(insertStmt)) {
        qDebug() << "Failed to insert tag into tags table:" << query.lastError().text();
    } else {
        qDebug() << "Tag inserted successfully!";
    }*/ //手动添加标签

    /* QString newFileLocation = "://images/dishes/tdnbf_j2_10.jpg"; // 新的文件位置
    int dishId = 3; // 要更新的菜品的ID

    QString updateStmt = QString("UPDATE dishes SET file_location = '%1' WHERE id = %2").arg(newFileLocation, QString::number(dishId));

    QSqlQuery query;
    if (!query.exec(updateStmt)) {
        qDebug() << "Failed to update file_location for dish:" << query.lastError().text();
    } else {
        qDebug() << "File location updated successfully!";
    }*/ // 要是不小心上传了中文的图片 可以用这个指令修改
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoadSQL();
    /*QString sql=QString("SELECT dish_id, tag_id FROM dish_tags");
    QSqlQuery queryA;
    if(!queryA.exec(sql)){
         qDebug()<<queryA.lastError().text();
     }else{
         qDebug()<<"success";
     }

     while(queryA.next()){
         qDebug()<<queryA.value("dish_id").toInt()<<queryA.value("tag_id").toInt();
         //qDebug()<<queryA.value("file_location").toString();
     }*/

    //从19开始

    /*QSqlQuery query;
    QString sql = "DROP TABLE IF EXISTS dish_comments";
     if (!query.exec(sql)) {
         qDebug() << "Error: Failed to execute query - " << query.lastError();
     }else{
         qDebug()<<"success";
     }*/

    Widget w;
    w.show();

    return a.exec();
}
