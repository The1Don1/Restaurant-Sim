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

class Dish
{
    private:
        DishStatus* prepareState;
        std::string customerName;
        int customerTable;
        Menu* beverage;
        Menu* starter;
        Menu* mainDish;
        Menu* dessert;
        
    public:
        Customer* customer;
        DishStatus* dishStatus;
        HeadChef* headChef;

        Dish(std::string customerName, int customerTable);
        void createDish();
        void dishState();
        DishStatus* getDishStatus();
        void change();
        void setDishStatus(DishStatus* state);
        std::string getCustomerName();
        void setCustomerName(std::string customerName);
        int getCustomerTable();
        void setCustomerTable(int customerTableID);
};

class DishStatus : public Dish
{
    public:
        DishStatus();
        virtual void updateDishStatus() = 0;
        void DishState();
        virtual std::string getStatus() = 0;
};

class Preparing: public DishStatus
{
    public:
        Preparing();
        void updateDishStatus();
        std::string getStatus();
};

class ReadyForPickUp: public DishStatus
{
    public:
        ReadyForPickUp();
        void updateDishStatus();
        std::string getStatus();
};

class StillQueued: public DishStatus
{
    public:
        StillQueued();
        void updateDishStatus();
        std::string getStatus();
};
#endif //PROJECT_DISH_H
