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
#include "Visitor.h"

class TableState;
class Bill;
class Floor;
class Waiter;
class MaitreD;
class Visitor;
class TableIterator;
class ConcreteTableIterator;
//class AbstractTable;
class AbstractTable 
{
    private:

        int customerNumber;
    public:
        explicit AbstractTable(int customerNumber) : customerNumber(customerNumber){}
        virtual TableIterator* createIterator() = 0;
        virtual void accept(Visitor* visitor) = 0;
        virtual void addTable(AbstractTable* table) = 0;
        virtual AbstractTable* clone() = 0;
};

class ConcreteTable: public AbstractTable
{
    public: AbstractTable* clone();
};

class TableGroup: public AbstractTable
{
    private:
        std::vector<AbstractTable*> children;
    public:
        AbstractTable* abstractiTable;

        void addTable(AbstractTable* aTable);
};

class Table : public AbstractTable
{
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
    generalWaiter* waiter;
    ConcreteTableIterator* concreteTableIterator;
    public:
            Table(int customerNumber) : AbstractTable(customerNumber){}
            void addTable(AbstractTable* table){
                std::cout << "";
            }
            int getCustomerNumber(){
                return 0;
            };
            void decrementTimer()
            {
                std::cout << "";
            };
            TableIterator* createIterator();
            void accept(Visitor* visitor);
            AbstractTable* clone() ;
            void acceptVisitor(Visitor* visitor);
            void handleState();
            void changeTableState();
            void setState(TableState* state);
            Bill* getBill(Customer* customer);
            void getOrders();
            Customer* getCustomer();
            generalWaiter* getWaiter();
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

public: void acceptVisitor(Visitor* visitor);

public: void handleState();

public: std::string getState();
};
class Reserved: public TableState
{

public: void handleState();

public: std::string getState();
};


#endif //PROJECT_TABLE_H
