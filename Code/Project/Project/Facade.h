//
// Created by mathe on 2023/10/30.
//

#ifndef PROJECT_FACADE_H
#define PROJECT_FACADE_H


#include "Engine.h"
#include <chrono>
#include <thread>
class Facade {
private:
    Facade* instance;
    Engine* mediator;
    Floor* floor;

public:

    Facade(Floor* f, Engine* e) : mediator(e), floor(f){
        e->setFloor(f);
    }
    void Decrement();
    void displayMenu();
    void createWaiter();
    Facade* GetInstance(Floor* f, Engine* e){
        if(!instance){
            instance = new Facade(f, e);
        }
        return instance;
    }
    Facade();
    void operation();
    Facade(std::string);
};


#endif //PROJECT_FACADE_H
