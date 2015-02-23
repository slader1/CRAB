#ifndef CCUSTOMER_H
#define CCUSTOMER_H

#include <QtGui/QImage>

/*! Simple container class to store a record from the Customer table */
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
