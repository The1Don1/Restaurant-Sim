//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_KITCHEN_H
#define PROJECT_KITCHEN_H
#include "Floor.h"
#include "Engine.h"
class Chef;
class Waiter;
class Engine;
class Dish;
class Kitchen {

private:
    std::vector<Dish*> order;
    Engine* engine;
    Chef* chef;
public:
    void receiveOrder(Waiter* aWaiter);
};


#endif //PROJECT_KITCHEN_H
