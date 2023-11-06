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
    delete this->tableState;
    this->tableState = tableState;
    handleState();
}

Bill* Table::getBill(Customer* customer) {
    return bill;
}

void Table::setWaiter(Waiter *waiter)
{
    throw "Not yet implemented";
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
    throw "Not yet implemented";
}

AbstractTable *TableGroup::clone()
{
    return this;
}
