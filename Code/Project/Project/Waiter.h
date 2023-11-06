//
// Created by mathe on 2023/10/30.
//
//Template Method: Abstract Class
#ifndef PROJECT_WAITER_H
#define PROJECT_WAITER_H
#include <iostream>
#include <queue>
#include <utility>
#include "Floor.h"
#include "Chef.h"
#include "Visitor.h"
#include <ctime>

class Floor;
class AbstractTable;
class Table;
class TableGroup;
class Tab;
class Customer;

/**
 * @brief Waiters are responsible for serving customers
 * 
 */
class Waiter
{
private:


public:
    Floor* waiterFloor;
    int waiterWaitTime;
    HeadChef* headChef;
    std::string waiterName;

    AbstractTable* waiterHeadTable;
public: 
    Waiter(std::string WaiterName,  HeadChef* hc, Floor* floor) : headChef(hc), waiterName(std::move(WaiterName)), waiterFloor(floor) {
        srand((unsigned) time(NULL));
        int random = 60 + (rand() % 2);
        this->waiterWaitTime = random;
    }
    virtual void performTask() = 0;
    void deliverOrder(Dish* dish);
//
    void getOrder(Dish* dish);

    void sendOrder(Dish*);

};

/**
 * @brief GeneralWaiter is responsible for serving customers
 * 
 */
class generalWaiter : public Waiter
{
public:
    generalWaiter(std::string basicString, HeadChef* hc, Floor *pFloor) : Waiter(basicString, hc, pFloor) {}
    void getAllocatedAtable(Table* table);
    void performTask();
    virtual void visitTable(AbstractTable* table);
    void addToTab(std::string name, double amount);
    void payTab(std::string name, double amount);
    Tab* getTab(std::string name);
    void decrementTimer()
    {
        if(this->waiterWaitTime <= 0){
            std::cout << this->waiterName << " time out resetting" << std::endl;
            srand((unsigned) time(NULL));
            int random =60 + (rand() % 2);
            this->waiterWaitTime = random;
        }else{
            this->waiterWaitTime-=1;

        }
    };

    void receiveCompliment(const std::string& compliment);
};

/**
 * @brief MaitreD is responsible for allocating tables to customers
 * 
 */
class MaitreD : public Waiter
{
private:
    std::queue<Customer*> waitingList;
public:
    MaitreD();
    void performTask();
    void allocateTable(std::vector<Customer*>);
    void mergeTables(int table1, int table2);
    void splitTables(TableGroup* tableGroup);
};
#endif //PROJECT_WAITER_H
