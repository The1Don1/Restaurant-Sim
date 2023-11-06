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

class Table;

class Kitchen;

/**
 * @brief Chef base class
 * Chef classes are commisChef and HeadChef
 */
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

class ChefNotifier;

class commisChef;

/**
 * @brief HeadChef class
 * HeadChef delegates making of dishes to commisChef class
 * HeadChef can also add and remove commisChefs as necessary
 * commisChefs given dishes are moved from a freeChef to a busyChefs queue
 * once a dish is complete commisChef is moved back to freeChefs
 */
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
        void AddDish(Dish* d);
        void PrepareDish(Dish* dish);
        void addChef();
        void removeChef();
        void Notify(generalWaiter* waiter);
        void Attach(generalWaiter* waiter);
        void Detach();
};

/**
 * @brief commisChef class
 * commisChef is responsible for making dishes given to them by their HeadChef
 * once a given a dish a commisChef 
 */
class commisChef: public Chef
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