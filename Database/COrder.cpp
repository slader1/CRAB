#include "COrder.h"

COrder::COrder()
{    
    OrderID = -1;
    CustomerID = -1;
    ProductID = -1;
    DateTime = QDateTime::currentDateTime();
}
