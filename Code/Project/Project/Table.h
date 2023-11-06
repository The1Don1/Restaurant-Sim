//
// Created by mathe on 2023/10/30.
//

#ifndef PROJECT_TABLE_H
#define PROJECT_TABLE_H
#include <iostream>
#include "Customer.h"
#include "Table.h"
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
class TableGroup;
class AbstractTable {
public:
    explicit AbstractTable(int numberOfSeats) : numberOfSeats(numberOfSeats), tableID(5) {};
    virtual void acceptVisitor(Visitor* visitor) = 0;
    virtual AbstractTable *operator+(TableGroup *tableGroup) = 0;
    virtual AbstractTable *operator+(Table *table) = 0;
    virtual AbstractTable *clone() = 0;
    int getnumberOfSeats();
    int getTableID();
    std::vector<Customer *> getCustomers();
    void setState(TableState *tableState);
    TableState *getState();
    void handleState();
    Bill *getBill(Customer *customer);
    void setWaiter(Waiter *waiter);
    Waiter *getWaiter();
    void getOrders();
    //static int tableCount;
    AbstractTable *next;
protected:
    TableState *tableState;
    std::vector<Customer *> customers;
    Bill *bill;
    Waiter *waiter;
    int numberOfSeats;
    int tableID;
};

class TableGroup : public AbstractTable
{
private:
    std::vector<AbstractTable *> tables;
public:
    TableGroup(int numberOfSeats = 0) : AbstractTable(numberOfSeats) {};
    //~TableGroup();
    void addTable(AbstractTable *aTable);
    void acceptVisitor(Visitor* visitor);
    AbstractTable *operator+(TableGroup *tableGroup);
    AbstractTable *operator+(Table *table);
    AbstractTable *clone();
    std::vector<AbstractTable *> getTables();
};

class Table : public AbstractTable
{
public:
    Table(int numberOfSeats) : AbstractTable(numberOfSeats) {}
    AbstractTable *operator+(Table *table);
    AbstractTable *operator+(TableGroup *tableGroup);
    void acceptVisitor(Visitor* visitor);
    AbstractTable *clone();
    std::vector<Customer *> getCustomers();
    void setState(TableState *tableState);
    TableState *getState();
    void handleState();
    Bill *getBill(Customer *customer);
    void setWaiter(Waiter *waiter);
    Waiter *getWaiter();
    void getOrders();
    
};
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

#endif //PROJECT_TABLE_H