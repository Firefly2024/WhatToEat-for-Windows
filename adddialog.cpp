#include "adddialog.h"
#include "ui_adddialog.h"
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>


AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent)
    ,scores(0)
    , ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    ui->line_otherType->setText("");
    ui->line_otherFlavor->setText("");
    connect(ui->btnSelectPhoto,SIGNAL(clicked()),this,SLOT(selectFile()));
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&AddDialog::addActions);
    connect(ui->btnStar1,&QPushButton::clicked,this,&AddDialog::starOne);
    connect(ui->btnStar2,&QPushButton::clicked,this,&AddDialog::starTwo);
    connect(ui->btnStar3,&QPushButton::clicked,this,&AddDialog::starThree);
    connect(ui->btnStar4,&QPushButton::clicked,this,&AddDialog::starFour);
    connect(ui->btnStar5,&QPushButton::clicked,this,&AddDialog::starFive);
    connect(ui->btnStar1,&StarButton::enterEvent_1,this,&AddDialog::starOne);
    //connect(ui->btnStar1,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    connect(ui->btnStar2,&StarButton::enterEvent_1,this,&AddDialog::starTwo);
    //connect(ui->btnStar2,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    connect(ui->btnStar3,&StarButton::enterEvent_1,this,&AddDialog::starThree);
    //connect(ui->btnStar3,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    connect(ui->btnStar4,&StarButton::enterEvent_1,this,&AddDialog::starFour);
    //connect(ui->btnStar4,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    connect(ui->btnStar5,&StarButton::enterEvent_1,this,&AddDialog::starFive);
    //connect(ui->btnStar5,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    connect(ui->btnStar1,&QPushButton::clicked,this,&AddDialog::Selecteddisconnect);
    connect(ui->btnStar2,&QPushButton::clicked,this,&AddDialog::Selecteddisconnect);
    connect(ui->btnStar3,&QPushButton::clicked,this,&AddDialog::Selecteddisconnect);
    connect(ui->btnStar4,&QPushButton::clicked,this,&AddDialog::Selecteddisconnect);
    connect(ui->btnStar5,&QPushButton::clicked,this,&AddDialog::Selecteddisconnect);


}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::selectFile()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,                      // 父窗口
        "选择图片文件",            // 对话框标题
        "",                        // 起始目录，空字符串表示默认目录
        "图片文件 (*.png *.jpg *.jpeg *.bmp);;所有文件 (*.*)"  // 文件类型过滤器
        );

    // 检查用户是否选择了文件
    if (!fileName.isEmpty()) {
        // 如果选择了文件，则存储在ui->line_photofile文本框里
        ui->line_photofile->setText(fileName);
    }
}


bool copyImageFile(const QString &sourcePath, const QString &destinationPath) {
    QFile sourceFile(sourcePath);
    QFile destinationFile(destinationPath);

    if (!sourceFile.exists()) {
        qDebug() << "Source file does not exist.";
        return false;
    }

    if (!destinationFile.open(QIODevice::WriteOnly)) {
        qDebug() << "Could not open destination file for writing.";
        return false;
    }

    if (!sourceFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open source file for reading.";
        destinationFile.close();
        return false;
    }

    destinationFile.write(sourceFile.readAll());
    sourceFile.close();
    destinationFile.close();
    return true;
}


void addDish(const QString &name, const QString &fileLocation, int rating, double price,const QString &place) {


    QSqlQuery query;
    query.prepare("INSERT INTO dishes (name, file_location, rating, price, place) VALUES (:name, :file_location, :rating, :price, :place)");
    query.bindValue(":name", name);
    query.bindValue(":file_location", fileLocation);
    query.bindValue(":rating", rating);
    query.bindValue(":price",price);
    query.bindValue(":place",place);

    if (!query.exec()) {
        qDebug() << "Failed to add dish:" << query.lastError().text();
    }

}

void addTag(const QString &tagName,const int type=0) {

    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO tags (name,type) VALUES (:name,:type)");
    query.bindValue(":name", tagName);
    query.bindValue(":type", type);

    if (!query.exec()) {
        qDebug() << "Failed to add tag:" << query.lastError().text();
    }
}//这个地方要改

int getIdByName(const QString &tableName, const QString &name) {
    QSqlQuery query;
    query.prepare(QString("SELECT id FROM %1 WHERE name = :name").arg(tableName));
    query.bindValue(":name", name);

    if (query.exec()) {
        if (query.next()) {
            return query.value(0).toInt();
        } else {
            qDebug() << "No ID found for name:" << name;
            return -1;
        }
    } else {
        qDebug() << "Failed to execute query:" << query.lastError().text();
        return -1;
    }
}

void addDishTagRelation(const QString &dishName, const QString &tagName) {

    int dishId = getIdByName("dishes", dishName);
    int tagId = getIdByName("tags", tagName);
    // qDebug() <<dishId<<" "<<tagId;

    if (dishId == -1 || tagId == -1) {
        qDebug() << "Invalid dish or tag ID";
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO dish_tags (dish_id, tag_id, times) VALUES (:dish_id, :tag_id, :times)");
    query.bindValue(":dish_id", dishId);
    query.bindValue(":tag_id", tagId);
    query.bindValue(":times",1);

    if (!query.exec()) {
        qDebug() << "Failed to add dish-tag relation:" << query.lastError().text();
    } else {
        qDebug() << "Dish-tag relation added successfully!";
    }

}

void AddDialog::addActions()
{
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

    QString name,sourcePath,place;
    int rating;
    double price;

    name=ui->lineName->text();
    if(name==""){
        return;
    }
    sourcePath=ui->line_photofile->text();
    if(sourcePath==""){
        return;
    }
    place=ui->line_place->text();
    if(place==""){
        return;
    }
    rating=scores;
    if(ui->linePrice->text().toDouble()){
        price=ui->linePrice->text().toDouble();
    }else{
        return;
    }

    addDish(name,sourcePath,rating,price,place);

    if(place.startsWith(QString("家"))){
        addDishTagRelation(name,"家园");
    }
    else if(place.startsWith(QString("学一"))){
        addDishTagRelation(name,"学一");
    }
    else if(place.startsWith(QString("学五"))){
        addDishTagRelation(name,"学一");
    }
    else if(place.startsWith(QString("燕"))){
        addDishTagRelation(name,"燕南");
    }
    else if(place.startsWith(QString("农"))){
        addDishTagRelation(name,"农园");
    }

    if(ui->line_otherType->text()!=""){
        addTag(ui->line_otherType->text(),3);
        addDishTagRelation(name,ui->line_otherType->text());
    }

    if(ui->line_otherFlavor->text()!=""){
        addTag(ui->line_otherFlavor->text(),4);
        addDishTagRelation(name,ui->line_otherFlavor->text());
    }
    if(ui->line_material->text()!=""){
        addTag(ui->line_material->text(),5);
        addDishTagRelation(name,ui->line_material->text());
    }
    if(ui->rbOtherMethod->isChecked() && ui->line_method->text()!=""){
        addTag(ui->line_method->text(),6);
        addDishTagRelation(name,ui->line_method->text());
    }

    if(ui->cbAverage->isChecked()){
        addDishTagRelation(name,"平衡");
    }
    if(ui->cbBeef->isChecked()){
        addDishTagRelation(name,"牛肉");
    }
    if(ui->cbBitter->isChecked()){
        addDishTagRelation(name,"苦");
    }
    if(ui->cbChicken->isChecked()){
        addDishTagRelation(name,"鸡肉");
    }
    if(ui->cbCui->isChecked()){
        addDishTagRelation(name,"脆");
    }
    if(ui->cbDessert->isChecked()){
        addDishTagRelation(name,"甜点");
    }
    if(ui->cbDrinks->isChecked()){
        addDishTagRelation(name,"饮料");
    }
    if(ui->cbEgg->isChecked()){
        addDishTagRelation(name,"鸡蛋");
    }
    if(ui->cbFish->isChecked()){
        addDishTagRelation(name,"鱼");
    }
    if(ui->cbFresh->isChecked()){
        addDishTagRelation(name,"鲜");
    }
    if(ui->cbHua->isChecked()){
        addDishTagRelation(name,"滑");
    }
    if(ui->cbLan->isChecked()){
        addDishTagRelation(name,"软烂");
    }
    if(ui->cbLight->isChecked()){
        addDishTagRelation(name,"清淡");
    }
    if(ui->cbLowOil->isChecked()){
        addDishTagRelation(name,"低油");
    }
    if(ui->cbLowSuger->isChecked()){
        addDishTagRelation(name,"低糖");
    }
    if(ui->cbLowTanshui->isChecked()){
        addDishTagRelation(name,"低碳水");
    }
    if(ui->cbMaindish->isChecked()){
        addDishTagRelation(name,"主菜");
    }
    if(ui->cbMian->isChecked()){
        addDishTagRelation(name,"绵");
    }
    if(ui->cbMushroom->isChecked()){
        addDishTagRelation(name,"蘑菇");
    }
    if(ui->cbNen->isChecked()){
        addDishTagRelation(name,"嫩");
    }
    if(ui->cbNoMaifu->isChecked()){
        addDishTagRelation(name,"无麦麸");
    }
    if(ui->cbNoMilk->isChecked()){
        addDishTagRelation(name,"无乳制品");
    }
    if(ui->cbNoNut->isChecked()){
        addDishTagRelation(name,"无坚果");
    }
    if(ui->cbNoXiangcai->isChecked()){
        addDishTagRelation(name,"无香菜");
    }
    if(ui->cbNoodle->isChecked()){
        addDishTagRelation(name,"面");
    }
    if(ui->cbNuo->isChecked()){
        addDishTagRelation(name,"糯");
    }
    if(ui->cbPork->isChecked()){
        addDishTagRelation(name,"猪肉");
    }
    if(ui->cbQingzhen->isChecked()){
        addDishTagRelation(name,"清真");
    }
    if(ui->cbRice->isChecked()){
        addDishTagRelation(name,"米");
    }
    if(ui->cbRich->isChecked()){
        addDishTagRelation(name,"浓郁");
    }
    if(ui->cbRuan->isChecked()){
        addDishTagRelation(name,"软");
    }
    if(ui->cbSalty->isChecked()){
        addDishTagRelation(name,"咸");
    }
    if(ui->cbSeafood->isChecked()){
        addDishTagRelation(name,"海鲜");
    }
    if(ui->cbShuang->isChecked()){
        addDishTagRelation(name,"爽");
    }
    if(ui->cbSnack->isChecked()){
        addDishTagRelation(name,"小吃");
    }
    if(ui->cbSong->isChecked()){
        addDishTagRelation(name,"松");
    }
    if(ui->cbSoup->isChecked()){
        addDishTagRelation(name,"汤");
    }
    if(ui->cbSour->isChecked()){
        addDishTagRelation(name,"酸");
    }
    if(ui->cbSpicy->isChecked()){
        addDishTagRelation(name,"辣");
    }
    if(ui->cbStaple->isChecked()){
        addDishTagRelation(name,"主食");
    }
    if(ui->cbSu->isChecked()){
        addDishTagRelation(name,"酥");
    }
    if(ui->cbSweet->isChecked()){
        addDishTagRelation(name,"甜");
    }
    if(ui->cbToufu->isChecked()){
        addDishTagRelation(name,"豆腐");
    }
    if(ui->cbVegt->isChecked()){
        addDishTagRelation(name,"全素");
    }
    if(ui->chbkDinner->isChecked()){
        addDishTagRelation(name,"晚餐");
    }
    if(ui->chbxBreakfast->isChecked()){
        addDishTagRelation(name,"早餐");
    }
    if(ui->chbxLunch->isChecked()){
        addDishTagRelation(name,"午餐");
    }
    if(ui->rbChinese->isChecked()){
        addDishTagRelation(name,"中餐");
    }
    if(ui->rbDun->isChecked()){
        addDishTagRelation(name,"炖");
    }
    if(ui->rbJian->isChecked()){
        addDishTagRelation(name,"煎");
    }
    if(ui->rbKao->isChecked()){
        addDishTagRelation(name,"烤");
    }
    if(ui->rbWestern->isChecked()){
        addDishTagRelation(name,"西餐");
    }
    if(ui->rbXun->isChecked()){
        addDishTagRelation(name,"熏");
    }
    if(ui->rbZha->isChecked()){
        addDishTagRelation(name,"炸");
    }
    if(ui->rbZheng->isChecked()){
        addDishTagRelation(name,"蒸");
    }
    if(ui->rbZhu->isChecked()){
        addDishTagRelation(name,"煮");
    }


    // QString sourcePath = ui->line_photofile->text();
    // QFileInfo fileInfo(sourcePath);
    // QString extension = fileInfo.suffix();

    // QString baseString = "item_%1.";
    // int itemNum=0;

    // QSqlQuery query;
    // query.prepare(QString("SELECT COUNT(*) FROM %1").arg("dishes"));

    // if (!query.exec()) {
    //     qDebug() << "Error: Failed to execute query:" << query.lastError();
    // }

    // if (query.next()) {
    //     itemNum= query.value(0).toInt();
    // }

    // QString incrementedString = baseString.arg(itemNum);


    // QString destinationPath = "/Users/zhangjiacheng/QtProjects/HomeWork/source/"+incrementedString+extension;

    // if (copyImageFile(sourcePath, destinationPath)) {
    //     qDebug() << "Image copied successfully.";
    // } else {
    //     qDebug() << "Failed to copy image.";
    // }

    db.close();
    emit addDone();
}

void AddDialog::starZero()
{
    ui->btnStar1->setIcon(QIcon("://images/star.svg"));
    ui->btnStar2->setIcon(QIcon("://images/star.svg"));
    ui->btnStar3->setIcon(QIcon("://images/star.svg"));
    ui->btnStar4->setIcon(QIcon("://images/star.svg"));
    ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    scores=0;
}

void AddDialog::starOne()
{
    ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar2->setIcon(QIcon("://images/star.svg"));
    ui->btnStar3->setIcon(QIcon("://images/star.svg"));
    ui->btnStar4->setIcon(QIcon("://images/star.svg"));
    ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    scores=1;
}

void AddDialog::starTwo()
{
    ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar2->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar3->setIcon(QIcon("://images/star.svg"));
    ui->btnStar4->setIcon(QIcon("://images/star.svg"));
    ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    scores=2;
}

void AddDialog::starThree()
{
    ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar2->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar3->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar4->setIcon(QIcon("://images/star.svg"));
    ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    scores=3;
}

void AddDialog::starFour()
{
    ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar2->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar3->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar4->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar5->setIcon(QIcon("://images/star.svg"));
    scores=4;
}

void AddDialog::starFive()
{
    ui->btnStar1->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar2->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar3->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar4->setIcon(QIcon("://images/star (full).svg"));
    ui->btnStar5->setIcon(QIcon("://images/star (full).svg"));
    scores=5;
}

void AddDialog::Selecteddisconnect(){
    disconnect(ui->btnStar1,&StarButton::enterEvent_1,this,&AddDialog::starOne);
    //disconnect(ui->btnStar1,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    disconnect(ui->btnStar2,&StarButton::enterEvent_1,this,&AddDialog::starTwo);
    //disconnect(ui->btnStar2,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    disconnect(ui->btnStar3,&StarButton::enterEvent_1,this,&AddDialog::starThree);
    //disconnect(ui->btnStar3,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    disconnect(ui->btnStar4,&StarButton::enterEvent_1,this,&AddDialog::starFour);
    //disconnect(ui->btnStar4,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
    disconnect(ui->btnStar5,&StarButton::enterEvent_1,this,&AddDialog::starFive);
    //disconnect(ui->btnStar5,&StarButton::leaveEvent_1,this,&AddDialog::starZero);
}

