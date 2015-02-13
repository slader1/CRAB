#ifndef CCUSTOMER_H
#define CCUSTOMER_H

#include <QtGui/QImage>

class CCustomer
{

public:
    CCustomer();

private:
    int m_CustomerID;
    QString m_Name;
    QString m_CardNumber;
    QImage m_Image;
    int m_DefaultProductID;

};

#endif // CCUSTOMER_H
