#ifndef FORMORDER_H
#define FORMORDER_H

#include <QWidget>

namespace Ui {
class FormOrder;
}

class FormOrder : public QWidget
{
    Q_OBJECT

public:
    explicit FormOrder(QWidget *parent = 0);
    ~FormOrder();

private:
    Ui::FormOrder *ui;
};

#endif // FORMORDER_H
