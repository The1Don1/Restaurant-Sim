//
// Created by mathe on 2023/10/31.
//
#include "Dish.h"
#include <random>

Dish* Dish::createDish()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 1);
    int randBool = distribution(gen);

    /*if(randBool)
    {
        
    }*/
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
    this->setDishStatus(new Preparing());
}

std::string Preparing::getStatus()
{
    return "Preparing";
}

void readyForPickUp::updateDishStatus()
{
    this->setDishStatus(new readyForPickUp());
}

std::string readyForPickUp::getStatus()
{
    return "Ready for Pick Up!";
}

void stillQueued::updateDishStatus()
{
    this->setDishStatus(new stillQueued());
}

std::string stillQueued::getStatus()
{
    return "Still Queued";
}