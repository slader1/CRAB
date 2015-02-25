#ifndef FORMORDER_H
#define FORMORDER_H

#include <QWidget>

#include "../Database/CCustomer.h"
#include "../Database/CProduct.h"
#include "../Database/COrder.h"

namespace Ui {
class FormOrder;
}

class FormOrder : public QWidget
{
    Q_OBJECT

public:
    explicit FormOrder(QWidget *parent = 0);
    ~FormOrder();

    /*!
     * \brief DisplayOrder Displays an order on the form
     * \param p_Order
     * \param p_Customer
     * \param p_Product
     */
    void DisplayOrder(const CCustomer& p_Customer, const CProduct& p_Product);

private:
    Ui::FormOrder *ui;
};

#endif // FORMORDER_H
