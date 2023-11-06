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
#include <vector>
#include <ctime>

class Floor;
class Table;
class Tab;
class Customer;
class Kitchen;
class Waiter
{
private:
    Kitchen* kitchen;

public:
    Floor* waiterFloor;
    int waiterWaitTime;

    std::string waiterName;

    Table* waiterHeadTable;
//public: Chef* _unnamed_Chef_;
//public: Floor* _unnamed_Floor_;
//public: Engine* _unnamed_Engine_;
public: HeadChef* headChef;
    Waiter(std::string WaiterName, Table* waiterTable,  Floor* floor, Kitchen* kitchen) : waiterWaitTime(100), waiterName(std::move(WaiterName)), waiterHeadTable(waiterTable), waiterFloor(floor) {
        srand((unsigned) time(NULL));
        int random = 60 + (rand() % 2);
        this->waiterWaitTime = random;
        this->kitchen = kitchen;
    }
    virtual void performTask() = 0;
    void deliverOrder();

    void prepareDish();
//
    void getOrders();

    void sendOrders(std::vector<Dish*> dish);

};

//Template Method: Concrete Class
class generalWaiter : public Waiter
{
public:
    generalWaiter(std::string basicString, Table* t, Floor *pFloor, Kitchen* kitchen) : Waiter(basicString,t, pFloor, kitchen) {}
    void getAllocatedAtable(Table* table);
    void performTask();
    virtual void visitTable(Table* table);
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
//    void performTask(){}
//    void setWaiterHeadTable(Table *waiterHeadTable) {
//        this->waiterHeadTable = waiterHeadTable;
//    }
//    void setWaiterName(const std::string &waiterName) {
//        this->waiterName = waiterName;
//    }
//
//    void setWaiterWaitTime(int waiterWaitTime) {
//        this->waiterWaitTime = waiterWaitTime;
//    }
//    void setWaiterFloor(Floor *waiterFloor) {
//        this->waiterFloor = waiterFloor;
//    }
//    Tab* getTab(std::string aName);
};

//Template Method: Concrete Class
class MaitreD : public Waiter
{
private:
    std::queue<Customer*> waitingList;
public:
    MaitreD();
    void performTask();
    void allocateTable(Customer* customer);
    void checkReservation();
//
    void mergeTables(int table1, int table2);
//
    void splitTables(Waiter* waiter, int tableNo);

//    virtual Iterator* createIterator();

//    virtual void accept(Visitor* aVisitor);

//    virtual void addTable(AbstractTable* aTable);
};
#endif //PROJECT_WAITER_H
