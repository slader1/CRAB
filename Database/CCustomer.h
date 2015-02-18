#ifndef CCUSTOMER_H
#define CCUSTOMER_H

#include <QtGui/QImage>

class CCustomer
{

public:
    CCustomer();

    int CustomerID;
    QString Name;
    QString CardNumber;
    QImage Image;
    int DefaultProductID;

};

#endif // CCUSTOMER_H
