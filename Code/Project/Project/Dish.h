//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_DISH_H
#define PROJECT_DISH_H


#include "Menu.h"
#include "Customer.h"
class DishStatus;
class Customer;
class HeadChef;
class Menu;
class Dish {
private:
    Menu* order;
    DishStatus* prepareState;
    std::string customerName;
    int customerTable;
public:
    Customer* customer;
    DishStatus* dishStatus;
    HeadChef* headChef;
    Dish* createDish();
    void dishState();
    DishStatus* getDishStatus();
    void change();
    void setState(DishStatus* state);
    std::string getCustomerName();
    void setCustomerName(std::string customerName);
    int getCustomerTable();
    void setCustomerTable(int customerTableID);
};

class DishStatus
{
public:
    Dish* dish;
    virtual void updateDishStatus() = 0;
    void DishState();
    std::string getStatus();
};
class Preparing: public DishStatus
{

public: void updateDishStatus();

public: void getStatus();
};
class readyForPickUp: public DishStatus
{

public: void updateDishStatus();

public: void getStatus();
};
class stiiQueued: public DishStatus
{

public: void updateDishStatus();

public: void getStatus();
};
#endif //PROJECT_DISH_H
