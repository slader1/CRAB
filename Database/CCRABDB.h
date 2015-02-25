#ifndef CCRABDB_H
#define CCRABDB_H

#include <QtSql/QSqlDatabase>

#include "CCustomer.h"
#include "CProduct.h"

class CCRABDB
{
public:
    CCRABDB();

    bool GetCustomerForCardNumber(const QString& p_CardNumber, CCustomer& p_Customer);

    bool GetDefaultProductFromCustomer(const CCustomer& p_Customer, CProduct& p_Product);

    void MakeOrder(const CCustomer& p_Customer, const CProduct& p_Product);

private:
    QSqlDatabase m_DB;

    unsigned int RunQuery(const QString& p_SQL, QSqlQuery& p_Query);

};

#endif // CCRABDB_H
