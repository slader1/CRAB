#include "FormMain.h"
#include "ui_FormMain.h"

#include <QMessageBox>

FormMain::FormMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMain)
{
    ui->setupUi(this);

    m_AnimationTimer.setInterval(2000);

    //connect and start thread
    connect(&m_ReaderThread, &CReaderThread::NewCardNumber, this, &FormMain::NewCardNumber);
    m_ReaderThread.start();
}

FormMain::~FormMain()
{
    delete ui;
}

void FormMain::on_ButtonGong_clicked()
{
    m_SoundPlayer.PlayMP3("Sounds/gong.mp3");
}

void FormMain::NewCardNumber(const QString &p_CardNumber)
{
    try
    {
        CCustomer l_Customer;
        if(m_CRABDB.GetCustomerForCardNumber(p_CardNumber, l_Customer))
        {
            CProduct l_Product;
            if(m_CRABDB.GetDefaultProductFromCustomer(l_Customer, l_Product) == false)
            {
                //invalid product
            }
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

void FormMain::on_pushButton_clicked()
{
    NewCardNumber("0");
}
