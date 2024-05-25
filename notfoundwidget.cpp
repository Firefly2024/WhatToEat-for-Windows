#include "notfoundwidget.h"
#include "ui_notfoundwidget.h"

NotFoundWidget::NotFoundWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NotFoundWidget)
{
    ui->setupUi(this);
}

NotFoundWidget::~NotFoundWidget()
{
    delete ui;
}
