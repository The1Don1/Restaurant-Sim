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
#include "Chef.h"

class AbstractTable;
class Manager;
class generalWaiter;

/**
 * @brief Floor is responsible for managing the tables and waiters
 * 
 */
class Floor {
private:
    std::vector<generalWaiter*> floorWaiters;
    AbstractTable* headTable;
    Manager* manager;
    HeadChef* hc;
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
    void constructWaiter(std::string, HeadChef* hc);
    void printWaiters();
    Tab* getTab(std::string aName);
    Manager* getManager();
    void setManager(Manager* aManager);
    void getManagerComplaints();
    void mergeTables(int table1, int table2);
    void splitTables(TableGroup* table);
};


#endif //PROJECT_FLOOR_H
