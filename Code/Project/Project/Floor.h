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
class Floor {
private:
    std::vector<generalWaiter*> floorWaiters;
    std::vector<Table*> floorTables;
    Manager* manager;
    int floorCapacity;

public:
    Table* constructTable();
    Table* destructTable();
    void Decrement();
    ~Floor()= default;
    Table* getHeadTable(){
        return this->floorTables.front();
    }
    void constructWaiter(std::string name, Table* table);
    void printWaiters();
    Tab* getTab(std::string aName);
    Manager* getManager();
    void setManager(Manager* aManager);
    void getManagerComplaints();
    std::vector<Table*> getFloorTables()
    {
        return floorTables;
    }
};


#endif //PROJECT_FLOOR_H
