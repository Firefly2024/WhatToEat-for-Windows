#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();
    int scores;

signals:
    void addDone();

public slots:
    void Selecteddisconnect();
private:
    Ui::AddDialog *ui;

private slots:
    void selectFile();
    void addActions();
    void starZero();
    void starOne();
    void starTwo();
    void starThree();
    void starFour();
    void starFive();
};

#endif // ADDDIALOG_H
