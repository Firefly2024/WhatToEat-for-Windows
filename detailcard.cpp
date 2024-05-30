#include "detailcard.h"
#include "ui_detailcard.h"
#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "morethingmenu.h"
#include <manghewindow.h>

DetailCard::DetailCard(const int& _dish_id,int _mode,TujianWindow* _tjparent,QWidget *parent)
    : QWidget(parent)
    ,tjWindow(_tjparent)
    , ui(new Ui::DetailCard)
    ,model(new QStandardItemModel())
    ,dish_id(_dish_id)
{
    mode=_mode;

    ui->setupUi(this);
    this->setWindowTitle("");

    setWindowFlags(Qt::CustomizeWindowHint |
                   Qt::WindowMinimizeButtonHint );

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

    int rating=0;
    QSqlQuery query;
    QString sql=QString("SELECT name, place, rating, price, file_location FROM dishes WHERE id = %1").arg(this->dish_id);
    if(query.exec(sql)){
        qDebug()<<query.lastError().text();
    }
    if(query.next()){
        ui->lbName->setText(query.value(0).toString());
        ui->lb_Place->setText("坐标:   "+query.value(1).toString());
        rating=query.value(2).toInt();
        double price=query.value(3).toDouble();
        ui->lbPrice->setText(QString::number(price)+" ¥");
        ui->btnPhoto->setIcon(QIcon(query.value(4).toString()));
    }
    if(rating>=1){
        ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    }
    if(rating>=2){
        ui->btnStar2->setIcon(QIcon("://images/star (full).svg"));
    }
    if(rating>=3){
        ui->btnStar3->setIcon(QIcon("://images/star (full).svg"));
    }
    if(rating>=4){
        ui->btnStar4->setIcon(QIcon("://images/star (full).svg"));
    }
    if(rating>=5){
        ui->btnStar5->setIcon(QIcon("://images/star (full).svg"));
    }

    QVector<int>tag_ids;
    sql=QString("SELECT tag_id FROM dish_tags WHERE dish_id = %1 AND tag_id >= 19 ORDER BY times DESC LIMIT 3").arg(dish_id);
    if(!query.exec(sql)){
        qDebug()<<query.lastError().text();
    }
    while(query.next()){
        tag_ids.push_back(query.value(0).toInt());
        //qDebug()<<queryA.value("file_location").toString();
    }
    //qDebug()<<tag_ids.size();
    QString queryString = "SELECT name FROM tags WHERE id IN (";
    for (int i = 0; i < tag_ids.size(); ++i) {
        queryString += (i == 0 ? "?" : ", ?");
    }
    queryString += ")";
    //qDebug()<<queryString;

    query.prepare(queryString);

    // 绑定参数
    for (int tag_id:tag_ids) {
        query.addBindValue(tag_id);
    }
    if (!query.exec()) {
        qDebug() << "Error: Failed to execute query - " << query.lastError();
    }

    // 处理查询结果
    QVector<QString>tags;
    while (query.next()) {
        QString name = query.value(0).toString();
        tags.push_back(name);
    }
    int size=tags.size();
    if(size>=1){
        ui->lbTag_1->setText(tags[0]);
    }
    if(size>=2){
        ui->lbTag_2->setText(tags[1]);
    }
    if(size>=3){
        ui->lbTag_3->setText(tags[2]);
    }

    queryString=QString("SELECT comment FROM dish_comments WHERE dish_id = %1 ORDER BY times DESC LIMIT 1").arg(this->dish_id);
    if(!query.exec(queryString)){
        qDebug() << "Error: Failed to execute query - " << query.lastError();
    }
    if(query.next()){
        ui->lbComments->setText("“ "+query.value(0).toString()+" ”");
    }

    connect(ui->btnMore,&QPushButton::clicked,this,&DetailCard::moreThings);
    connect(ui->btnBack,&QPushButton::clicked,this,&DetailCard::backward);
}

DetailCard::~DetailCard()
{
    delete ui;
}

void DetailCard::reset(){

    qDebug()<<"reset";
    int rating=0;
    QSqlQuery query;
    QString sql=QString("SELECT name, place, rating, price, file_location FROM dishes WHERE id = %1").arg(this->dish_id);
    if(query.exec(sql)){
        qDebug()<<query.lastError().text();
    }
    if(query.next()){
        ui->lbName->setText(query.value(0).toString());
        ui->lb_Place->setText("坐标:   "+query.value(1).toString());
        rating=query.value(2).toInt();
        double price=query.value(3).toDouble();
        ui->lbPrice->setText(QString::number(price)+" ¥");
        ui->btnPhoto->setIcon(QIcon(query.value(4).toString()));
    }
    if(rating>=1){
        ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    }else{
        ui->btnStar1->setIcon(QIcon("://images/star.svg"));
    }
    if(rating>=2){
        ui->btnStar2->setIcon(QIcon("://images/star (full).svg"));
    }else{
        ui->btnStar2->setIcon(QIcon("://images/star.svg"));
    }
    if(rating>=3){
        ui->btnStar3->setIcon(QIcon("://images/star (full).svg"));
    }else{
        ui->btnStar3->setIcon(QIcon("://images/star.svg"));
    }
    if(rating>=4){
        ui->btnStar4->setIcon(QIcon("://images/star (full).svg"));
    }else{
        ui->btnStar4->setIcon(QIcon("://images/star.svg"));
    }
    if(rating>=5){
        ui->btnStar5->setIcon(QIcon("://images/star (full).svg"));
    }else{
        ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    }

    QVector<int>tag_ids;
    sql=QString("SELECT tag_id FROM dish_tags WHERE dish_id = %1 AND tag_id >= 19 ORDER BY times DESC LIMIT 3").arg(dish_id);
    if(!query.exec(sql)){
        qDebug()<<query.lastError().text();
    }
    while(query.next()){
        tag_ids.push_back(query.value(0).toInt());
        //qDebug()<<queryA.value("file_location").toString();
    }
    //qDebug()<<tag_ids.size();
    QString queryString = "SELECT name FROM tags WHERE id IN (";
    for (int i = 0; i < tag_ids.size(); ++i) {
        queryString += (i == 0 ? "?" : ", ?");
    }
    queryString += ")";
    //qDebug()<<queryString;

    query.prepare(queryString);

    // 绑定参数
    for (int tag_id:tag_ids) {
        query.addBindValue(tag_id);
    }
    if (!query.exec()) {
        qDebug() << "Error: Failed to execute query - " << query.lastError();
    }

    // 处理查询结果
    QVector<QString>tags;
    while (query.next()) {
        QString name = query.value(0).toString();
        tags.push_back(name);
    }
    int size=tags.size();
    if(size>=1){
        ui->lbTag_1->setText(tags[0]);
    }
    if(size>=2){
        ui->lbTag_2->setText(tags[1]);
    }
    if(size>=3){
        ui->lbTag_3->setText(tags[2]);
    }

    queryString=QString("SELECT comment FROM dish_comments WHERE dish_id = %1 ORDER BY times DESC LIMIT 1").arg(this->dish_id);
    if(!query.exec(queryString)){
        qDebug() << "Error: Failed to execute query - " << query.lastError();
    }
    if(query.next()){
        ui->lbComments->setText("“ "+query.value(0).toString()+" ”");
    }
}

void DetailCard::moreThings(){
    MoreThingMenu* menu = new MoreThingMenu(this->dish_id,this);
    menu->show();
    //menu->setGeometry()
}

void DetailCard::backward(){
    if(mode==0){
        tjWindow->show();
        this->close();
    }
    else if(mode==1){
        Ui_MangheWindow* mh=new Ui_MangheWindow(this);
        mh->wparent=this;
        this->close();
        mh->show();
    }
}
