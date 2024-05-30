#include "manghewindow.h"
#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QHBoxLayout>
#include <QDebug>
#include <QRandomGenerator>
#include <QTime>
#include <QPushButton>

void Ui_MangheWindow::setupUi(QMainWindow *MangheWindow){
    if (MangheWindow->objectName().isEmpty())
        MangheWindow->setObjectName(QString::fromUtf8("MangheWindow"));
    MangheWindow->resize(800, 600);
    centralwidget = new QWidget(MangheWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    lable_1_tishiyv = new QLabel(centralwidget);
    lable_1_tishiyv->setObjectName(QString::fromUtf8("lable_1_tishiyv"));
    lable_1_tishiyv->setGeometry(QRect(100, 50, 600, 31));
    QFont font;
    font.setPointSize(10);
    lable_1_tishiyv->setFont(font);
    generate = new QPushButton(centralwidget);
    generate->setObjectName(QString::fromUtf8("generate"));
    generate->setGeometry(QRect(490, 530, 80, 24));
    btnHome = new QPushButton(centralwidget);
    btnHome->setObjectName(QString::fromUtf8("btnHome"));
    btnHome->setGeometry(QRect(690, 10, 91, 31));
    btnHome->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border:none;\n"
                                             "border-radius: 10px;}QPushButton:hover{background:rgb(213, 215, 215);}"));
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/home-two.svg"), QSize(), QIcon::Normal, QIcon::Off);
    btnHome->setIcon(icon);
    btnHome->setIconSize(QSize(20, 20));
    change = new QPushButton(centralwidget);
    change->setObjectName(QString::fromUtf8("change"));
    change->setGeometry(QRect(230, 530, 80, 24));
    box_shiduan = new QGroupBox(centralwidget);
    box_shiduan->setObjectName(QString::fromUtf8("groupBox"));
    box_shiduan->setGeometry(QRect(200, 80, 400, 60));
    horizontalLayoutWidget = new QWidget(box_shiduan);
    horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
    horizontalLayoutWidget->setGeometry(QRect(30, 30, 341, 24));
    horizontalLayout_shiduan = new QHBoxLayout(horizontalLayoutWidget);
    horizontalLayout_shiduan->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalLayout_shiduan->setContentsMargins(0, 0, 0, 0);
    zaocan = new QCheckBox(horizontalLayoutWidget);
    zaocan->setObjectName(QString::fromUtf8("checkBox_3"));

    horizontalLayout_shiduan->addWidget(zaocan);

    checkBox_2 = new QCheckBox(horizontalLayoutWidget);
    checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

    horizontalLayout_shiduan->addWidget(checkBox_2);

    wancan = new QCheckBox(horizontalLayoutWidget);
    wancan->setObjectName(QString::fromUtf8("checkBox"));

    horizontalLayout_shiduan->addWidget(wancan);

    box_caixi = new QGroupBox(centralwidget);
    box_caixi->setObjectName(QString::fromUtf8("groupBox_2"));
    box_caixi->setGeometry(QRect(200, 140, 400, 60));
    horizontalLayoutWidget_2 = new QWidget(box_caixi);
    horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
    horizontalLayoutWidget_2->setGeometry(QRect(30, 30, 341, 24));
    horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
    xican = new QCheckBox(horizontalLayoutWidget_2);
    xican->setObjectName(QString::fromUtf8("checkBox_5"));

    horizontalLayout_3->addWidget(xican);

    checkBox_4 = new QCheckBox(horizontalLayoutWidget_2);
    checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

    horizontalLayout_3->addWidget(checkBox_4);

    box_caipinleibie = new QGroupBox(centralwidget);
    box_caipinleibie->setObjectName(QString::fromUtf8("groupBox_3"));
    box_caipinleibie->setGeometry(QRect(200, 200, 400, 60));
    horizontalLayoutWidget_3 = new QWidget(box_caipinleibie);
    horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
    horizontalLayoutWidget_3->setGeometry(QRect(30, 30, 351, 24));
    horizontalLayout_caipinleibie = new QHBoxLayout(horizontalLayoutWidget_3);
    horizontalLayout_caipinleibie->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    horizontalLayout_caipinleibie->setContentsMargins(0, 0, 0, 0);
    leibie_1 = new QCheckBox(horizontalLayoutWidget_3);
    leibie_1->setObjectName(QString::fromUtf8("checkBox_10"));

    horizontalLayout_caipinleibie->addWidget(leibie_1);

    leibie_2 = new QCheckBox(horizontalLayoutWidget_3);
    leibie_2->setObjectName(QString::fromUtf8("checkBox_9"));

    horizontalLayout_caipinleibie->addWidget(leibie_2);

    checkBox_8 = new QCheckBox(horizontalLayoutWidget_3);
    checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));

    horizontalLayout_caipinleibie->addWidget(checkBox_8);

    leibie_4 = new QCheckBox(horizontalLayoutWidget_3);
    leibie_4->setObjectName(QString::fromUtf8("checkBox_7"));

    horizontalLayout_caipinleibie->addWidget(leibie_4);

    groupBox_6 = new QGroupBox(centralwidget);
    groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
    groupBox_6->setGeometry(QRect(200, 320, 400, 60));
    horizontalLayoutWidget_4 = new QWidget(groupBox_6);
    horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
    horizontalLayoutWidget_4->setGeometry(QRect(30, 30, 351, 24));
    horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
    kouwei_1 = new QCheckBox(horizontalLayoutWidget_4);
    kouwei_1->setObjectName(QString::fromUtf8("checkBox_11"));

    horizontalLayout_5->addWidget(kouwei_1);

    checkBox_12 = new QCheckBox(horizontalLayoutWidget_4);
    checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));

    horizontalLayout_5->addWidget(checkBox_12);

    kouwei_3 = new QCheckBox(horizontalLayoutWidget_4);
    kouwei_3->setObjectName(QString::fromUtf8("checkBox_13"));

    horizontalLayout_5->addWidget(kouwei_3);

    checkBox_14 = new QCheckBox(horizontalLayoutWidget_4);
    checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));

    horizontalLayout_5->addWidget(checkBox_14);

    box_jikouyinshixianzhi = new QGroupBox(centralwidget);
    box_jikouyinshixianzhi->setObjectName(QString::fromUtf8("groupBox_4"));
    box_jikouyinshixianzhi->setGeometry(QRect(200, 380, 401, 121));
    gridLayoutWidget = new QWidget(box_jikouyinshixianzhi);
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(30, 30, 341, 81));
    gridLayout_jikouyinshixianzhi = new QGridLayout(gridLayoutWidget);
    gridLayout_jikouyinshixianzhi->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout_jikouyinshixianzhi->setContentsMargins(0, 0, 0, 0);
    ditanshui = new QCheckBox(gridLayoutWidget);
    ditanshui->setObjectName(QString::fromUtf8("checkBox_15"));

    gridLayout_jikouyinshixianzhi->addWidget(ditanshui, 1, 0, 1, 1);

    wujianguo = new QCheckBox(gridLayoutWidget);
    wujianguo->setObjectName(QString::fromUtf8("checkBox_19"));

    gridLayout_jikouyinshixianzhi->addWidget(wujianguo, 2, 1, 1, 1);

    qvansu = new QCheckBox(gridLayoutWidget);
    qvansu->setObjectName(QString::fromUtf8("checkBox_6"));

    gridLayout_jikouyinshixianzhi->addWidget(qvansu, 0, 0, 1, 1);

    checkBox_18 = new QCheckBox(gridLayoutWidget);
    checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));

    gridLayout_jikouyinshixianzhi->addWidget(checkBox_18, 1, 1, 1, 1);

    checkBox_16 = new QCheckBox(gridLayoutWidget);
    checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));

    gridLayout_jikouyinshixianzhi->addWidget(checkBox_16, 2, 0, 1, 1);

    qingzhen = new QCheckBox(gridLayoutWidget);
    qingzhen->setObjectName(QString::fromUtf8("checkBox_17"));

    gridLayout_jikouyinshixianzhi->addWidget(qingzhen, 0, 1, 1, 1);

    wuxiangcai = new QCheckBox(gridLayoutWidget);
    wuxiangcai->setObjectName(QString::fromUtf8("checkBox_20"));

    gridLayout_jikouyinshixianzhi->addWidget(wuxiangcai, 0, 2, 1, 1);

    diyou = new QCheckBox(gridLayoutWidget);
    diyou->setObjectName(QString::fromUtf8("checkBox_21"));

    gridLayout_jikouyinshixianzhi->addWidget(diyou, 1, 2, 1, 1);

    checkBox_22 = new QCheckBox(gridLayoutWidget);
    checkBox_22->setObjectName(QString::fromUtf8("checkBox_22"));

    gridLayout_jikouyinshixianzhi->addWidget(checkBox_22, 2, 2, 1, 1);

    box_zhuyaochengfen = new QGroupBox(centralwidget);
    box_zhuyaochengfen->setObjectName(QString::fromUtf8("groupBox_5"));
    box_zhuyaochengfen->setGeometry(QRect(200, 260, 400, 60));
    horizontalLayoutWidget_5 = new QWidget(box_zhuyaochengfen);
    horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
    horizontalLayoutWidget_5->setGeometry(QRect(30, 30, 351, 24));
    horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
    checkBox_23 = new QCheckBox(horizontalLayoutWidget_5);
    checkBox_23->setObjectName(QString::fromUtf8("checkBox_23"));

    horizontalLayout_6->addWidget(checkBox_23);

    checkBox_24 = new QCheckBox(horizontalLayoutWidget_5);
    checkBox_24->setObjectName(QString::fromUtf8("checkBox_24"));

    horizontalLayout_6->addWidget(checkBox_24);

    chengfen_3 = new QCheckBox(horizontalLayoutWidget_5);
    chengfen_3->setObjectName(QString::fromUtf8("checkBox_25"));

    horizontalLayout_6->addWidget(chengfen_3);

    checkBox_26 = new QCheckBox(horizontalLayoutWidget_5);
    checkBox_26->setObjectName(QString::fromUtf8("checkBox_26"));

    horizontalLayout_6->addWidget(checkBox_26);

    MangheWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MangheWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 21));
    MangheWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MangheWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MangheWindow->setStatusBar(statusbar);

    retranslateUi(MangheWindow);

    QMetaObject::connectSlotsByName(MangheWindow);
    getIdVector();
    random_tags();
} // setupUi

void Ui_MangheWindow::retranslateUi(QMainWindow *MangheWindow){
    MangheWindow->setWindowTitle(QCoreApplication::translate("MangheWindow", "MainWindow", nullptr));
    lable_1_tishiyv->setText(QCoreApplication::translate("MangheWindow", "\350\257\267\351\200\211\346\213\251\344\275\240\345\226\234\346\254\242\347\232\204tag\357\274\214\347\202\271\345\207\273\345\274\200\345\247\213\347\224\237\346\210\220\357\274\214\344\270\272\344\275\240\351\232\217\346\234\272\347\224\237\346\210\220\344\270\200\344\273\275\347\276\216\345\221\263\345\220\247\357\274\201\357\274\210\346\210\226\350\200\205\347\202\271\345\207\273\346\215\242\344\270\200\346\211\271\346\235\245\346\233\264\346\215\242\344\270\213\351\235\242\347\232\204\351\200\211\351\241\271\357\274\211", nullptr));
    generate->setText(QCoreApplication::translate("MangheWindow", "\346\215\242\344\270\200\346\211\271", nullptr));
    btnHome->setText(QCoreApplication::translate("MangheWindow", "\350\277\224\345\233\236\351\246\226\351\241\265", nullptr));
    change->setText(QCoreApplication::translate("MangheWindow", "\345\274\200\345\247\213\347\224\237\346\210\220", nullptr));
    box_shiduan->setTitle(QCoreApplication::translate("MangheWindow", "\346\227\266\346\256\265", nullptr));
    zaocan->setText(QCoreApplication::translate("MangheWindow", "\346\227\251\351\244\220", nullptr));
    checkBox_2->setText(QCoreApplication::translate("MangheWindow", "\345\215\210\351\244\220", nullptr));
    wancan->setText(QCoreApplication::translate("MangheWindow", "\346\231\232\351\244\220", nullptr));
    box_caixi->setTitle(QCoreApplication::translate("MangheWindow", "\350\217\234\347\263\273", nullptr));
    xican->setText(QCoreApplication::translate("MangheWindow", "\344\270\255\351\244\220", nullptr));
    checkBox_4->setText(QCoreApplication::translate("MangheWindow", "\350\245\277\351\244\220", nullptr));
    box_caipinleibie->setTitle(QCoreApplication::translate("MangheWindow", "\350\217\234\345\223\201\347\261\273\345\210\253", nullptr));
    leibie_1->setText(QCoreApplication::translate("MangheWindow", "\347\261\273\345\210\2531", nullptr));
    leibie_2->setText(QCoreApplication::translate("MangheWindow", "\347\261\273\345\210\2532", nullptr));
    checkBox_8->setText(QCoreApplication::translate("MangheWindow", "\347\261\273\345\210\2533", nullptr));
    leibie_4->setText(QCoreApplication::translate("MangheWindow", "\347\261\273\345\210\2534", nullptr));
    groupBox_6->setTitle(QCoreApplication::translate("MangheWindow", "\345\217\243\345\221\263\343\200\201\345\217\243\346\204\237", nullptr));
    kouwei_1->setText(QCoreApplication::translate("MangheWindow", "\345\217\243\345\221\2631", nullptr));
    checkBox_12->setText(QCoreApplication::translate("MangheWindow", "\345\217\243\345\221\2632", nullptr));
    kouwei_3->setText(QCoreApplication::translate("MangheWindow", "\345\217\243\345\221\2633", nullptr));
    checkBox_14->setText(QCoreApplication::translate("MangheWindow", "\345\217\243\345\221\2634", nullptr));
    box_jikouyinshixianzhi->setTitle(QCoreApplication::translate("MangheWindow", "\345\277\214\345\217\243\343\200\201\351\245\256\351\243\237\351\231\220\345\210\266", nullptr));
    ditanshui->setText(QCoreApplication::translate("MangheWindow", "\344\275\216\347\242\263\346\260\264", nullptr));
    wujianguo->setText(QCoreApplication::translate("MangheWindow", "\346\227\240\345\235\232\346\236\234", nullptr));
    qvansu->setText(QCoreApplication::translate("MangheWindow", "\345\205\250\347\264\240", nullptr));
    checkBox_18->setText(QCoreApplication::translate("MangheWindow", "\344\275\216\347\263\226", nullptr));
    checkBox_16->setText(QCoreApplication::translate("MangheWindow", "\346\227\240\351\272\246\351\272\270", nullptr));
    qingzhen->setText(QCoreApplication::translate("MangheWindow", "\346\270\205\347\234\237", nullptr));
    wuxiangcai->setText(QCoreApplication::translate("MangheWindow", "\346\227\240\351\246\231\350\217\234", nullptr));
    diyou->setText(QCoreApplication::translate("MangheWindow", "\344\275\216\346\262\271", nullptr));
    checkBox_22->setText(QCoreApplication::translate("MangheWindow", "\346\227\240\344\271\263\345\210\266\345\223\201", nullptr));
    box_zhuyaochengfen->setTitle(QCoreApplication::translate("MangheWindow", "\344\270\273\350\246\201\346\210\220\345\210\206", nullptr));
    checkBox_23->setText(QCoreApplication::translate("MangheWindow", "\346\210\220\345\210\2061", nullptr));
    checkBox_24->setText(QCoreApplication::translate("MangheWindow", "\346\210\220\345\210\2062", nullptr));
    chengfen_3->setText(QCoreApplication::translate("MangheWindow", "\346\210\220\345\210\2063", nullptr));
    checkBox_26->setText(QCoreApplication::translate("MangheWindow", "\346\210\220\345\210\2064", nullptr));
} // retranslateUi

// 数字对应关系
// 0 位置（这个没用）
// 1 时段
// 2 菜系
// 3 菜品类别
// 4 主要成分
// 5 烹饪方法
// 6 口味、口感
// 7 忌口、饮食限制
void Ui_MangheWindow::getIdVector(){
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

    QSqlQuery query(db);
    QString sql0 = "SELECT id FROM tags WHERE type = 0";

    if (query.exec(sql0)) {
        while (query.next()) {
            int id = query.value(0).toInt();
            type0.append(id);
        }
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }


    QString sql1 = "SELECT id FROM tags WHERE type = 1";

    if (query.exec(sql1)) {
        while (query.next()) {
            int id = query.value(0).toInt();
            type1.append(id);
        }
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }


    QString sql2 = "SELECT id FROM tags WHERE type = 2";

    if (query.exec(sql2)) {
        while (query.next()) {
            int id = query.value(0).toInt();
            type2.append(id);
        }
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }


    QString sql3 = "SELECT id FROM tags WHERE type = 3";

    if (query.exec(sql3)) {
        while (query.next()) {
            int id = query.value(0).toInt();
            type3.append(id);
        }
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }


    QString sql4 = "SELECT id FROM tags WHERE type = 4";

    if (query.exec(sql4)) {
        while (query.next()) {
            int id = query.value(0).toInt();
            type4.append(id);
        }
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }


    QString sql5 = "SELECT id FROM tags WHERE type = 5";

    if (query.exec(sql5)) {
        while (query.next()) {
            int id = query.value(0).toInt();
            type5.append(id);
        }
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }


    QString sql6 = "SELECT id FROM tags WHERE type = 6";

    if (query.exec(sql6)) {
        while (query.next()) {
            int id = query.value(0).toInt();
            type6.append(id);
        }
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }


    QString sql7 = "SELECT id FROM tags WHERE type = 7";

    if (query.exec(sql7)) {
        while (query.next()) {
            int id = query.value(0).toInt();
            type7.append(id);
        }
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }

    // 暂且初始化一下
    for(int i=0;i<=2;i++)shiduan[i]=type1[i];
    for(int i=0;i<=1;i++)caixi[i]=type2[i];
    for(int i=0;i<=3;i++)caipinleibie[i]=type3[i];
    for(int i=0;i<=3;i++)zhuyaochengfen[i]=type4[i];
    for(int i=0;i<=3;i++)kouweikougan[i]=type6[i];
    for(int i=0;i<=8;i++)jikouyinshixianzhi[i]=type7[i];

    // 检查初始化是否成功
    // for(int id:type0)qDebug()<<id;
    // for(int id:type1)qDebug()<<id;
    // for(int id:type2)qDebug()<<id;
    // for(int id:type3)qDebug()<<id;
    // for(int id:type4)qDebug()<<id;
    // for(int id:type5)qDebug()<<id;
    // for(int id:type6)qDebug()<<id;
    // for(int id:type7)qDebug()<<id;
}

void Ui_MangheWindow::random_tags(){
    Ui_MangheWindow::random_caipinleibie();
    Ui_MangheWindow::random_zhuyaochengfen();
    Ui_MangheWindow::random_kouweikougan();

    int targetId = 1;

    targetId=caipinleibie[0];
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
    QSqlQuery query(db);
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                leibie_1->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }
    targetId=caipinleibie[1];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                leibie_2->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }
    targetId=caipinleibie[2];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                checkBox_8->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }
    targetId=caipinleibie[3];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                leibie_4->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }

    targetId=zhuyaochengfen[0];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                checkBox_23->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }
    targetId=zhuyaochengfen[1];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                checkBox_24->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }
    targetId=zhuyaochengfen[2];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                chengfen_3->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }
    targetId=zhuyaochengfen[3];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                checkBox_26->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }

    targetId=kouweikougan[0];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                kouwei_1->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }
    targetId=kouweikougan[1];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                checkBox_12->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }
    targetId=kouweikougan[2];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                kouwei_3->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }
    targetId=kouweikougan[3];
    if (query.prepare("SELECT name FROM tags WHERE id = :id")) {
        query.bindValue(":id", targetId);

        if (query.exec()) {
            if (query.next()) {
                QString name = query.value(0).toString();
                // qDebug() << "Name of id " << targetId << " is:" << name;
                checkBox_14->setText(name);
            } else {
                qDebug() << "No record found for id " << targetId;
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        qDebug() << "Database not open";
    }

}
void Ui_MangheWindow::random_caipinleibie(){
    QRandomGenerator randomGenerator(QTime::currentTime().msec());

    QVector<int> randomIndices;
    while (randomIndices.size() < 4) {
        int randomIndex = randomGenerator.generate() % type3.size();
        if (!randomIndices.contains(randomIndex)) {
            randomIndices.append(randomIndex);
        }
        if (randomIndices.size() > 4) {
            randomIndices.removeLast();
        }
    }

    QVector<int> randomNumbers;
    for (int index : randomIndices) {
        randomNumbers.append(type3[index]);
    }

    for(int i=0;i<=3;i++){
        caipinleibie[i]=randomNumbers[i];
        // qDebug()<<caipinleibie[i];
    }
}
void Ui_MangheWindow::random_zhuyaochengfen(){
    QRandomGenerator randomGenerator(QTime::currentTime().msec());

    QVector<int> randomIndices;
    while (randomIndices.size() < 4) {
        int randomIndex = randomGenerator.generate() % type4.size();
        if (!randomIndices.contains(randomIndex)) {
            randomIndices.append(randomIndex);
        }
        if (randomIndices.size() > 4) {
            randomIndices.removeLast();
        }
    }

    QVector<int> randomNumbers;
    for (int index : randomIndices) {
        randomNumbers.append(type4[index]);
    }

    for(int i=0;i<=3;i++){
        zhuyaochengfen[i]=randomNumbers[i];
        // qDebug()<<zhuyaochengfen[i];
    }
}
void Ui_MangheWindow::random_kouweikougan(){
    QRandomGenerator randomGenerator(QTime::currentTime().msec());

    QVector<int> randomIndices;
    while (randomIndices.size() < 4) {
        int randomIndex = randomGenerator.generate() % type6.size();
        if (!randomIndices.contains(randomIndex)) {
            randomIndices.append(randomIndex);
        }
        if (randomIndices.size() > 4) {
            randomIndices.removeLast();
        }
    }

    QVector<int> randomNumbers;
    for (int index : randomIndices) {
        randomNumbers.append(type6[index]);
    }

    for(int i=0;i<=3;i++){
        kouweikougan[i]=randomNumbers[i];
        // qDebug()<<kouweikougan[i];
    }
}

void Ui_MangheWindow::check_add_tag_1(){
    // qDebug()<<"1";
    selected_tags[num]=1;
    num++;
}
void Ui_MangheWindow::check_add_tag_2(){
    // qDebug()<<"2";
    selected_tags[num]=2;
    num++;
}
void Ui_MangheWindow::check_add_tag_3(){
    // qDebug()<<"3";
    selected_tags[num]=3;
    num++;
}
void Ui_MangheWindow::check_add_tag_4(){
    // qDebug()<<"4";
    selected_tags[num]=4;
    num++;
}
void Ui_MangheWindow::check_add_tag_5(){
    // qDebug()<<"5";
    selected_tags[num]=5;
    num++;
}
void Ui_MangheWindow::check_add_tag_6(){
    // qDebug()<<"6";
    selected_tags[num]=caipinleibie[0];
    num++;
}
void Ui_MangheWindow::check_add_tag_7(){
    // qDebug()<<"7";
    selected_tags[num]=caipinleibie[1];
    num++;
}
void Ui_MangheWindow::check_add_tag_8(){
    // qDebug()<<"8";
    selected_tags[num]=caipinleibie[2];
    num++;
}
void Ui_MangheWindow::check_add_tag_9(){
    // qDebug()<<"9";
    selected_tags[num]=caipinleibie[3];
    num++;
}
void Ui_MangheWindow::check_add_tag_10(){
    // qDebug()<<"10";
    selected_tags[num]=zhuyaochengfen[0];
    num++;
}
void Ui_MangheWindow::check_add_tag_11(){
    // qDebug()<<"11";
    selected_tags[num]=zhuyaochengfen[1];
    num++;
}
void Ui_MangheWindow::check_add_tag_12(){
    // qDebug()<<"12";
    selected_tags[num]=zhuyaochengfen[2];
    num++;
}
void Ui_MangheWindow::check_add_tag_13(){
    // qDebug()<<"13";
    selected_tags[num]=zhuyaochengfen[3];
    num++;
}
void Ui_MangheWindow::check_add_tag_14(){
    // qDebug()<<"14";
    selected_tags[num]=kouweikougan[0];
    num++;
}
void Ui_MangheWindow::check_add_tag_15(){
    // qDebug()<<"15";
    selected_tags[num]=kouweikougan[1];
    num++;
}
void Ui_MangheWindow::check_add_tag_16(){
    // qDebug()<<"16";
    selected_tags[num]=kouweikougan[2];
    num++;
}
void Ui_MangheWindow::check_add_tag_17(){
    // qDebug()<<"17";
    selected_tags[num]=kouweikougan[3];
    num++;
}
void Ui_MangheWindow::check_add_tag_18(){
    // qDebug()<<"18";
    selected_tags[num]=53;
    num++;
}
void Ui_MangheWindow::check_add_tag_19(){
    // qDebug()<<"19";
    selected_tags[num]=54;
    num++;
}
void Ui_MangheWindow::check_add_tag_20(){
    // qDebug()<<"20";
    selected_tags[num]=55;
    num++;
}
void Ui_MangheWindow::check_add_tag_21(){
    // qDebug()<<"21";
    selected_tags[num]=56;
    num++;
}
void Ui_MangheWindow::check_add_tag_22(){
    // qDebug()<<"22";
    selected_tags[num]=57;
    num++;
}
void Ui_MangheWindow::check_add_tag_23(){
    // qDebug()<<"23";
    selected_tags[num]=58;
    num++;
}
void Ui_MangheWindow::check_add_tag_24(){
    // qDebug()<<"24";
    selected_tags[num]=59;
    num++;
}
void Ui_MangheWindow::check_add_tag_25(){
    // qDebug()<<"25";
    selected_tags[num]=60;
    num++;
}
void Ui_MangheWindow::check_add_tag_26(){
    // qDebug()<<"26";
    selected_tags[num]=61;
    num++;
}

void Ui_MangheWindow::load_dishes(){
    if(num==0){
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
        QSqlQuery query(db);
        QString queryString = "SELECT * FROM dishes";

        if (query.exec(queryString)) {
            while (query.next()) {
                int id = query.value(0).toInt();
                selected_dishes[num_of_dishes]=id;
                num_of_dishes++;
            }
        } else {
            qDebug() << "Failed to execute query:" << query.lastError().text();
        }
        return;
    }

    else{
        QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
        if (!db.open()) {
            qDebug() << "Failed to open database:" << db.lastError().text();
            return;
        }

        QVector<int> selectedDishes;
        QSqlQuery query(db);

        for(int tagId:selected_tags){
            if((tagId>5&&tagId<=52)||(tagId>=62))
            {
                if (!query.exec(QString("SELECT dish_id FROM dish_tags WHERE tag_id = %1").arg(tagId))) {
                    continue;
                }
                else{
                    while (query.next()) {
                        int dishId = query.value(0).toInt();
                        // 将dish_id添加到数组中times次
                        int times=query.value(2).toInt();
                        for (int i = 0; i <=times-1;i++) {
                            selectedDishes.append(dishId);
                        }
                    }
                }
            }
        }//加入一些菜品，根据类别，成分，口味并集

        int num_of_jikou=0;
        int jikou[10];
        for(int tagId:selected_tags){
            if((tagId>=1&&tagId<=5)||(tagId>=53&&tagId<=61)){
                QString sql = QString("SELECT dish_id FROM dish_tags WHERE tag_id IS NULL");

                if (query.prepare(sql)) {
                    if (query.exec()) {
                        while (query.next()) {
                            int dishId = query.value(0).toInt();
                            selectedDishes.removeAll(dishId);
                        }
                    } else {
                        qDebug() << "Query failed:" << query.lastError();
                    }
                } else {
                    qDebug() << "Query preparation failed:" << query.lastError();
                }
            }
            else if((tagId>=53&&tagId<=61)){
                jikou[num_of_jikou]=tagId;
                num_of_jikou++;
            }
        }//根据时段，菜系，忌口删除一些菜品

        int size_of_vector=selectedDishes.size();
        for(int i=0;i<=size_of_vector-1;i++){
            selected_dishes[i]=selectedDishes[i];
        }
        num_of_dishes=size_of_vector;

        if(num_of_dishes==0){
            QString queryString = "SELECT * FROM dishes";

            if (query.exec(queryString)) {
                while (query.next()) {
                    int id = query.value(0).toInt();
                    selected_dishes[num_of_dishes]=id;
                    num_of_dishes++;
                }
            } else {
                qDebug() << "Failed to execute query:" << query.lastError().text();
            }
        }

        return;
    }
}

void Ui_MangheWindow::showDetail(const int& dish_id){
    //qDebug()<<"here"<<dish_id;
    DetailCard* card = new DetailCard(dish_id,1);
    this->hide();
    card->show();
}

void Ui_MangheWindow::generate_dish(){
    load_dishes();
    srand(time(0));
    int random_number = rand()%num_of_dishes;
    int res=selected_dishes[random_number];
    showDetail(res);//转到菜的detailcard
}

void Ui_MangheWindow::home(){
    this->close();
    Widget *w=new Widget();
    w->show();
}

