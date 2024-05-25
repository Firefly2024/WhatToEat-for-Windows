#ifndef TUJIANWINDOW_H
#define TUJIANWINDOW_H

#include "QtWidgets/qpushbutton.h"
#include "widget.h"
#include <QMainWindow>


namespace Ui {
class TujianWindow;
}

class TagButton:public QPushButton{
    Q_OBJECT
public:
    TagButton(const QString& text);
    ~TagButton();
    int tagId;
signals:
    void sendSelf(TagButton*);
public slots:
    void clickedMessage();
};

class SelectedTagButton:public QPushButton{
    Q_OBJECT
public:
    SelectedTagButton(const QString& text);
    ~SelectedTagButton();
    int index;
signals:
    void sendIndex(const int& num);
public slots:
    void clickedMessage();
};


class TujianWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TujianWindow(QWidget *parent = nullptr);
    ~TujianWindow();
    int page;
    int totalPage;
    int searchMode;
    QVector<QString>selectedNames;
    QVector<int>selectedIds;
    Widget* wparent;



public slots:
    void addCards();
    void resetCards();
    void updateLabelSearch(const QString &text);
    void selectTag(TagButton* target);
    void releaseTag(const int& idx);
    void NameModelOn();
    void TabelModelOn();
    void backward();
private slots:
    void on_btnRight_clicked();

    void on_btnLeft_clicked();

private:
    Ui::TujianWindow *ui;

};



#endif // TUJIANWINDOW_H
