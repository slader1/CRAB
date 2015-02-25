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

void FormOrder::DisplayOrder(const CCustomer &p_Customer, const CProduct &p_Product)
{
    ui->LabelCustomerImage->setPixmap(QPixmap::fromImage(p_Customer.Image));
    ui->LabelProductImage->setPixmap(QPixmap::fromImage(p_Product.Image));
    ui->LabelCustomerName->setText(p_Customer.Name);
    ui->LabelProductName->setText(p_Product.Name);
    ui->LabelPrice->setText(QString::number(p_Product.Price) + " €");
}

