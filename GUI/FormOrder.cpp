#include "FormOrder.h"
#include "ui_FormOrder.h"

FormOrder::FormOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOrder)
{
    ui->setupUi(this);
}

FormOrder::~FormOrder()
{
    delete ui;
}
