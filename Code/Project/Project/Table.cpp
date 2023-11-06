//
// Created by mathe on 2023/10/30.
//

#include "Table.h"

/**
 * @brief Returns table's number of seats
 * 
 * @return int 
 */
int AbstractTable::getnumberOfSeats()
{
    return numberOfSeats;
}

/**
 * @brief Returns table ID
 * 
 * @return int 
 */
int AbstractTable::getTableID()
{
    return tableID;
};

/**
 * @brief Returns customers currently at table
 * 
 * @return std::vector<Customer *> 
 */
std::vector<Customer *> AbstractTable::getCustomers()
{
    return customers;
};

/**
 * @brief Sets the state of the table
 * 
 * @param tableState 
 */
void AbstractTable::setState(TableState *tableState)
{
    delete this->tableState;
    this->tableState = tableState;
    handleState();
};

/**
 * @brief Returns table's state
 * 
 * @return TableState* 
 */
TableState* AbstractTable::getState()
{
    return tableState;
};

/**
 * @brief State handler for table class
 * 
 */
void AbstractTable::handleState()
{
    tableState->handleState(this);
};

/**
 * @brief Returns customer bill
 * 
 * @param customer 
 * @return Bill* 
 */
Bill* AbstractTable::getBill(Customer *customer)
{
    return bill;
};

/**
 * @brief Sets waiter to the table
 * 
 * @param waiter 
 */
void AbstractTable::setWaiter(Waiter *waiter)
{
    this->waiter = waiter;
}

/**
 * @brief Gets the table's assigned  waiter
 * 
 * @return Waiter* 
 */
Waiter *AbstractTable::getWaiter()
{
    return waiter;
}

/**
 * @brief Adds customers to the table
 * 
 * @param newCustomers 
 */
void AbstractTable::setCustomers(std::vector<Customer *> newCustomers)
{
    for(auto customer: newCustomers)
    {
        this->customers.push_back(customer);
    }
};

/**
 * @brief Returns a copy of the table
 * 
 * @return AbstractTable* 
 */
AbstractTable *Table::clone() {
    return nullptr;
}

/**
 * @brief Returns a vector of customers seated at table
 * 
 * @return std::vector<Customer *> 
 */
std::vector<Customer *> Table::getCustomers()
{
    return customers;
}

/**
 * @brief + operator overload to add 2 tables and return a table group
 * 
 * @param table 
 * @return AbstractTable* 
 */
AbstractTable *Table::operator+(Table *table)
{
    TableGroup *newTableGroup = new TableGroup(this->getnumberOfSeats() + table->getnumberOfSeats());
    newTableGroup->addTable(this);
    newTableGroup->addTable(table);
    return newTableGroup;
}


/**
 * @brief operator overload to add a table to a table group
 * 
 * @param tableGroup 
 * @return AbstractTable* 
 */
AbstractTable *Table::operator+(TableGroup *tableGroup)
{
    TableGroup *newTableGroup = new TableGroup(this->getnumberOfSeats() + tableGroup->getnumberOfSeats());
    newTableGroup->addTable(this);
    newTableGroup->addTable(tableGroup);
    return newTableGroup;
}

/**
 * @brief Function used in visitor design pattern to accept a waiter to the table
 * 
 * @param visitor 
 */
void Table::acceptVisitor(Visitor *visitor)
{
    visitor->visitTable(this);
}

/**
 * @brief State handler for table class
 * 
 */
void Table::handleState()
{
    tableState->handleState(this);
}

/**
 * @brief Sets state for current table
 * 
 * @param state 
 */
void Table::setState(TableState* state) {
    delete this->tableState;
    this->tableState = tableState;
    handleState();
}

/**
 * @brief gets state 
 * 
 * @return TableState* 
 */
TableState *Table::getState()
{
    return tableState;
}

/**
 * @brief Returns bill for the table
 * 
 * @param customer 
 * @return Bill* 
 */
Bill* Table::getBill(Customer* customer) {
    return bill;
}

/**
 * @brief Sets waiter for current table
 * 
 * @param waiter 
 */
void Table::setWaiter(Waiter *waiter)
{
    this->waiter = waiter;
}

/**
 * @brief Gets waiter for current table
 * 
 * @return Waiter* 
 */
Waiter *Table::getWaiter()
{
    return waiter;
}

void Table::getOrders() {
    throw "Not yet implemented";
}

/**
 * @brief State handler for table state
 * 
 * @param table 
 */
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

/**
 * @brief Returns string which specifies table state 
 * 
 * @return std::string 
 */
std::string Unoccupied::getState()
{
    return "Unoccupied";
}

/**
 * @brief Occupied state handle, if there are no customers change from occupied to unoccupied
 * 
 * @param table 
 */
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

/**
 * @brief Returns string which specifies table state 
 * 
 * @return std::string 
 */
std::string Occupied::getState()
{
    return "Occupied";
}

/**
 * @brief Adds a table to tables vector
 * 
 * @param aTable 
 */
void TableGroup::addTable(AbstractTable *aTable)
{
    tables.push_back(aTable);
    numberOfSeats += aTable->getnumberOfSeats();
}

/**
 * @brief Function to accept a table visitor
 * 
 * @param visitor 
 */
void TableGroup::acceptVisitor(Visitor *visitor)
{
    visitor->visitTable(this);
}


/**
 * @brief operator overload to add 2 table groups and return a table group
 * 
 * @param tableGroup 
 * @return AbstractTable* 
 */
AbstractTable* TableGroup::operator+(TableGroup *tableGroup)
{
    TableGroup *newTableGroup = new TableGroup();
    newTableGroup->addTable(this);
    newTableGroup->addTable(tableGroup);
    return newTableGroup;
}


/**
 * @brief + operator overload to add a table to the table group
 * 
 * @param table 
 * @return AbstractTable* 
 */
AbstractTable* TableGroup::operator+(Table *table)
{
    TableGroup *newTableGroup = new TableGroup();
    newTableGroup->addTable(this);
    newTableGroup->addTable(table);
    return newTableGroup;
}

/**
 * @brief Returns reference to current table
 * 
 * @return AbstractTable* 
 */
AbstractTable *TableGroup::clone()
{
    return this;
}

/**
 * @brief Returns tables vector
 * 
 * @return std::vector<AbstractTable *> 
 */
std::vector<AbstractTable *> TableGroup::getTables()
{
    return tables;
}
