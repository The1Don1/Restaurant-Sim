//
// Created by mathe on 2023/10/30.
//

#include "Floor.h"
//using namespace std;

/**
 * @brief Construct a new Floor:: Floor object
*/
AbstractTable* Floor::constructTable(){
    srand((unsigned) time(NULL));
    int random = rand() % floorWaiters.size();
    std::cout << "Random waiter: " << random << std::endl;
    generalWaiter* waiter = floorWaiters.at(random);
    
    AbstractTable* t = new Table(random + 1);
    if(headTable == nullptr){
        headTable = t;
        headTable->setWaiter(waiter);
    }
    else{
        AbstractTable* temp = headTable;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = t;
        temp->setWaiter(waiter);
    }
    std::cout << "Floor construct table" << std::endl;
    std::cout << "AbstractTable ID: " << t->getTableID() << std::endl;
    
    return t;
}

/**
 * @brief Function to construct a waiter
*/
void Floor::constructWaiter(std::string name, HeadChef* hc){
    generalWaiter* g = new generalWaiter(name, hc, this);
    std::cout << g->waiterName << " " << g->waiterWaitTime << std::endl;
    floorWaiters.push_back(g);
}

/**
 * @brief Function to destruct a table
*/
AbstractTable* Floor::destructTable(){
    return nullptr;
}

/**
 * @brief Function to decrement the timer
*/
void Floor::Decrement() {
    for(auto & floorWaiter : floorWaiters){
        floorWaiter->decrementTimer();
    }
}

/**
 *  @brief Function to print the waiters
*/
void Floor::printWaiters()
{
    for(auto & floorWaiter : floorWaiters){
        std::cout << floorWaiter->waiterName << " " << floorWaiter->waiterWaitTime << std::endl;
    }
}

/**
 * @brief Function to get the tab
*/
Tab* Floor::getTab(std::string customerName) {
    throw "Not yet implemented";
}

/**
 * @brief Function to get the manager
*/
Manager* Floor::getManager() {
    return this->manager;
}

/**
 * @brief Function to set the manager
*/
void Floor::setManager(Manager* manager) {
    this->manager = manager;
}


void Floor::getManagerComplaints() {
    throw "Not yet implemented";
 }

/**
 * @brief Function to merge tables
*/
 void Floor::mergeTables(int t1, int t2)
 {
    std::cout << "Attempting to merge tables " << t1 << " and " << t2 << std::endl;

    AbstractTable *curr = headTable;
    AbstractTable *table1 = nullptr;
    AbstractTable *table2 = nullptr;

    while(curr != NULL)
    {
        if(curr->getTableID() == t1)
        {
            table1 = curr;
        }

        if(curr->getTableID() == t2)
        {
            table2 = curr;
        }
        
        curr = curr->next;
    }

    if(!(table1 != nullptr && table2 != nullptr))
    {
        std::cout << "One or both of the tables do not exist" << std::endl;
        return;
    }

    TableGroup *newTableGroup = new TableGroup(table1->getnumberOfSeats() + table2->getnumberOfSeats());
    newTableGroup->addTable(table1);
    newTableGroup->addTable(table2);

    curr = headTable;
    AbstractTable *prev = nullptr;

    while(curr != nullptr)
    {
        if(curr == table1)
        {
            if(prev == nullptr)
            {
                headTable = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
        }
        else if(curr == table2)
        {
            if(prev == nullptr)
            {
                headTable = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
        }

        prev = curr;
        curr = curr->next;
    }

    if(headTable == nullptr)
    {
        headTable = newTableGroup;
    }
    else
    {
        curr = headTable;

        while(curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = newTableGroup;
    }

    std::cout << "Table " << table1->getTableID() << " and table " << table2->getTableID() << " have been merged" << std::endl;

    newTableGroup->setWaiter(table1->getWaiter());
 }


/**
 * @brief Function to split tables
 * This function will only split tablegroup and not normal tables, It takes a tablegroup and splits it into its individual tables
 * @param table
 *  
*/

 void Floor::splitTables(TableGroup *table)
 {
    std::cout << "Attempting to split table " << table->getTableID() << std::endl;

    AbstractTable *curr = headTable;
    AbstractTable *prev = nullptr;

    while(curr != nullptr)
    {
        if(curr == table)
        {
            if(prev == nullptr)
            {
                headTable = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
        }

        prev = curr;
        curr = curr->next;
    }

    if(headTable == nullptr)
    {
        headTable = table->getTables().at(0);
    }
    else
    {
        curr = headTable;

        while(curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = table->getTables().at(0);
    }

    for(int i = 1; i < table->getTables().size(); i++)
    {
        curr = headTable;

        while(curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = table->getTables().at(i);
    }

    std::cout << "Table " << table->getTableID() << " has been split" << std::endl;
 }
