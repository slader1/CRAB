#include "FormMain.h"
#include "ui_FormMain.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //m_AnimationTimer.setInterval(2000);

    connect(&m_ReaderThread, SIGNAL(NewCardNumber(QString)), this, SLOT(NewCardNumber(QString)));

    //m_ReaderThread.moveToThread();
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
    try
    {
        CCustomer l_Customer;
        if(m_CRABDB.GetCustomerForCardNumber(p_CardNumber, l_Customer))
        {
            CProduct l_Product = m_CRABDB.GetDefaultProductFromCustomer(l_Customer);
            m_CRABDB.MakeOrder(l_Customer, l_Product);
        }
        else
        {
            //card number not registered
        }
        qDebug("Order complete");
    }
    catch(std::exception &e)
    {
        QMessageBox::information(this, "Error", e.what());
    }
}

void Widget::on_pushButton_clicked()
{
    NewCardNumber("0");
}
