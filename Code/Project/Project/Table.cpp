//
// Created by mathe on 2023/10/30.
//

#include "Table.h"
int AbstractTable::getnumberOfSeats()
{
    return numberOfSeats;
}

int AbstractTable::getTableID()
{
    return tableID;
};
std::vector<Customer *> AbstractTable::getCustomers()
{
    return customers;
};
void AbstractTable::setState(TableState *tableState)
{
    delete this->tableState;
    this->tableState = tableState;
    handleState();
};

TableState* AbstractTable::getState()
{
    return tableState;
};
void AbstractTable::handleState()
{
    //tableState->handleState(this);
};

Bill* AbstractTable::getBill(Customer *customer)
{
    return bill;
};
void AbstractTable::setWaiter(Waiter *waiter)
{
    this->waiter = waiter;
};


AbstractTable *Table::clone() {
    return nullptr;
}
std::vector<Customer *> Table::getCustomers()
{
    return customers;
}

void Table::acceptVisitor(Visitor *visitor)
{
    visitor->visitTable(this);
}
void Table::handleState()
{
    throw "Not yet implemented";
}

void Table::setState(TableState* state) {
    throw "Not yet implemented";
}

Bill* Table::getBill(Customer* customer) {
    throw "Not yet implemented";
}

void Table::setWaiter(Waiter *waiter)
{
    throw "Not yet implemented";
}

void Table::getOrders() {
    throw "Not yet implemented";
}

std::string TableState::getState() {
    throw "Not yet implemented";
}

void TableState::handleState(Table* tabke) {
    throw "Not yet implemented";
}

void Unoccupied::handleState() {
    throw "Not yet implemented";
}

std::string Unoccupied::getState() {
    throw "Not yet implemented";
}


void Occupied::acceptVisitor(Visitor visitor) {
    throw "Not yet implemented";
}

void Occupied::handleState() {
    throw "Not yet implemented";
}

std::string Occupied::getState() {
    throw "Not yet implemented";
}
void Reserved::handleState() {
    throw "Not yet implemented";
}

std::string Reserved::getState() {
    throw "Not yet implemented";
}

void TableGroup::addTable(AbstractTable *aTable)
{
    throw "Not yet implemented";
}

void TableGroup::acceptVisitor(Visitor *visitor)
{
    throw "Not yet implemented";
}

AbstractTable *TableGroup::clone()
{
    return this;
}
