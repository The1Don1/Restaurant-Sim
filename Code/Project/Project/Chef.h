//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_CHEF_H
#define PROJECT_CHEF_H


#include "Visitor.h"
#include "Kitchen.h"
#include "Waiter.h"
#include "Dish.h"
//class Visitor;
class generalWaiter;
class Kitchen;
class Chef{
private:
    std::string role;
    Chef* nextChef;
public:

    Kitchen* kitchen;
    Chef* chef;
    Waiter* waiter;
    void visitTable(Table* table);
    std::string getRole();
    virtual void prepareDish(Dish dish) = 0;
    void setNextChef(Chef* chef);
};
class commisChef: public Chef
{

public: void visitTable(Table* table);

public: void prepareDish(Dish dish);

public: void notify();

public: void setNextChef(Chef* chef);
};
class ChefNotifier;
class HeadChef: public Chef{
private: std::queue<generalWaiter*> waiters;
private: std::queue<Dish*> dishQueue;
public: generalWaiter* waiter;
public: Dish* dish;

public: void visitTable(Table* table);

public: void prepareDish(Dish dish);

public: void notify(generalWaiter waiter);

public: void attach(generalWaiter* waiter);

public: void detach(generalWaiter* waiter);

public: void setNextChef(Chef* chef);

public: void takeOrder(generalWaiter& waiter, Dish* dish);
};

class ChefNotifier;
class Observer
{
public: ChefNotifier* chefNotifier;

public: virtual void deliverOrder() = 0;
};
class ChefNotifier{
private: Observer* waiters;
public: Observer* observer;

public: virtual void attach(Observer* observer) = 0;

public: virtual void detach(Observer* observer) = 0;

public: virtual void notify() = 0;
};

#endif //PROJECT_CHEF_H
