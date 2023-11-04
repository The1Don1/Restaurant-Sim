//
// Created by mathe on 2023/10/31.
//
#include "Dish.h"
#include <random>

Dish::Dish(std::string customerName, int customerTable)
{
    this->customerName = customerName;
    this->customerTable = customerTable;
    this->beverage = NULL;
    this->starter = NULL;
    this->mainDish = NULL;
    this->dessert = NULL;

    this->createDish();
}

void Dish::createDish()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 1);
    int randBool = distribution(gen);

    if(randBool)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(1, 5);

        int randBev = distribution(gen);

        /*switch(randBev)
        {
            case 1:
                this.be
                break;
            case 2:

                break;
            case 3:


                break;
            case 4:

                break;
            case 5:

                break;
        }*/
    }
    throw "Not yet implemented";
}

void Dish::dishState()
{
    throw "Not yet implemented";
}

DishStatus* Dish::getDishStatus()
{
    return this->dishStatus;
}

void Dish::change()
{
    throw "Not yet implemented";
}

void Dish::setDishStatus(DishStatus* state)
{
    this->dishStatus = state;
}

std::string Dish::getCustomerName()
{
    return this->customerName;
}

void Dish::setCustomerName(std::string customerName)
{
    this->customerName = customerName;
}

int Dish::getCustomerTable()
{
    return this->customerTable;
}

void Dish::setCustomerTable(int customerTableID)
{
    this->customerTable = customerTableID;
}

void DishStatus::DishState()
{
    throw "Not yet implemented";
}

void Preparing::updateDishStatus()
{
    this->setDishStatus(this);
}

std::string Preparing::getStatus()
{
    return "Preparing";
}

void ReadyForPickUp::updateDishStatus()
{
    this->setDishStatus(this);
}

std::string ReadyForPickUp::getStatus()
{
    return "Ready for Pick Up!";
}

void StillQueued::updateDishStatus()
{
    this->setDishStatus(this);
}

std::string StillQueued::getStatus()

{
    return "Still Queued";
}