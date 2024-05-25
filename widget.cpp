#include "widget.h"
#include "ui_widget.h"
#include "tujianwindow.h"
//#include "manghe.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pixmap = QPixmap("://images/home page.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(), QBrush(pixmap));
    this->setPalette(palette); //设置背景图片

    connect(ui->startmh,&QPushButton::clicked,this,&Widget::turntomh); //盲盒模式开始按钮槽
    connect(ui->starttj,&QPushButton::clicked,this,&Widget::turntotj); //图鉴模式开始按钮槽
}

Widget::~Widget()
{
    delete ui;
}

void Widget::turntomh()
{
    // Manghe *mh=new Manghe();
    // this->close();
    // mh->show();
} //盲盒模式槽连接函数

void Widget::turntotj()
{
    TujianWindow* tj=new TujianWindow();
    tj->wparent=this;
    this->hide();
    tj->show();
} //图鉴模式槽连接函数
