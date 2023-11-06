#include "Waiter.h"

void Waiter::getOrders()
{
    throw "Not yet implemented";
}

void Waiter::sendOrders(std::vector<Dish*> dish)
{
    std::cout << "Sending order to kitchen." << std::endl;
    kitchen->receiveOrder(dish);
}

void Waiter::deliverOrder()
{
    std::cout << "Delivering order to table with table ID of " << waiterHeadTable->getTableID() << std::endl;
}

void generalWaiter::visitTable(Table* table)
{
    throw "Not yet implemented";
}

void generalWaiter::addToTab(std::string customerName, double amount)
{
    throw "Not yet implemented";
}

void generalWaiter::payTab(std::string customerName, double amount)
{
    throw "Not yet implemented";
}

Tab *generalWaiter::getTab(std::string customerName)
{
    throw "Not yet implemented";
}

void generalWaiter::performTask()
{
    throw "Not yet implemented";
}

void MaitreD::checkReservation()
{
    throw "Not yet implemented";
}

void MaitreD::allocateTable(Customer* customer)
{
    throw "Not yet implemented";
}

void MaitreD::mergeTables(int table1, int table2)
{
throw "Not yet implemented";
}

void MaitreD::splitTables(Waiter* waiter, int tableno)
{
    throw "Not yet implemented";
}

void MaitreD::performTask()
{
    throw "Not yet implemented";
}
