#include "CCRABDB.h"

#include <stdexcept>
#include <math.h>
#include <QtSql/QtSql>

CCRABDB::CCRABDB()
{
    m_DB.addDatabase("QSQLITE");
    m_DB.setDatabaseName("CRABDB.db3");
    if (m_DB.open())
    {
        //good
    }
    else
    {
        throw std::runtime_error("Failed to open database");
    }
}

CCustomer& CCRABDB::GetCustomerForCardNumber(const QString& p_CardNumber)
{
    QSqlQuery l_Query = RunQuery("SELECT * FROM Customers WHERE CardNumber = '" + p_CardNumber + "'");
    if(l_Query.result()->size() == 1)
    {
        //good
    }
    else if(l_Query.result()->size() == 0)
    {
        throw std::runtime_error("CardNumber not registered");
    }
    else
    {
        throw std::runtime_error("CardNumber not unique");
    }
}

CProduct& CCRABDB::GetDefaultProductFromCustomer(const CCustomer& p_Customer)
{

}

void CCRABDB::MakeOrder(const CCustomer& p_Customer, const CProduct& p_Product)
{

}

QSqlQuery& CCRABDB::RunQuery(const QString& p_SQL)
{
    QSqlQuery l_Query(m_DB);
    if(l_Query.exec(p_SQL))
    {
        //good
        l_Query.first();
    }
    else
    {
        //bad
        throw std::runtime_error("SQL Error: " + l_Query.lastError().text() + "\nQuery: " + p_SQL);
    }
    return l_Query;
}
