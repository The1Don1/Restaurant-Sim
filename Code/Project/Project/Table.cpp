#include "Table.h"

AbstractTable::~AbstractTable()
{
    delete tableState;
    delete bill;
    delete waiter;
    for (auto customer : customers)
    {
        delete customer;
    }
}

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
};

TableGroup::~TableGroup()
{
    for (auto table : tables)
    {
        delete table;
    }
}

//Add a table to the vector of tables
void TableGroup::addTable(AbstractTable *aTable)
{
    tables.push_back(aTable);
    numberOfSeats += aTable->getnumberOfSeats();
}

void TableGroup::acceptVisitor(Visitor visitor)
{
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

AbstractTable* TableGroup::clone()
{
    TableGroup *tableGroup = new TableGroup();
    for (auto table : tables)
    {
        tableGroup->addTable(table->clone());
    }
    return tableGroup;
}

//Get tables vector
std::vector<AbstractTable *> TableGroup::getTables()
{
    return tables;
}

AbstractTable *Table::clone()
{
    Table *table = new Table(this->getnumberOfSeats());
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

void Table::acceptVisitor(Visitor visitor)
{
    visitor.visitTable(this);
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