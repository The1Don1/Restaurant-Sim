//
// Created by mathe on 2023/10/30.
//

#ifndef PROJECT_FACADE_H
#define PROJECT_FACADE_H


#include "Engine.h"
#include <chrono>
#include <thread>
/**
 * @brief acts as main interface for system/interface
 * 
 */
class Facade {
private:
    Facade* instance;
    Engine* mediator;
    Floor* floor;

public:
    /**
     * @brief Construct a new Facade object
     * 
     * @param f 
     * @param e 
     */
    Facade(Floor* f, Engine* e) : mediator(e), floor(f){
        e->setFloor(f);
    }
    /**
     * @brief notfy all related timers to decrement
     * 
     */
    void Decrement();
    /**
     * @brief show interface for users
     * 
     */
    void displayMenu();
    /**
     * @brief Create a Waiter object (template code)
     * 
     */
    void createWaiter();
    /**
     * @brief Get the Instance object or create if it doesn't exist
     * 
     * @param f 
     * @param e 
     * @return Facade* 
     */
    Facade* GetInstance(Floor* f, Engine* e){
        if(!instance){
            instance = new Facade(f, e);
        }
        return instance;
    }
    /**
     * @brief Construct a new Facade object
     * 
     */
    Facade();
    /**
     * @brief (template code)
     * 
     */
    void operation();
    /**
     * @brief Construct a new Facade object (template code)
     * 
     */
    Facade(std::string);
};


#endif //PROJECT_FACADE_H
