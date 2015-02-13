#ifndef CCRABDB_H
#define CCRABDB_H

#include <QtSql/QSqlDatabase>

#include "CCustomer.h"
#include "CProduct.h"

class CCRABDB
{
public:
    CCRABDB();

    CCustomer& GetCustomerForCardNumber(const QString& p_CardNumber);

    CProduct& GetDefaultProductFromCustomer(const CCustomer& p_Customer);

    void MakeOrder(const CCustomer& p_Customer, const CProduct& p_Product);

private:
    QSqlDatabase m_DB;

    QSqlQuery& RunQuery(const QString& p_SQL);

};

#endif // CCRABDB_H
