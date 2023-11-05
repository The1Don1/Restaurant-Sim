//
// Created by mathe on 2023/10/31.
//
#include "Chef.h"

void Chef::VisitTable(Table* table)
{
    this->currTable = table;
}

std::string Chef::GetRole()
{
    return this->role;
}

void Chef::SetNextChef(Chef* chef)
{
    this->nextChef = chef;
}

commisChef::commisChef(HeadChef* headChef)
{
    this->headChef = headChef;
    this->role = "commisChef";
    this->nextChef = NULL;
    this->currTable = NULL;
}

void commisChef::PrepareDish(Dish* dish)
{
    this->dish = dish;
}

void commisChef::Notify()
{
    this->headChef->Notify(this->headChef->waiter);
}

HeadChef::HeadChef()
{
    this->role = "HeadChef";
    this->nextChef = NULL;
    this->currTable = NULL;
}

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

void HeadChef::addChef()
{
    this->freeChefs.push(new commisChef(this));
}

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

void HeadChef::Notify(generalWaiter* waiter)
{
    waiter->deliverOrder();
}

void HeadChef::Attach(generalWaiter* waiter)
{
    this->waiters.push(waiter);
}

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