#include "Waiter.h"
void Waiter::visitTable(Table *table) {
    throw "Not yet implemented";
}

void Waiter::prepareDish() {
    throw "Not yet implemented";
}

void Waiter::getOrders() {
    throw "Not yet implemented";
}

void Waiter::sendOrders() {
    throw "Not yet implemented";
}

void Waiter::deliverOrder() {
    throw "Not yet implemented";
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

void MaitreD::checkReservation() {
    throw "Not yet implemented";
}

void MaitreD::allocateTable() {
    throw "Not yet implemented";
}

void MaitreD::mergeTables(int table1, int table2) {
    throw "Not yet implemented";
}

void MaitreD::splitTables(Waiter* waiter, int tableNumber) {
    throw "Not yet implemented";
}

void MaitreD::performTask() {
    throw "Not yet implemented";
}

void generalWaiter::receiveCompliment(const std::string& compliment)
{
    std::cout << "Waiter: Thank you for your kind words! I'm glad you enjoyed your dining experience.\n";
    std::cout << "Compliment details: " << compliment << "\n";
}