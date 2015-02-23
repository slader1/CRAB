#ifndef CPRODUCT_H
#define CPRODUCT_H

#include <QtGui/QImage>

/*! Simple container class to store a record from the Product table */
class CProduct               
{

public:
    CProduct();

    int ProductID;
    QString Name;
    QImage Image;
    double Price;

};

#endif // CPRODUCT_H
