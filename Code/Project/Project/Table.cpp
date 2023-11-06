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
    tableState->handleState(this);
};

Bill* AbstractTable::getBill(Customer *customer)
{
    return bill;
};
void AbstractTable::setWaiter(Waiter *waiter)
{
    this->waiter = waiter;
}
Waiter *AbstractTable::getWaiter()
{
    return waiter;
};

AbstractTable *Table::clone() {
    return nullptr;
}
std::vector<Customer *> Table::getCustomers()
{
    return customers;
}

//+ operator overload to add 2 tables and return a table group
AbstractTable *Table::operator+(Table *table)
{
    TableGroup *newTableGroup = new TableGroup(this->getnumberOfSeats() + table->getnumberOfSeats());
    newTableGroup->addTable(this);
    newTableGroup->addTable(table);
    return newTableGroup;
}
//+ operator overload to add a table to a table group
AbstractTable *Table::operator+(TableGroup *tableGroup)
{
    TableGroup *newTableGroup = new TableGroup(this->getnumberOfSeats() + tableGroup->getnumberOfSeats());
    newTableGroup->addTable(this);
    newTableGroup->addTable(tableGroup);
    return newTableGroup;
}

void Table::acceptVisitor(Visitor *visitor)
{
    visitor->visitTable(this);
}
void Table::handleState()
{
    tableState->handleState(this);
}

void Table::setState(TableState* state) {
    delete this->tableState;
    this->tableState = tableState;
    handleState();
}

TableState *Table::getState()
{
    return tableState;
}

Bill* Table::getBill(Customer* customer) {
    return bill;
}

void Table::setWaiter(Waiter *waiter)
{
    this->waiter = waiter;
}

Waiter *Table::getWaiter()
{
    return waiter;
}

void Table::getOrders() {
    throw "Not yet implemented";
}

void Unoccupied::handleState(AbstractTable *table)
{
    if (table->getCustomers().size() == 0)
    {
        table->setState(new Unoccupied());
    }
    else if (table->getCustomers().size() > 0)
    {
        return;
    }
}

std::string Unoccupied::getState()
{
    return "Unoccupied";
}

void Occupied::handleState(AbstractTable *table)
{
    if (table->getCustomers().size() == 0)
    {
        table->setState(new Unoccupied());
    }
    else if (table->getCustomers().size() > 0)
    {
        return;
    }
}

std::string Occupied::getState()
{
    return "Occupied";
}

void TableGroup::addTable(AbstractTable *aTable)
{
    tables.push_back(aTable);
    numberOfSeats += aTable->getnumberOfSeats();
}

void TableGroup::acceptVisitor(Visitor *visitor)
{
    visitor->visitTable(this);
}

//+ operator overload to add 2 table groups and return a table group
AbstractTable* TableGroup::operator+(TableGroup *tableGroup)
{
    TableGroup *newTableGroup = new TableGroup();
    newTableGroup->addTable(this);
    newTableGroup->addTable(tableGroup);
    return newTableGroup;
}

//+ operator overload to add a table to the table group
AbstractTable* TableGroup::operator+(Table *table)
{
    TableGroup *newTableGroup = new TableGroup();
    newTableGroup->addTable(this);
    newTableGroup->addTable(table);
    return newTableGroup;
}

AbstractTable *TableGroup::clone()
{
    return this;
}

std::vector<AbstractTable *> TableGroup::getTables()
{
    return tables;
}
