#ifndef GENERALWAITER_H
#define GENERALWAITER_H

#include <iostream>
#include "Waiter.h"
using namespace std;

class Table;
class Tab;

class GeneralWaiter : public Waiter
{
    public:
        void visitOccupiedTable(Table* table);
        void addToTab(string name, double amount);
        void payTab(string name, double amount);
        Tab* getTab(string name, Tab* tabList[]);

};

#endif
