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
             name TEXT NOT NULL UNIQUE，
             type INTEGER NOT NULL
            //数字对应关系
            // 0 位置（这个没用）
            // 1 时段
            // 2 菜系
            // 3 菜品类别
            // 4 主要成分
            // 5 烹饪方法
            // 6 口味、口感
            // 7 忌口、饮食限制
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


//打印出database的函数
/*void printDishes() {
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    QString queryString = "SELECT * FROM dishes";

    if (query.exec(queryString)) {
        while (query.next()) {
            // 获取每个字段的值
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            //QString file_location = query.value(2).toString();没用上
            int rating = query.value(3).toInt();
            QString place = query.value(4).toString();
            double price = query.value(5).toDouble();

            // 打印字段值
            qDebug() << "ID: " << id
                     << ", Name: " << name
                     << ", Rating: " << rating
                     << ", Place: " << place
                     << ", Price: " << price;
        }
    } else {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    }
}*/

/*void printTags() {
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    QString queryString = "SELECT * FROM tags";

    if (query.exec(queryString)) {
        while (query.next()) {
            // 获取每个字段的值
            int id = query.value(0).toInt();
            QString tag_name = query.value(1).toString();
            int tag_type = query.value(2).toInt();

            // 打印字段值
            qDebug() << "ID: " << id << ", Tag Name: " << tag_name << ", Tag Type: "<<tag_type;
        }
    } else {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    }
}*/

/*void printDishesTags() {
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    QString queryString = "SELECT * FROM dish_tags";

    if (query.exec(queryString)) {
        while (query.next()) {
            // 获取每个字段的值
            int dish_ID = query.value(0).toInt();
            int tag_ID = query.value(1).toInt();

            // 打印字段值
            qDebug() << "Dish_ID: " << dish_ID << ", Tag_ID: " << tag_ID;
        }
    } else {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    }
}

void printDishComments() {
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    QString queryString = "SELECT * FROM dish_comments";

    if (query.exec(queryString)) {
        while (query.next()) {
            // 获取每个字段的值
            int commentId = query.value(0).toInt();
            int dishId = query.value(1).toInt();
            QString commentContent = query.value(2).toString();
            int commentTime = query.value(3).toInt();

            // 打印字段值
            qDebug() << "Comment ID: " << commentId
                     << ", Dish ID: " << dishId
                     << ", Comment: " << commentContent
                     << ", Comment Time: " << commentTime;
        }
    } else {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    }
}*/

//初始化tag——type的函数，注释掉的是没有这个id，应该是删了
/*void chushitagtap(){
    for(int i=1;i<=82;i++){
        // 假设我们要更新 tag_id 为 1 的记录的 type 字段
        int tagIdToUpdate = i;
        int newType=1;
        switch(tagIdToUpdate){
        case 1:newType=1;break;
        case 2:newType=1;break;
        case 3:newType=1;break;
        case 4:newType=2;break;
        case 5:newType=2;break;
        case 6:newType=0;break;
        case 7:newType=0;break;
        case 8:newType=0;break;
        case 9:newType=0;break;
        case 10:newType=0;break;
        case 11:newType=3;break;
        case 12:newType=3;break;
        case 13:newType=3;break;
        case 14:newType=3;break;
        case 15:newType=3;break;
        case 16:newType=3;break;
        case 17:newType=4;break;
        case 18:newType=4;break;
        case 19:newType=4;break;
        case 20:newType=4;break;
        case 21:newType=4;break;
        case 22:newType=4;break;
        case 23:newType=4;break;
        case 24:newType=4;break;
        case 25:newType=4;break;
        case 26:newType=4;break;
        case 27:newType=5;break;
        case 28:newType=5;break;
        case 29:newType=5;break;
        case 30:newType=5;break;
        case 31:newType=5;break;
        case 32:newType=5;break;
        case 33:newType=5;break;
        case 34:newType=6;break;
        case 35:newType=6;break;
        case 36:newType=6;break;
        case 37:newType=6;break;
        case 38:newType=6;break;
        case 39:newType=6;break;
        case 40:newType=6;break;
        case 41:newType=6;break;
        case 42:newType=6;break;
        case 43:newType=6;break;
        case 44:newType=6;break;
        case 45:newType=6;break;
        case 46:newType=6;break;
        case 47:newType=6;break;
        case 48:newType=6;break;
        case 49:newType=6;break;
        case 50:newType=6;break;
        case 51:newType=6;break;
        case 52:newType=6;break;
        case 53:newType=7;break;
        case 54:newType=7;break;
        case 55:newType=7;break;
        case 56:newType=7;break;
        case 57:newType=7;break;
        case 58:newType=7;break;
        case 59:newType=7;break;
        case 60:newType=7;break;
        case 61:newType=7;break;
        case 62:newType=5;break;
        case 63:newType=6;break;
        case 64:newType=4;break;
        //case 65:newType=5;break;
        case 66:newType=5;break;
        case 67:newType=4;break;
        case 68:newType=5;break;
        case 69:newType=4;break;
        //case 70:newType=1;break;
        case 71:newType=4;break;
        //case 72:newType=1;break;
        case 73:newType=4;break;
        case 74:newType=6;break;
        case 75:newType=4;break;
        //case 76:newType=1;break;
        case 77:newType=5;break;
        case 78:newType=4;break;
        case 79:newType=4;break;
        case 80:newType=6;break;
        case 81:newType=4;break;
        case 82:newType=5;break;
        }


        QString updateStmt = QString("UPDATE tags SET type = %1 WHERE id = %2")
                                 .arg(newType)
                                 .arg(tagIdToUpdate);

        QSqlQuery query;
        if (!query.exec(updateStmt)) {
            qDebug() << "Failed to update tag type:" << query.lastError().text();
        } else {
            qDebug() << "Tag type updated successfully!";
        }
    }
}*/


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

    /* 输出应用程序运行文件夹的路径（即db所在位置）
    QString appDir = QCoreApplication::applicationDirPath();
    qDebug() << "Application directory: " << appDir;*/

    // chushitagtype();
    // printDishes();
    //printTags();
    // printDishesTags();
    // printDishComments();

    Widget w;
    w.show();

    return a.exec();
}
