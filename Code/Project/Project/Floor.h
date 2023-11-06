//
// Created by mathe on 2023/10/30.
//
//Mediator: concreteColleague
#ifndef PROJECT_FLOOR_H
#define PROJECT_FLOOR_H
#include <iostream>
#include <vector>
#include "Customer.h"
#include "Waiter.h"
#include "Table.h"
#include "Tab.h"
#include "Manager.h"

class Table;
class Manager;
class generalWaiter;
class TableIterator;
class ConcreteTableIterator;
class Floor {
private:
    std::vector<generalWaiter*> floorWaiters;
    AbstractTable* headTable;
    Manager* manager;
    int floorCapacity;
    std::vector<Tab*> tabs;
public:
    Floor(int capacity = 4) : floorCapacity(capacity) {
        for (int i = 0; i < capacity; i++)
        {
            std::string name = "Waiter" + std::to_string(i);
            // Waiter* w = new generalWaiter(name, this);
        }
        for (int i = 0; i < capacity; i++)
        {
            this->headTable = constructTable();
        }
    }
    AbstractTable* constructTable();
    virtual ~Floor();
    void Decrement();
    AbstractTable* getHeadTable(){
        return this->headTable;
    }
    TableIterator* createIterator(){
        ConcreteTableIterator* iterator = new ConcreteTableIterator();//this->headTable);
        return iterator;
    }
    void constructWaiter(std::string name, AbstractTable* table);
    void printWaiters();
    Tab* getTab(std::string aName);
    void storeTab(Tab* aTab);
    Manager* getManager();
    void setManager(Manager* aManager);
    void getManagerComplaints();
};


#endif //PROJECT_FLOOR_H
