#ifndef CPRODUCT_H
#define CPRODUCT_H

#include <QtGui/QImage>

class CProduct               
{

public:
    CProduct();

private:
    int m_ProductID;
    QString m_Name;
    QImage m_Image;
    double m_Price;

};

#endif // CPRODUCT_H
