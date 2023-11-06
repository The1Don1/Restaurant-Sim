#ifndef PROJECT_TABLE_H
#define PROJECT_TABLE_H
#include <iostream>
#include "Customer.h"
#include "Floor.h"
#include "TableIterator.h"

class Bill;
class Waiter;
class Visitor;

/*
Abstract Class that will be the base for the Tables
Stores the number of seats
It will have the table id to identify it
It will have a table state to determine if it is occupied or not
*/
class AbstractTable
{
public:
    explicit AbstractTable(int numberOfSeats) : numberOfSeats(numberOfSeats), tableID(tableCount++) {}
    virtual void acceptVisitor(Visitor visitor) = 0;
    virtual AbstractTable *operator+(TableGroup *tableGroup);
    virtual AbstractTable *operator+(Table *table);
    virtual AbstractTable *clone() = 0;
    virtual ~AbstractTable()
    {
        delete tableState;
        delete bill;
        delete waiter;
        for (auto customer : customers)
        {
            delete customer;
        }
    }
    int getnumberOfSeats()
    {
        return numberOfSeats;
    };
    int getTableID()
    {
        return tableID;
    };
    std::vector<Customer *> getCustomers()
    {
        return customers;
    };
    void setState(TableState *tableState)
    {
        delete this->tableState;
        this->tableState = tableState;
        handleState();
    };
    TableState *getState()
    {
        return tableState;
    };
    void handleState()
    {
        tableState->handleState(this);
    };

    Bill *getBill(Customer *customer)
    {
        return bill;
    };
    void setWaiter(Waiter *waiter)
    {
        this->waiter = waiter;
    };
    void getOrders();
    static int tableCount;
    AbstractTable *next;
protected:
    TableState *tableState;
    std::vector<Customer *> customers;
    Bill *bill;
    Waiter *waiter;
    int numberOfSeats;
    int tableID;
};
int AbstractTable::tableCount = 0;

/*
    TableGroup is a composite class that will store a vector of AbstractTables
    It will be used to store the tables that are grouped together
*/
class TableGroup : public AbstractTable
{
private:
    std::vector<AbstractTable *> tables;
public:
    TableGroup(int numberOfSeats = 0) : AbstractTable(numberOfSeats) {};
    ~TableGroup()
    {
        for (auto table : tables)
        {
            delete table;
        }
    }

    //Add a table to the vector of tables
    void addTable(AbstractTable *aTable)
    {
        tables.push_back(aTable);
        numberOfSeats += aTable->getnumberOfSeats();
    }

    void acceptVisitor(Visitor visitor)
    {
    }

    //+ operator overload to add 2 table groups and return a table group
    AbstractTable *operator+(TableGroup *tableGroup)
    {
        TableGroup *newTableGroup = new TableGroup();
        newTableGroup->addTable(this);
        newTableGroup->addTable(tableGroup);
        return newTableGroup;
    }

    //+ operator overload to add a table to the table group
    AbstractTable *operator+(Table *table)
    {
        TableGroup *newTableGroup = new TableGroup();
        newTableGroup->addTable(this);
        newTableGroup->addTable(table);
        return newTableGroup;
    }

    AbstractTable *clone()
    {
        TableGroup *tableGroup = new TableGroup();
        for (auto table : tables)
        {
            tableGroup->addTable(table->clone());
        }
        return tableGroup;
    }

    //Get tables vector
    std::vector<AbstractTable *> getTables()
    {
        return tables;
    }
};

/*
    Table is a leaf class that will be a single table
*/
class Table : public AbstractTable
{
public:
    Table(int numberOfSeats) : AbstractTable(numberOfSeats) {}
    //+ operator overload to add 2 tables and return a table group
    AbstractTable *operator+(Table *table)
    {
        TableGroup *newTableGroup = new TableGroup(this->getnumberOfSeats() + table->getnumberOfSeats());
        newTableGroup->addTable(this);
        newTableGroup->addTable(table);
        return newTableGroup;
    }
    //+ operator overload to add a table to a table group
    AbstractTable *operator+(TableGroup *tableGroup)
    {
        TableGroup *newTableGroup = new TableGroup(this->getnumberOfSeats() + tableGroup->getnumberOfSeats());
        newTableGroup->addTable(this);
        newTableGroup->addTable(tableGroup);
        return newTableGroup;
    }

    void acceptVisitor(Visitor visitor)
    {
        visitor.visitTable(this);
    }

    AbstractTable *clone()
    {
        Table *table = new Table(this->getnumberOfSeats());
    }
    
};

/*
    TableState is a state class that will be used to determine if the table is occupied or not
*/
class TableState
{
public:
    virtual std::string getState() = 0;
    virtual void handleState(AbstractTable *table) = 0;
};

class Unoccupied : public TableState
{
public:
    void handleState(AbstractTable *table)
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
    std::string getState()
    {
        return "Unoccupied";
    }
};
class Occupied : public TableState
{
public:
    void handleState(AbstractTable *table)
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
    std::string getState()
    {
        return "Occupied";
    }
};

#endif // PROJECT_TABLE_H
