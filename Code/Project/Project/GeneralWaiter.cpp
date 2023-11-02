#include "GeneralWaiter.h"

void GeneralWaiter::visitOccupiedTable(Table* table)
{
    if (table->getOrderStatus() == false)
    {
        visitTable(table);
        getOrders();
    }
    else if (table->getOrderDelivered() == false)
    {
        visitTable(table);
        setOrders();
    }
    else
    {
        visitTable(table);
        prepareDish();
    }
}

void GeneralWaiter::addToTab(string name, double amount)
{
    Tab* tab = getTab(name);
    if (tab == NULL)
    {
        Tab* newTab = new Tab(name, amount);
        tabList.push_back(newTab);
    }
    else
    {
        tab->addToTab(amount);
    }
}

void GeneralWaiter::payTab(string name, double amount)
{
    Tab* tab = getTab(name);
    if (tab != NULL)
    {
        tab->payTab(amount);
    }
}

Tab* GeneralWaiter::getTab(string name, Tab* tabList[])
{
    for (int i = 0; i < tabList.size(); i++)
    {
        if (tabList[i]->getName() == name)
        {
            return tabList[i];
        }
    }
    return NULL;
}
