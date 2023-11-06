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
//class AbstractTable;
class AbstractTable {
public:
    explicit AbstractTable(int numberOfSeats) : numberOfSeats(numberOfSeats), tableID(5) {};
    virtual void acceptVisitor(Visitor visitor);
    // virtual AbstractTable *operator+(TableGroup *tableGroup);
    // virtual AbstractTable *operator+(Table *table);
    virtual AbstractTable *clone() = 0;
    int getnumberOfSeats();
    int getTableID();
    std::vector<Customer *> getCustomers();
    void setState(TableState *tableState);
    TableState *getState();
    void handleState();
    Bill *getBill(Customer *customer);
    void setWaiter(Waiter *waiter);
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

class TableGroup: public AbstractTable
{
private:
    std::vector<AbstractTable*> children;
public:
    AbstractTable* abstractiTable;

    void addTable(AbstractTable* aTable);
};

class Table : public AbstractTable{
private:
    int tableID;
    Table* up;
    Table* left;
    Table* down;
    Table* right;
    TableState* tableState;
    std::vector<Customer*> customers;
    Bill* bill;
    Customer* customer;
    AbstractTable* abstractTable;
    MaitreD* maD;
    Floor* floor;
    Waiter* waiter;
    ConcreteTableIterator* concreteTableIterator;
    public:
            Table(int numberOfSeats) : AbstractTable(numberOfSeats){}
            void addTable(AbstractTable* table){
                std::cout << "";
            }
            int getnumberOfSeats(){
                return 0;
            };
            void decrementTimer(){
                std::cout << "";
            };
            TableIterator* createIterator();
            void accept(Visitor* visitor);
            AbstractTable* clone() ;
            void acceptVisitor(Visitor visitor);
            void handleState();
            void changeTableState();
            void setState(TableState* state);
            Bill* getBill(Customer* customer);
            void getOrders();
    };
class TableState
{
public: Table* _unnamed_Table_;

public: std::string getState();

public: void handleState(Table* table);
};

class Unoccupied: public TableState
{

public: void handleState();

public: std::string getState();
};
class Occupied: public TableState
{

public: void acceptVisitor(Visitor visitor);

public: void handleState();

public: std::string getState();
};
class Reserved: public TableState
{

public: void handleState();

public: std::string getState();
};

#endif //PROJECT_TABLE_H
