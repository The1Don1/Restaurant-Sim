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

    std::random_device rd2;
    std::mt19937 gen2(rd2());
    std::uniform_int_distribution<int> distribution2(1, 5);
    int randItem;

    int randBool = distribution(gen);

    if(randBool)
    {
        randItem = distribution2(gen2);

        switch(randItem)
        {
            case 1:
                this->beverage = new CokeZero();
                break;
            case 2:
                this->beverage = new Coke();
                break;
            case 3:
                this->beverage = new Sprite();
                break;
            case 4:
                this->beverage = new StrawberryMilkshake();
                break;
            case 5:
                this->beverage = new BubblegumMilkshake();
                break;
        }
    }

    std::random_device rd3;
    std::mt19937 gen3(rd3());
    std::uniform_int_distribution<int> distribution3(1, 4);

    randBool = distribution(gen);

    if(randBool)
    {
        randItem = distribution3(gen3);

        switch(randItem)
        {
            case 1:
                this->starter = new OnionRings();
                break;
            case 2:
                this->starter = new ChickenWings();
                break;
            case 3:
                this->starter = new Chips();
                break;
            case 4:
                this->starter = new ChickenNuggets();
                break;
        }
    }

    std::random_device rd4;
    std::mt19937 gen4(rd4());
    std::uniform_int_distribution<int> distribution4(1, 8);

    randBool = distribution(gen);

    if(randBool)
    {
        randItem = distribution4(gen4);

        switch(randItem)
        {
            case 1:
                this->mainDish = new CheeseBurger();
                break;
            case 2:
                this->mainDish = new HotDog();
                break;
            case 3:
                this->mainDish = new MacAndCheese();
                break;
            case 4:
                this->mainDish = new BBQRibs();
                break;
            case 5:
                this->mainDish = new ChickenTenders();
                break;
            case 6:
                this->mainDish = new CheeseSteak();
                break;
            case 7:
                this->mainDish = new BBQSteak();
                break;
            case 8:
                this->mainDish = new BuffaloWings();
                break;
        }
    }
    
    randBool = distribution(gen);

    if(randBool)
    {
        randItem = distribution3(gen3);

        switch(randItem)
        {
            case 1:
                this->dessert = new Pancakes();
                break;
            case 2:
                this->dessert = new Donuts();
                break;
            case 3:
                this->dessert = new Waffles();
                break;
            case 4:
                this->dessert = new ChocolateBrownies();
                break;
        }
    }

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