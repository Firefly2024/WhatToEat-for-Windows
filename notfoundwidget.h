#ifndef NOTFOUNDWIDGET_H
#define NOTFOUNDWIDGET_H

#include <QWidget>

namespace Ui {
class NotFoundWidget;
}

class NotFoundWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NotFoundWidget(QWidget *parent = nullptr);
    ~NotFoundWidget();

private:
    Ui::NotFoundWidget *ui;
};

#endif // NOTFOUNDWIDGET_H
