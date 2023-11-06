#include "Waiter.h"
// void generalWaiter::visitTable(Table *table)
// {
//     throw "Not yet implemented";
// }

void Waiter::getOrders() {
    throw "Not yet implemented";
}

/**
 * @brief Send order function for the waiter class
 * This function sends all the customer orders to the head chef and
 * changes the state of the dishes sent to "preparing"
 * @param order 
 * 
 */
void Waiter::sendOrders(std::vector<Dish*> order) {
    for(auto dish: order){
        dish->setDishStatus(new Preparing);
        headChef->AddDish(dish);
    }
}

void Waiter::deliverOrder() {
    
}

void generalWaiter::addToTab(std::string customerName, double amount) {
    throw "Not yet implemented";
}

void generalWaiter::payTab(std::string customerName, double amount) {
    throw "Not yet implemented";
}

Tab* generalWaiter::getTab(std::string customerName) {
    throw "Not yet implemented";
}

void generalWaiter::performTask() {
    throw "Not yet implemented";
}

void generalWaiter::visitTable(AbstractTable *table)
{
    std::cout << "Waiter: " << waiterName << " visiting table "<< table->getTableID() << "\n";
}

void MaitreD::checkReservation() {
    throw "Not yet implemented";
}

void MaitreD::allocateTable(Customer* customer) {
    throw "Not yet implemented";
}

void MaitreD::mergeTables(int table1, int table2) {
    throw "Not yet implemented";
}

void MaitreD::splitTables(Waiter* waiter, int tableNumber) {
    throw "Not yet implemented";
}

void MaitreD::performTask() {
    std::cout << "Waiter: " << waiterName << " performing task\n";
}

void generalWaiter::receiveCompliment(const std::string& compliment)
{
    std::cout << "Waiter: Thank you for your kind words! I'm glad you enjoyed your dining experience.\n";
    std::cout << "Compliment details: " << compliment << "\n";
}