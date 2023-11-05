#include "Waiter.h"
void Waiter::visitTable(Table *table) {
   
    std::cout << "Visiting table " << table->getTableID() << std::endl;
}

void Waiter::prepareDish(Dish  dish) {
    headChef->prepareDish(dish);
}

void Waiter::getOrders() {
    waiterHeadTable->getOrders();
}

void Waiter::sendOrders() {
    std::cout << "Sending order to table with table ID of " << waiterHeadTable->getTableID() << std::endl;
}

void Waiter::deliverOrder() {
    std::cout << "Delivering order to table with table ID of " << waiterHeadTable->getTableID() << std::endl;

}

void generalWaiter::visitTable(Table occupiedTable) {
    std::cout << "Visiting table " << occupiedTable.getTableID() << std::endl;
}

void generalWaiter::addToTab(std::string customerName, double amount) {
    
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

void MaitreD::checkReservation() {
    //note i need to be able to check what the current state of the table is
    //std::cout << "Current state of table: " << waiterHeadTable->getTableState();
    std::cout << "Checking reservation" << std::endl;
}

void MaitreD::allocateTable() {
    std::cout << "Allocating table " << waiterHeadTable->getTableID()
              << ". Current table state: Occupied" << std::endl;
            
    Occupied* occupied;
    waiterHeadTable->setState(occupied); 
    //waiterHeadTable->setCustomer(waitingList.pop());
    waitingList.pop();
}


void MaitreD::mergeTables(int table1, int table2) {
    std::cout << "Merging table " << table1 << " with table " << table2 << std::endl;
}

void MaitreD::splitTables(Waiter* waiter, int tableNumber) {
    std::cout << "Splitting table " << tableNumber << " for waiter " << waiter->waiterName << std::endl;
}

void MaitreD::performTask() {
    throw "Not yet implemented";
}