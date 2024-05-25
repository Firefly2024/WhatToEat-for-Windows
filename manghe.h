#ifndef MANGHE_H
#define MANGHE_H

#include <QWidget>

namespace Ui {
class Manghe;
}

class Manghe : public QWidget
{
    Q_OBJECT

public:
    explicit Manghe(QWidget *parent = nullptr);
    ~Manghe();

private slots:


    void on_returnmenu_clicked();

private:
    Ui::Manghe *ui;
};

#endif // MANGHE_H
