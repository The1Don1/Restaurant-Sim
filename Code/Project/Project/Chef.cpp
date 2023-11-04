//
// Created by mathe on 2023/10/31.
//
#include "Chef.h"

void Chef::VisitTable(Table* table)
{
    throw "Not yet implemented";
}

std::string Chef::GetRole()
{
    return this->role;
}

void Chef::SetNextChef(Chef* chef)
{
    this->nextChef = chef;
}

commisChef::commisChef()
{
    this->role = "commisChef";
    this->nextChef = NULL;
    this->currTable = NULL;
}

void commisChef::VisitTable(Table* table)
{
    this->currTable = table;
}

void commisChef::PrepareDish(Dish dish)
{
    throw "Not yet implemented";
}

void commisChef::Notify()
{
    throw "Not yet implemented";
}

HeadChef::HeadChef()
{
    this->role = "HeadChef";
    this->nextChef = NULL;
    this->currTable = NULL;
}

void HeadChef::VisitTable(Table* table)
{
    this->currTable = table;
}

void HeadChef::PrepareDish(Dish dish)
{
    throw "Not yet implemented";
}

void HeadChef::Notify(generalWaiter waiter)
{
    throw "Not yet implemented";
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
        std::cout << "No more chefs left" << std::endl;
    }
}

void HeadChef::TakeOrder(generalWaiter& waiter, Dish* dish)
{
    throw "Not yet implemented";
}

