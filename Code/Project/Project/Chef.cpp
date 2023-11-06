//
// Created by mathe on 2023/10/31.
//
#include "Chef.h"

/**
 * @brief assigns a table to a chef when they visit it
 * 
 * @param table 
 */
void Chef::VisitTable(Table* table)
{
    this->currTable = table;
}

/**
 * @brief returns what type of chef a specific chef object is, commis or Head
 * 
 * @return std::string 
 */
std::string Chef::GetRole()
{
    return this->role;
}

/**
 * @brief sets the next chef after the current chef who 
 * will carry on the flow of the system
 * 
 * @param chef 
 */
void Chef::SetNextChef(Chef* chef)
{
    this->nextChef = chef;
}

/**
 * @brief Construct a new commisChef object
 * takes a HeadChef object as a parameter to set the 
 * headChef of the commisChef as the passed in HeadChef
 * 
 * @param headChef 
 */
commisChef::commisChef(HeadChef* headChef)
{
    this->headChef = headChef;
    this->role = "commisChef";
    this->nextChef = NULL;
    this->currTable = NULL;
}

/**
 * @brief Have a commisChef start preparing a dish
 * assign a dish to commisChef who will be the one preparing it
 * 
 * @param dish 
 */
void commisChef::PrepareDish(Dish* dish)
{
    this->dish = dish;
}

/**
 * @brief Notify the HeadChef that the dish is complete and
 *  ready for delivery
 * Calls HeadChef's Notify function
 * 
 */
void commisChef::Notify()
{
    this->headChef->Notify(this->headChef->waiter);
}

/**
 * @brief Construct a new HeadChef object
 * Set role to "HeadChef"
 * nextChef and currTable set to NULL
 * 
 */
HeadChef::HeadChef()
{
    this->role = "HeadChef";
    this->nextChef = NULL;
    this->currTable = NULL;
}

/**
 * @brief add a dish to the dishQueue
 * enqueues a dish object to HeadChef's dishQueue
 * 
 * @param d 
 */
void HeadChef::AddDish(Dish* d)
{
    this->dishQueue.push(d);
}

/**
 * @brief gives a dish to a commisChef to prepare
 * dequeues a dish object from HeadChef's dishQueue and
 *  assigns a commisChef to start preparing it
 * 
 * @param dish 
 */
void HeadChef::PrepareDish(Dish* dish)
{
    if(this->dishQueue.size() > 0)
    {
        commisChef* chef;

        if(this->freeChefs.size() > 0)
        {
            chef = this->freeChefs.front();
            this->freeChefs.pop();
            chef->PrepareDish(dish);
            this->busyChefs.push(chef);
        }
        else
        {
            std::cout << "There are no chefs available" << std::endl;
        }
    }
    else
    {
        std::cout << "There are no orders waiting to be made" << std::endl;
    }
}

/**
 * @brief add a chef to the kitchen
 * adds a commisChef object to HeadChef's freeChefs commisChef queue
 * 
 */
void HeadChef::addChef()
{
    this->freeChefs.push(new commisChef(this));
}

/**
 * @brief remove a chef from the kitchen
 * remove a commisChef object from HeadChef's freeChefs commisChef queue
 * 
 */
void HeadChef::removeChef()
{
    if(this->freeChefs.size() > 0)
    {
        this->freeChefs.pop();
    }
    else
    {
        std::cout << "There's no one left to fire" << std::endl;
    }
}

/**
 * @brief notify a waiter an order is ready to be delivered
 * call the passed in generalWaiter object's deliverOrder object
 * to deliver a finished order to the appropriate table
 * 
 * @param waiter 
 */
void HeadChef::Notify(generalWaiter* waiter)
{
    waiter->deliverOrder();
    commisChef* chef = this->busyChefs.front();
    this->busyChefs.pop();
    this->freeChefs.push(chef);
}

/**
 * @brief add a new generalWaiter
 * attach a new generalWaiter object to the HeadChef's generalWaiter queue
 * 
 * @param waiter 
 */
void HeadChef::Attach(generalWaiter* waiter)
{
    this->waiters.push(waiter);
}

/**
 * @brief remove a generalWaiter
 * remove a generalWaiter object from HeadChef's generalWaiter queue
 * 
 */
void HeadChef::Detach()
{
    if(this->waiters.size() > 0)
    {
        return waiters.pop();
    }
    else
    {
        std::cout << "No more waiters left" << std::endl;
    }
}