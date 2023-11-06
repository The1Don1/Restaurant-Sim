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

/**
 * @brief Dish class definition
 * each Dish consists of multiple menu objects as well as
 * the customer's name, their table and the state of the dish
 * once it is being prepared
 * 
 */
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

/**
 * @brief DishStatus base class, inherits from Dish
 * There are 3 different DishStatus classes: Preparing, ReadyForPickUp and StillQueued
 * each DishStatus updates a dish's status to their corresponding class
 * 
 */
class DishStatus : public Dish
{
    public:
        virtual void updateDishStatus() = 0;
        void DishState();
        virtual std::string getStatus() = 0;
};

/**
 * @brief DishStatus Preparing class
 * used to indicate when a dish is still being prepared
 */
class Preparing: public DishStatus
{
    public:
        void updateDishStatus();
        std::string getStatus();
};

/**
 * @brief DishStatus ReadyForPickUp class
 * used to indicate when a dish is ready to be picked up
 * 
 */
class ReadyForPickUp: public DishStatus
{
    public:
        void updateDishStatus();
        std::string getStatus();
};

/**
 * @brief DishStatus StillQueued class
 * used to indicate when a dish has yet to begin preparation
 * 
 */
class StillQueued: public DishStatus
{
    public:
        void updateDishStatus();
        std::string getStatus();
};
#endif //PROJECT_DISH_H
