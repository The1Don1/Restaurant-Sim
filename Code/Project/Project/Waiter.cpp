#include "Waiter.h"

Waiter::Waiter(string name, Table* headTable)
{
    waiterName = name;
    this->headTable = headTable;
    waitTime = 0;
}

void Waiter::reduceTimer()
{
    if (waitTime > 0)
        waitTime--;
}

void Waiter::deliverOrder()
{
    if (waitTime == 0)
    {
        cout << "Waiter " << waiterName << " delivers order to table " << headTable->getTableNumber() << endl;
        //headTable->setOrderDelivered();
    }
}

void Waiter::visitTable(Table* table)
{
    headTable = table;
}

void Waiter::getOrders()
{
    if (headTable->getOrderStatus() == false)
    {
        cout << "Waiter " << waiterName << " gets order from table " << headTable->getTableNumber() << endl;
        headTable->setOrderStatus();
        waitTime = 5;
    }
}

void Waiter::setOrders()
{
    if (headTable->getOrderStatus() == true)
    {
        cout << "Waiter " << waiterName << " sets order for table " << headTable->getTableNumber() << endl;
        headTable->setOrderDelivered();
        waitTime = 5;
    }
}

void Waiter::prepareDish()
{
    if (waitTime == 0)
    {
        cout << "Waiter " << waiterName << " prepares dish for table " << headTable->getTableNumber() << endl;
        headTable->setOrderDelivered();
    }
}


