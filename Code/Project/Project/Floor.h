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

class AbstractTable;
class Manager;
class generalWaiter;
class Floor {
private:
    std::vector<generalWaiter*> floorWaiters;
    AbstractTable* headTable;
    Manager* manager;
    int floorCapacity;
    std::vector<Tab*> tabs;
public:
    AbstractTable* constructTable();
    AbstractTable* destructTable();
    void Decrement();
    ~Floor()= default;
    AbstractTable* getHeadTable(){
        return headTable;
    }
    void constructWaiter(std::string);
    void printWaiters();
    Tab* getTab(std::string aName);
    Manager* getManager();
    void setManager(Manager* aManager);
    void getManagerComplaints();
};


#endif //PROJECT_FLOOR_H
