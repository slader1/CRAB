#include "CCRABDB.h"

#include <stdexcept>
#include <math.h>
#include <QtSql/QtSql>

CCRABDB::CCRABDB()
{
    m_DB = QSqlDatabase::addDatabase("QSQLITE");
    m_DB.setDatabaseName("CRABDB.db3");
    if (m_DB.open())
    {
        //good
    }
    else
    {
        throw std::runtime_error(QString("Failed to open database. Error: " + m_DB.lastError().text()).toStdString());
    }
}

bool CCRABDB::GetCustomerForCardNumber(const QString& p_CardNumber, CCustomer &p_Customer)
{
    QSqlQuery l_Query(m_DB);
    unsigned int l_CardCount = RunQuery("SELECT CustomerID, Name, CardNumber, Image, DefaultProductID FROM Customers WHERE CardNumber = '" + p_CardNumber + "'", l_Query);
    if( (l_CardCount == 1) && (l_Query.first()) )
    {
        //good, fill p_Customer
        p_Customer.CustomerID = l_Query.value("CustomerID").toInt();
        p_Customer.Name = l_Query.value("Name").toString();
        p_Customer.CardNumber = l_Query.value("CardNumber").toString();
        p_Customer.Image = QImage(l_Query.value("Image").toString());
        p_Customer.DefaultProductID = l_Query.value("DefaultProductID").toInt();
    }
    else if(l_CardCount == 0)
    {
        //card number not registered
        return false;
    }
    else
    {
        //should not happen
        throw std::runtime_error("CardNumber not unique");
    }
    return true;
}

bool CCRABDB::GetDefaultProductFromCustomer(const CCustomer &p_Customer, CProduct &p_Product)
{
    QSqlQuery l_Query(m_DB);
    unsigned int l_ProductCount = RunQuery("SELECT ProductID, Name, Image, Price FROM Products WHERE ProductID = " + QString::number(p_Customer.DefaultProductID), l_Query);
    if( (l_ProductCount == 1) && (l_Query.first()) )
    {
        //good, fill p_Product
        p_Product.ProductID = l_Query.value("ProductID").toInt();
        p_Product.Name = l_Query.value("Name").toString();
        p_Product.Image = QImage(l_Query.value("Image").toString());
        p_Product.Price = l_Query.value("Price").toDouble();
    }
    else
    {
        //should not happen
        throw std::runtime_error("Invalid DefaultProductID");
    }
    return true;
}

void CCRABDB::MakeOrder(const CCustomer& p_Customer, const CProduct& p_Product)
{
    if( (p_Customer.CustomerID <= 0) || (p_Product.ProductID <= 0) )
    {
        throw std::runtime_error("Invalid CustomerID/ProductID");
    }
    QSqlQuery l_Query(m_DB);
    RunQuery("INSERT INTO Orders (CustomerID, ProductID) VALUES (" + QString::number(p_Customer.CustomerID) + ", " + QString::number(p_Product.ProductID) + ")", l_Query);
    if(l_Query.numRowsAffected() != 1)
    {
        throw std::runtime_error(QString("Order failed!\n\n" + l_Query.lastError().text()).toStdString());
    }

    //Order stored
    return;
}

unsigned int CCRABDB::RunQuery(const QString& p_SQL, QSqlQuery& p_Query)
{
    unsigned int l_RecordCount = 0;
    if(p_Query.exec(p_SQL))
    {
        //good
        while(p_Query.next())
        {
            l_RecordCount++;
        }
    }
    else
    {
        //bad
        throw std::runtime_error(QString("SQL Error: " + p_Query.lastError().text() + "\nQuery: " + p_SQL).toStdString());
    }
    return l_RecordCount;
}
