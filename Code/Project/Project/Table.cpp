//
// Created by mathe on 2023/10/30.
//

#include "Table.h"

void AbstractTable::addTable(AbstractTable *table)
{

}
AbstractTable* ConcreteTable::clone() {
    throw "Not yet implemented";
}
TableIterator* Table::createIterator() {
    throw "Not yet implemented";
}
void Table::accept(Visitor* visitor) {
    throw "Not yet implemented";
}

AbstractTable *Table::clone() {
    return nullptr;
}
void Table::handleState() {
    throw "Not yet implemented";
}


void Table::changeTableState() {
    throw "Not yet implemented";
}

void Table::setState(TableState* state) {
    throw "Not yet implemented";
}

Bill* Table::getBill(Customer* customer) {
    throw "Not yet implemented";
}

void Table::getOrders() {
    throw "Not yet implemented";
}

std::string TableState::getState() {
    throw "Not yet implemented";
}

void TableState::handleState(Table* table) {
    throw "Not yet implemented";
}

void Unoccupied::handleState() {
    throw "Not yet implemented";
}

std::string Unoccupied::getState() {
    throw "Not yet implemented";
}


void Occupied::acceptVisitor(Visitor* visitor) {
    throw "Not yet implemented";
}
Customer* Table::getCustomer()
{
    return this->customer;
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

generalWaiter* Table::getWaiter()
{
    return waiter;
}