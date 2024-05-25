#include "tujianwindow.h"
#include "ui_tujianwindow.h"
#include "previewcards.h"
#include "adddialog.h"
#include "notfoundwidget.h"
#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QHBoxLayout>


TujianWindow::TujianWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TujianWindow)
{
    page=0;
    totalPage=0;
    searchMode=1;
    ui->setupUi(this);
    ui->statusbar->hide();

    int dishNums=0;

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
    query.prepare(QString("SELECT COUNT(*) FROM %1").arg("dishes"));

    if (!query.exec()) {
        qDebug() << "Error: Failed to execute query:" << query.lastError();
    }

    if (query.next()) {
        dishNums= query.value(0).toInt();
        //qDebug() << "Number of dishes:" << dishNums;
    }

    for(int i=1;i<=dishNums;i+=6){
        int a[6]={};
        int j=0;
        for(;j<6 && ((i+j)<=dishNums);++j){
            a[j]=i+j;
        }
        ui->stackedWidget->addWidget(new PreviewCards(a,j,this));
    }

    totalPage=ui->stackedWidget->count();

    ui->lbPage->setText(QString("%1/%2").arg(page+1).arg(totalPage));
    ui->lbPage->setStyleSheet("QLabel { color : rgb(208, 2, 27); }");
    ui->lbPage->setAlignment(Qt::AlignCenter);


    connect(ui->btnAdd,&QPushButton::clicked,this,&TujianWindow::addCards);
    connect(ui->btnTagSearch,&QPushButton::clicked,this,&TujianWindow::TabelModelOn);
    connect(ui->btnNameSearch,&QPushButton::clicked,this,&TujianWindow::NameModelOn);
    connect(ui->btnHome,&QPushButton::clicked,this,&TujianWindow::backward);

    this->NameModelOn();

}

TujianWindow::~TujianWindow()
{
    delete ui;
}

void TujianWindow::backward(){
    this->wparent->show();
    this->close();
}

TagButton::TagButton(const QString& text):QPushButton(text){
    this->setIcon(QIcon("://images/add.svg"));
    QString styleSheet="QPushButton{background:transparent;border:2px solid white;border-radius:10px;}\
                        QPushButton:hover{border:2px solid rgb(191, 40, 40);border-radius:10px;}";
    this->setStyleSheet(styleSheet);
    this->setCursor(Qt::PointingHandCursor);
    connect(this,&TagButton::clicked,this,&TagButton::clickedMessage);
}

TagButton::~TagButton(){}

void TagButton::clickedMessage()
{
    emit sendSelf(this);
}

void TujianWindow::selectTag(TagButton *target)
{
    selectedNames.push_back(target->text());
    selectedIds.push_back(target->tagId);
    this->updateLabelSearch(ui->searchLine->text());
    resetCards();
}

SelectedTagButton::SelectedTagButton(const QString &text):QPushButton(text)
{
    this->setIcon(QIcon("://images/minus.svg"));
    QString styleSheet="QPushButton{background:transparent;border:2px solid rgb(191, 40, 40);border-radius:10px;}";
    this->setStyleSheet(styleSheet);
    this->setCursor(Qt::PointingHandCursor);
    connect(this,&SelectedTagButton::clicked,this,&SelectedTagButton::clickedMessage);
}

SelectedTagButton::~SelectedTagButton(){}

QStringList splitChineseCharacters(const QString &input) {
    QStringList characters;
    for (const QChar &ch : input) {
        characters.append(ch);
    }
    return characters;
}

void SelectedTagButton::clickedMessage()
{
    emit sendIndex(this->index);
}

void TujianWindow::releaseTag(const int& idx)
{
    selectedNames.erase(selectedNames.begin()+idx);
    selectedIds.erase(selectedIds.begin()+idx);
    this->updateLabelSearch(ui->searchLine->text());
    resetCards();
}

void TujianWindow::NameModelOn()
{
    searchMode=1;
    ui->btnTagSearch->setStyleSheet("QPushButton{background:transparent;border:none;\
                border-radius: 10px;}QPushButton:hover{background:rgb(213, 215, 215);}");
    ui->btnNameSearch->setStyleSheet("QPushButton{background:transparent;border: 2px solid rgb(191, 40, 40);border-radius: 10px;}");
    disconnect(ui->searchLine,&QLineEdit::textChanged,this,&TujianWindow::updateLabelSearch);
    this->selectedIds.clear();
    this->selectedNames.clear();
    this->updateLabelSearch("");
    this->resetCards();
    connect(ui->searchLine,&QLineEdit::textChanged,this,&TujianWindow::resetCards);
    ui->btnTag->setIcon(QIcon());
}

void TujianWindow::TabelModelOn()
{
    searchMode=0;
    ui->btnNameSearch->setStyleSheet("QPushButton{background:transparent;border:none;\
                border-radius: 10px;}QPushButton:hover{background:rgb(213, 215, 215);}");
    ui->btnTagSearch->setStyleSheet("QPushButton{background:transparent;border: 2px solid rgb(191, 40, 40);border-radius: 10px;}");
    connect(ui->searchLine,&QLineEdit::textChanged,this,&TujianWindow::updateLabelSearch);
    this->updateLabelSearch(ui->searchLine->text());
    disconnect(ui->searchLine,&QLineEdit::textChanged,this,&TujianWindow::resetCards);
    ui->btnTag->setIcon(QIcon("://images/tag-one.svg"));
}

void TujianWindow::resetCards(){

    ui->btnLeft->setEnabled(true);
    ui->btnRight->setEnabled(true);

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

    while (ui->stackedWidget->count() > 0) {
        QWidget *widget = ui->stackedWidget->widget(0);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }


    if(searchMode==0){
        int dishNums=0;
        QSqlQuery query;
        query.prepare(QString("SELECT COUNT(*) FROM %1").arg("dishes"));

        if (!query.exec()) {
            qDebug() << "Error: Failed to execute query:" << query.lastError();
        }

        if (query.next()) {
            dishNums= query.value(0).toInt();
        }
        qDebug()<<"dishNums:"<<dishNums;

        if(this->selectedIds.empty()){
            for(int i=1;i<=dishNums;i+=6){
                int a[6]={};
                int j=0;
                for(;j<6 && ((i+j)<=dishNums);++j){
                    a[j]=i+j;
                }
                //qDebug()<<"called";
                ui->stackedWidget->addWidget(new PreviewCards(a,j,this));
            }
        }else{
            int tagsSize=this->selectedIds.size();
            QStringList placeholders;
            QVector<int>dishIds;
            for (int i = 0; i < tagsSize; ++i) {
                placeholders << "?";
            }
            QString queryStr = QString(
                                   "SELECT dish_id, SUM(times) as total_times "
                                   "FROM dish_tags "
                                   "WHERE tag_id IN (%1) "
                                   "GROUP BY dish_id "
                                   "HAVING COUNT(DISTINCT tag_id) = %2 "
                                   "ORDER BY total_times DESC"
                                   ).arg(placeholders.join(", "))
                                   .arg(tagsSize);

            QSqlQuery query;
            query.prepare(queryStr);
            for (int i = 0; i < tagsSize; ++i) {
                query.addBindValue(this->selectedIds[i]);
            }

            if (query.exec()) {
                while (query.next()) {
                    int dishId = query.value(0).toInt();
                    dishIds.push_back(dishId);
                    //int totalTimes = query.value(1).toInt();
                    //qDebug() << "Dish ID:" << dishId << "Total Times:" << totalTimes;
                }
            } else {
                qDebug() << "Query error:" << query.lastError().text();
            }

            dishNums=dishIds.size();
            for(int i=0;i<dishNums;i+=6){
                int a[6]={};
                int j=0;
                for(;j<6 && ((i+j)<dishNums);++j){
                    a[j]=dishIds[i+j];
                }
                ui->stackedWidget->addWidget(new PreviewCards(a,j,this));
            }
        }
    }else if(searchMode==1){//名称搜索模式

        // 拆分输入字符串成单个汉字
        //QStringList characters = splitChineseCharacters(ui->searchLine->text());

        // 动态构建查询
        // QString queryStr = "SELECT id, name, (";
        // QStringList conditions;

        // for (const QString &ch : characters) {
        //     conditions.append(QString("LENGTH(name) - LENGTH(REPLACE(name, '%1', ''))").arg(ch));
        // }

        // queryStr += conditions.join(" + ");
        // queryStr += ") AS match_count FROM dishes WHERE match_count>0 ORDER BY match_count DESC";

        //qDebug()<<queryStr;

        QSqlQuery query;

        query.prepare("SELECT id FROM dishes WHERE name LIKE ?");
        query.addBindValue("%" + ui->searchLine->text() + "%");
        if (!query.exec()) {
            qDebug() << "Failed to execute query:" << query.lastError().text();
            return;
        }
        QVector<int>dishIds;
        while (query.next()) {
            int dishId=query.value(0).toInt();
            dishIds.push_back(dishId);
        }
        int dishNums=dishIds.size();
        for(int i=0;i<dishNums;i+=6){
            int a[6]={};
            int j=0;
            for(;j<6 && ((i+j)<dishNums);++j){
                a[j]=dishIds[i+j];
            }
            ui->stackedWidget->addWidget(new PreviewCards(a,j,this));
        }
    }

    totalPage=ui->stackedWidget->count();
    if(totalPage==0){
        ui->stackedWidget->addWidget(new NotFoundWidget());
        ui->lbPage->setText("");
        ui->btnLeft->setEnabled(false);
        ui->btnRight->setEnabled(false);
    }else{
        if(page>=totalPage){
            page=totalPage-1;
        }
        ui->stackedWidget->setCurrentIndex(page);
        ui->lbPage->setText(QString("%1/%2").arg(page+1).arg(totalPage));
    }
    db.close();
}


void TujianWindow::addCards()
{
    AddDialog* dialog = new AddDialog;
    dialog->show();
    connect(dialog,&AddDialog::addDone,this,&TujianWindow::resetCards);

}

void TujianWindow::on_btnRight_clicked()
{
    if(page==totalPage-1)return;
    page++;
    ui->stackedWidget->setCurrentIndex(page);
    ui->lbPage->setText(QString("%1/%2").arg(page+1).arg(totalPage));
}

void TujianWindow::on_btnLeft_clicked()
{
    if(page==0)return;
    page--;
    ui->stackedWidget->setCurrentIndex(page);
    ui->lbPage->setAlignment(Qt::AlignCenter);
    ui->lbPage->setText(QString("%1/%2").arg(page+1).arg(totalPage));
}



void TujianWindow::updateLabelSearch(const QString& text){

    QWidget *contentWidget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(contentWidget);

    int cnt=0;
    for(QString& name:selectedNames){
        SelectedTagButton* btnSelected=new SelectedTagButton(name);
        btnSelected->index=cnt;
        connect(btnSelected,&SelectedTagButton::sendIndex,this,&TujianWindow::releaseTag);
        layout->addWidget(btnSelected);
        cnt++;
    }

    if(text!=""){
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

        // 拆分输入字符串成单个汉字
        QStringList characters = splitChineseCharacters(text);

        // 动态构建查询
        QString queryStr = "SELECT id, name, (";
        QStringList conditions;

        for (const QString &ch : characters) {
            conditions.append(QString("LENGTH(name) - LENGTH(REPLACE(name, '%1', ''))").arg(ch));
        }

        queryStr += conditions.join(" + ");
        queryStr += ") AS match_count FROM tags WHERE match_count>0 ORDER BY match_count DESC";


        //qDebug()<<queryStr;

        QSqlQuery query;
        if (!query.exec(queryStr)) {
            qDebug()<<"here";
            qDebug() << "Failed to execute query:" << query.lastError().text();
            return;
        }

        while (query.next()) {
            int tagId=query.value(0).toInt();
            QString tagName = query.value(1).toString();
            int flag=0;
            for(int tmp:selectedIds){
                if(tmp==tagId){
                    flag=1;
                    break;
                }
            }
            if(flag==1)continue;
            //int matchCount = query.value(2).toInt();
            //qDebug() << "Tag:" << tagName << "Match Count:" << matchCount;
            //QPushButton *btn = new QPushButton(tagName);
            TagButton *btn = new TagButton(tagName);
            btn->tagId=tagId;
            connect(btn,&TagButton::sendSelf,this,&TujianWindow::selectTag);
            layout->addWidget(btn);
        }
    }

    layout->addStretch();

    contentWidget->setLayout(layout);
    ui->SearchTagsArea->setWidget(contentWidget);

}




