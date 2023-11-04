//
// Created by mathe on 2023/10/31.
//
#ifndef PROJECT_CHEF_H
#define PROJECT_CHEF_H

#include "Visitor.h"
#include "Kitchen.h"
#include "Waiter.h"
#include "Dish.h"
class Visitor;
class generalWaiter;

class Kitchen;

class Chef
{
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
    public:
        void visitTable(Table* table);
        void prepareDish(Dish dish);
        void notify();
        void setNextChef(Chef* chef);
};

class ChefNotifier;

class HeadChef: public Chef, public Visitor
{
    private:
        std::queue<generalWaiter*> waiters;
        std::queue<Dish*> dishQueue;

    public:
        generalWaiter* waiter;
        Dish* dish;
        void visitTable(Customer* customer);
        void prepareDish(Dish dish);
        void notify(generalWaiter waiter);
        void attach(generalWaiter* waiter);
        void detach(generalWaiter* waiter);
        void setNextChef(Chef* chef);
        void takeOrder(generalWaiter& waiter, Dish* dish);
};

class ChefNotifier;

class Observer
{
    public:
        ChefNotifier* chefNotifier;
        virtual void deliverOrder() = 0;
};

class ChefNotifier
{
    private:
        Observer* waiters;
        Observer* observer;

    public:
        virtual void attach(Observer* observer) = 0;
        virtual void detach(Observer* observer) = 0;
        virtual void notify() = 0;
};
#endif //PROJECT_CHEF_H