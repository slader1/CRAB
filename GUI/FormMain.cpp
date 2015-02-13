#include "FormMain.h"
#include "ui_FormMain.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&m_ReaderThread, SIGNAL(NewCardNumber(QString)), this, SLOT(NewCardNumber(QString)), Qt::QueuedConnection);

    m_ReaderThread.start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ButtonGong_clicked()
{
    m_SoundPlayer.PlayMP3("Sounds/gong.mp3");
}

void Widget::NewCardNumber(const QString &p_CardNumber)
{
    //CCustomer l_Customer = m_CRABDB.GetCustomerForCardNumber(p_CardNumber);
    //CProduct l_Product = m_CRABDB.GetDefaultProductFromCustomer(l_Customer);
    //m_CRABDB.MakeOrder(l_Customer, l_Product);
    //display cust/prod
    QMessageBox::information(this, "Order", "Order");
}
