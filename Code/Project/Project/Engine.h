//
// Created by mathe on 2023/10/30.
//
//Mediator: ConcreteMediator
#ifndef PROJECT_ENGINE_H
#define PROJECT_ENGINE_H
#include "Floor.h"
class Floor;
class Mediator {
private:
    Floor* floor;
public:
    void setFloor(Floor* f){
        this->floor = f;
    }
    void notify();
};
class Engine : public Mediator{
private:
    Floor* engineFloor;
public:
    void update();
};


#endif //PROJECT_ENGINE_H
