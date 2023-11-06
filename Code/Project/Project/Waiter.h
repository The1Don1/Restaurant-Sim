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

class Floor;
class AbstractTable;
class Tab;
class Customer;
class Waiter {
private:


public:
    Floor* waiterFloor;
    int waiterWaitTime;

    std::string waiterName;

    AbstractTable* waiterHeadTable;
    public: HeadChef* headChef;
        Waiter(std::string WaiterName,  Floor* floor) : waiterWaitTime(100), waiterName(std::move(WaiterName)), waiterFloor(floor) {
            srand((unsigned) time(NULL));
            int random = 60 + (rand() % 2);
            this->waiterWaitTime = random;
        }
        virtual void performTask() = 0;
        void deliverOrder();

        void visitTable(AbstractTable* table);

        void prepareDish();
//
        void getOrders();

        void sendOrders();

};

//Template Method: Concrete Class
class generalWaiter : public Waiter{
public:
    generalWaiter(std::string basicString, Floor *pFloor) : Waiter(basicString, pFloor) {}
    void performTask();
    void visitTable(AbstractTable* table);

    void addToTab(std::string name, double amount);

    void payTab(std::string name, double amount);
    Tab* getTab(std::string name);
    void decrementTimer(){
        if(this->waiterWaitTime <= 0){
            std::cout << this->waiterName << " time out resetting" << std::endl;
            srand((unsigned) time(NULL));
            int random =60 + (rand() % 2);
            this->waiterWaitTime = random;
        }else{
            this->waiterWaitTime-=1;

        }
    };
//    void performTask(){}
//    void setWaiterHeadTable(AbstractTable *waiterHeadTable) {
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
class MaitreD : public Waiter{
private:
    std::queue<Customer*> waitingList;
public:
    void performTask();
    void allocateTable();
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
