#include "FormMain.h"
#include "ui_FormMain.h"

#include <QMessageBox>

FormMain::FormMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMain)
{
    ui->setupUi(this);

    //setup timer
    m_AnimationTimer.setInterval(2000);
    connect(&m_AnimationTimer, &QTimer::timeout, this, &FormMain::StopOrderAnimation);

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
        if(m_AnimationTimer.isActive())
        {
            //animation in progress
            return;
        }
        CCustomer l_Customer;
        if(m_CRABDB.GetCustomerForCardNumber(p_CardNumber, l_Customer))
        {
            CProduct l_Product;
            if(m_CRABDB.GetDefaultProductFromCustomer(l_Customer, l_Product) == false)
            {
                //invalid product
            }
            m_CRABDB.MakeOrder(l_Customer, l_Product);

            StartOrderAnimation(l_Customer, l_Product);
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

void FormMain::StartOrderAnimation(const CCustomer &p_Customer, const CProduct &p_Product)
{
    m_AnimationTimer.start();
    m_FormOrder.DisplayOrder(p_Customer, p_Product);
    m_FormOrder.show();
    ui->labelReadyForCard->setText("NOT READY FOR CARD");
    m_SoundPlayer.PlayMP3("Sounds/coin.mp3");
}

void FormMain::StopOrderAnimation()
{
    ui->labelReadyForCard->setText("READY FOR CARD");
    m_FormOrder.hide();
    m_AnimationTimer.stop();
}

void FormMain::on_pushButton_clicked()
{
    NewCardNumber("1");
}
