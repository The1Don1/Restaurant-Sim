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

class Chef
{
    protected:
        std::string role;
        Chef* nextChef;
        Table* currTable;

    public:
        Kitchen* kitchen;
        Chef* chef;
        Waiter* waiter;
        void VisitTable(Table* table);
        std::string GetRole();
        virtual void PrepareDish(Dish* dish) = 0;
        void SetNextChef(Chef* chef);
};

class commisChef: public HeadChef
{
    private:
        Dish* dish;
        HeadChef* headChef;

    public:
        commisChef(HeadChef* headChef);
        void PrepareDish(Dish* dish);
        void Notify();
};

class ChefNotifier;

class HeadChef: public Chef
{
    private:
        std::queue<generalWaiter*> waiters;
        std::queue<Dish*> dishQueue;
        std::queue<commisChef*> freeChefs;
        std::queue<commisChef*> busyChefs;

    public:
        generalWaiter* waiter;
        Dish* dish;

        HeadChef();
        void PrepareDish(Dish* dish);
        void addChef();
        void removeChef();
        void Notify(generalWaiter* waiter);
        void Attach(generalWaiter* waiter);
        void Detach();
};

class ChefNotifier;

class Observer
{
    public:
        ChefNotifier* chefNotifier;
        virtual void DeliverOrder() = 0;
};

class ChefNotifier
{
    private:
        Observer* waiters;
        Observer* observer;

    public:
        virtual void Attach(Observer* observer) = 0;
        virtual void Detach(Observer* observer) = 0;
        virtual void Notify() = 0;
};
#endif //PROJECT_CHEF_H