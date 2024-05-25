#include "manghe.h"
#include "ui_manghe.h"
#include "widget.h"

Manghe::Manghe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Manghe)
{
    ui->setupUi(this);
}

Manghe::~Manghe()
{
    delete ui;
}


void Manghe::on_returnmenu_clicked()
{
    Widget *menu=new Widget();
    this->close();
    menu->show();
} //返回主界面

