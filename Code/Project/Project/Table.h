#ifndef PROJECT_TABLE_H
#define PROJECT_TABLE_H
#include <iostream>
#include "Customer.h"
#include "Floor.h"
#include "TableIterator.h"

class TableState;
class Bill;
class Floor;
class Waiter;
class MaitreD;
class Visitor;
class TableIterator;
class ConcreteTableIterator;
//class AbstractTable;

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
    void handleState(AbstractTable *table);
    std::string getState();
};
class Occupied : public TableState
{
public:
    void handleState(AbstractTable *table);
    std::string getState();
};

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
    virtual ~AbstractTable();
    int getnumberOfSeats();
    int getTableID();
    std::vector<Customer *> getCustomers();
    void setState(TableState *tableState);
    TableState *getState();
    void handleState();
    Bill *getBill(Customer *customer);
    void setWaiter(Waiter *waiter);
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
    ~TableGroup();
    void addTable(AbstractTable *aTable);
    void acceptVisitor(Visitor visitor);
    AbstractTable *operator+(TableGroup *tableGroup);
    AbstractTable *operator+(Table *table);
    AbstractTable *clone();
    std::vector<AbstractTable *> getTables();
};

/*
    Table is a leaf class that will be a single table
*/
class Table : public AbstractTable
{
public:
    Table(int numberOfSeats) : AbstractTable(numberOfSeats) {}
    AbstractTable *operator+(Table *table);
    AbstractTable *operator+(TableGroup *tableGroup);
    void acceptVisitor(Visitor visitor);
    AbstractTable *clone();
    
};

#endif // PROJECT_TABLE_H
