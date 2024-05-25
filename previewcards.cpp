#include "previewcards.h"
#include "ui_previewcards.h"
#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "detailcard.h"

PreviewCards::PreviewCards(int ids[6],int size,TujianWindow* tjparent,QWidget *parent)
    : QWidget(parent)
    , tjWindow(tjparent)
    , ui(new Ui::PreviewCards)
{
    ui->setupUi(this);

    QString stylesheet_red="QGroupBox{ border: 2px solid rgb(191, 40, 40);}";
    //QString stylesheet_white="QGroupBox{ border: 2px solid white;}";


    if(size>=1){
        ui->groupBox->setStyleSheet(stylesheet_red);
        ui->label->setCursor(Qt::PointingHandCursor);
        ui->label->setAlignment(Qt::AlignCenter);
        ui->pushButton->setCursor(Qt::PointingHandCursor);
    }
    if(size>=2){
        ui->groupBox_2->setStyleSheet(stylesheet_red);
        ui->label_2->setCursor(Qt::PointingHandCursor);
        ui->label_2->setAlignment(Qt::AlignCenter);
        ui->pushButton_2->setCursor(Qt::PointingHandCursor);
    }
    if(size>=3){
        ui->groupBox_3->setStyleSheet(stylesheet_red);
        ui->label_3->setCursor(Qt::PointingHandCursor);
        ui->label_3->setAlignment(Qt::AlignCenter);
        ui->pushButton_3->setCursor(Qt::PointingHandCursor);
    }
    if(size>=4){
        ui->groupBox_4->setStyleSheet(stylesheet_red);
        ui->label_4->setCursor(Qt::PointingHandCursor);
        ui->label_4->setAlignment(Qt::AlignCenter);
        ui->pushButton_4->setCursor(Qt::PointingHandCursor);
    }
    if(size>=5){
        ui->groupBox_5->setStyleSheet(stylesheet_red);
        ui->label_5->setCursor(Qt::PointingHandCursor);
        ui->label_5->setAlignment(Qt::AlignCenter);
        ui->pushButton_5->setCursor(Qt::PointingHandCursor);
    }
    if(size>=6){
        ui->groupBox_6->setStyleSheet(stylesheet_red);
        ui->label_6->setCursor(Qt::PointingHandCursor);
        ui->label_6->setAlignment(Qt::AlignCenter);
        ui->pushButton_6->setCursor(Qt::PointingHandCursor);
    }

    QVector<MessageButton*>buttons={ui->pushButton,ui->pushButton_2,ui->pushButton_3,ui->pushButton_4,ui->pushButton_5,ui->pushButton_6};
    QVector<QLabel*>labels={ui->label,ui->label_2,ui->label_3,ui->label_4,ui->label_5,ui->label_6};
    QVector<QString>btnPics;
    QVector<QString>lbTexts;

    for(int i=0;i<size;++i){
        QString sql=QString("SELECT name,file_location FROM dishes WHERE id=%1").arg(ids[i]);
        QSqlQuery queryA;
        if(!queryA.exec(sql)){
            qDebug()<<queryA.lastError().text();
        }
        if(queryA.next()){
            lbTexts.push_back(queryA.value("name").toString());
            btnPics.push_back(queryA.value("file_location").toString());
        }

    }

    //qDebug()<<lbTexts.size();
    //qDebug()<<btnPics.size();
    for(int i=0;i<size;++i){
        //qDebug()<<lbTexts[i];
        //qDebug()<<btnPics[i];
        buttons[i]->dish_id=ids[i];
        buttons[i]->setIcon(QIcon(btnPics[i]));
        connect(buttons[i],&MessageButton::sendId,this,&PreviewCards::showDetail);
        labels[i]->setText(lbTexts[i]);
    }

}

PreviewCards::~PreviewCards()
{
    delete ui;
}

void PreviewCards::showDetail(const int& dish_id){
    //qDebug()<<"here"<<dish_id;
    DetailCard* card = new DetailCard(dish_id,this->tjWindow);
    this->tjWindow->hide();
    card->show();
}
