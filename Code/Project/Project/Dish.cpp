//
// Created by mathe on 2023/10/31.
//
#include "Dish.h"
#include <random>

/**
 * @brief Default Constructor for Dish Class
 * All attributes set to null, empty or 0
 * 
 */
Dish::Dish()
{
    this->customerName = "";
    this->customerTable = 0;
    this->beverage = NULL;
    this->starter = NULL;
    this->mainDish = NULL;
    this->dessert = NULL;
}

/**
 * @brief Constructor for Dish class that takes in arguments
 * Corresponding attributes are initialized to passed in arguments
 * remaining attributes are initialized by createDish function call
 * 
 * @param customerName 
 * @param customerTable 
 */
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

/**
 * @brief Initializes Dish class's Menu objects
 * randomly initializes the Menu attributes by using randomly generated numbers
 * not all Menu objects may be initialized
 * 
 */
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

/**
 * @brief Returns the current state of the dish
 * 
 * @return DishStatus* 
 */
DishStatus* Dish::getDishStatus()
{
    return this->dishStatus;
}

void Dish::change()
{
    throw "Not yet implemented";
}

/**
 * @brief set the status of the dish
 * sets the current status of the dish to the passed in parameter
 * 
 * @param state 
 */
void Dish::setDishStatus(DishStatus* state)
{
    this->dishStatus = state;
}

/**
 * @brief Returns the dish's customer name
 * Returns the name of the customer who ordered the dish
 * 
 * @return std::string 
 */
std::string Dish::getCustomerName()
{
    return this->customerName;
}

/**
 * @brief Returns the customer's table number
 * Returns the table number of the customer who ordered the dish
 * 
 * @return int 
 */
int Dish::getCustomerTable()
{
    return this->customerTable;
}

/**
 * @brief Default constructor for DishStatus base class
 * 
 */
DishStatus::DishStatus()
{}

void DishStatus::DishState()
{
    throw "Not yet implemented";
}

/**
 * @brief Default construct for DishStatus Preparing class
 * sets the status attribute accordingly
 * 
 */
Preparing::Preparing()
{
    this->status = "Preparing";
}

/**
 * @brief Update the dish's current status
 * Set the dish's status to the current DishStatus class
 * 
 */
void Preparing::updateDishStatus()
{
    this->setDishStatus(this);
}

/**
 * @brief Returns the current status of the dish
 * 
 * @return std::string 
 */
std::string Preparing::getStatus()
{
    return this->status;
}

/**
 * @brief Default construct for DishStatus ReadyForPickUp class
 * sets the status attribute accordingly
 * 
 */
ReadyForPickUp::ReadyForPickUp()
{
    this->status = "ReadyForPickUp";
}

/**
 * @brief Update the dish's current status
 * Set the dish's status to the current DishStatus class
 * 
 */
void ReadyForPickUp::updateDishStatus()
{
    this->setDishStatus(this);
}

/**
 * @brief Returns the current status of the dish
 * 
 * @return std::string 
 */
std::string ReadyForPickUp::getStatus()
{
    return this->status;
}

/**
 * @brief Default construct for DishStatus StillQueued class
 * sets the status attribute accordingly
 * 
 */
StillQueued::StillQueued()
{
    this->status = "StillQueued";
}

/**
 * @brief Update the dish's current status
 * Set the dish's status to the current DishStatus class
 * 
 */
void StillQueued::updateDishStatus()
{
    this->setDishStatus(this);
}

/**
 * @brief Returns the current status of the dish
 * 
 * @return std::string 
 */
std::string StillQueued::getStatus()
{
    return this->status;
}