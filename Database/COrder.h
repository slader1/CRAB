#ifndef CORDER_H
#define CORDER_H

#include <QtCore/QDateTime>

/*! Simple container class to store a record from the Order table */
class COrder
{

public:
    COrder();

    int OrderID;
    int CustomerID;
    int ProductID;
    QDateTime DateTime;

};

#endif // CORDER_H
