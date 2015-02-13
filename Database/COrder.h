#ifndef CORDER_H
#define CORDER_H

#include <QtCore/QDateTime>

class COrder
{

public:
    COrder();

private:
    int m_OrderID;
    int m_CustomerID;
    int m_ProductID;
    QDateTime m_DateTime;

};

#endif // CORDER_H
