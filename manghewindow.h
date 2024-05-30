/********************************************************************************
** Form generated from reading UI file 'manghewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MANGHEWINDOW_H
#define MANGHEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <QDebug>
#include "QtWidgets/qpushbutton.h"
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QApplication>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <detailcard.h>
#include <messagebutton.h>

class Ui_MangheWindow:public QMainWindow
{
public:
    QWidget *centralwidget;
    QLabel *lable_1_tishiyv;
    QPushButton *generate;
    QPushButton *btnHome;
    QPushButton *change;
    QGroupBox *box_shiduan;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_shiduan;
    QCheckBox *zaocan;
    QCheckBox *checkBox_2;
    QCheckBox *wancan;
    QGroupBox *box_caixi;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *xican;
    QCheckBox *checkBox_4;
    QGroupBox *box_caipinleibie;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_caipinleibie;
    QCheckBox *leibie_1;
    QCheckBox *leibie_2;
    QCheckBox *checkBox_8;
    QCheckBox *leibie_4;
    QGroupBox *groupBox_6;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *kouwei_1;
    QCheckBox *checkBox_12;
    QCheckBox *kouwei_3;
    QCheckBox *checkBox_14;
    QGroupBox *box_jikouyinshixianzhi;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_jikouyinshixianzhi;
    QCheckBox *ditanshui;
    QCheckBox *wujianguo;
    QCheckBox *qvansu;
    QCheckBox *checkBox_18;
    QCheckBox *checkBox_16;
    QCheckBox *qingzhen;
    QCheckBox *wuxiangcai;
    QCheckBox *diyou;
    QCheckBox *checkBox_22;
    QGroupBox *box_zhuyaochengfen;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_23;
    QCheckBox *checkBox_24;
    QCheckBox *chengfen_3;
    QCheckBox *checkBox_26;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QWidget *wparent;


    explicit Ui_MangheWindow(QWidget *parent=nullptr)
        : QMainWindow(parent){
        ui=this;
        ui->setupUi(this);
        wparent=parent;

        //不小心把两个button名字写错了
        QPushButton *t;
        t=change;
        change=generate;
        generate=t;
        connect(change, &QPushButton::clicked, this, &Ui_MangheWindow::random_tags);
        connect(generate, &QPushButton::clicked, this, &Ui_MangheWindow::generate_dish);

        connect(zaocan,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_1);
        connect(checkBox_2,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_2);
        connect(wancan,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_3);
        connect(xican,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_4);
        connect(checkBox_4,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_5);
        connect(leibie_1,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_6);
        connect(leibie_2,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_7);
        connect(checkBox_8,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_8);
        connect(leibie_4,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_9);
        connect(checkBox_23,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_10);
        connect(checkBox_24,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_11);
        connect(chengfen_3,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_12);
        connect(checkBox_26,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_13);
        connect(kouwei_1,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_14);
        connect(checkBox_12,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_15);
        connect(kouwei_3,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_16);
        connect(checkBox_14,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_17);
        connect(qvansu,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_18);
        connect(qingzhen,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_19);
        connect(wuxiangcai,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_20);
        connect(ditanshui,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_21);
        connect(checkBox_18,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_22);
        connect(diyou,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_23);
        connect(checkBox_16,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_24);
        connect(wujianguo,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_25);
        connect(checkBox_22,&QCheckBox::clicked,this,&Ui_MangheWindow::check_add_tag_26);

        connect(btnHome, &QPushButton::clicked, this, &Ui_MangheWindow::home);
    }
    ~Ui_MangheWindow(){
        delete ui;
    }

    void setupUi(QMainWindow *MangheWindow);
    void retranslateUi(QMainWindow *MangheWindow);

public:
    QVector<int> type0,type1,type2,type3,type4,type5,type6,type7;
    void getIdVector();
    int shiduan[3],caixi[2],caipinleibie[4],zhuyaochengfen[4],kouweikougan[4],jikouyinshixianzhi[9];
    void random_tags();
    void random_caipinleibie();
    void random_zhuyaochengfen();
    void random_kouweikougan();
    int num=0;
    int selected_tags[100];
    void check_add_tag_1();
    void check_add_tag_2();
    void check_add_tag_3();
    void check_add_tag_4();
    void check_add_tag_5();
    void check_add_tag_6();
    void check_add_tag_7();
    void check_add_tag_8();
    void check_add_tag_9();
    void check_add_tag_10();
    void check_add_tag_11();
    void check_add_tag_12();
    void check_add_tag_13();
    void check_add_tag_14();
    void check_add_tag_15();
    void check_add_tag_16();
    void check_add_tag_17();
    void check_add_tag_18();
    void check_add_tag_19();
    void check_add_tag_20();
    void check_add_tag_21();
    void check_add_tag_22();
    void check_add_tag_23();
    void check_add_tag_24();
    void check_add_tag_25();
    void check_add_tag_26();
    int num_of_dishes=0;
    int selected_dishes[10000];
    void load_dishes();
    void generate_dish();

    void home();

private slots:
    void showDetail(const int &dish_id);

private:
    Ui_MangheWindow *ui;
};

namespace Ui {
    class Ui_MangheWindow;
} // namespace Ui

#endif // MANGHEWINDOW_H
