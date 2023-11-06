//
// Created by mathe on 2023/10/30.
//

#include "Floor.h"
//using namespace std;

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

void Floor::constructWaiter(std::string name){
    generalWaiter* g = new generalWaiter(name, this);
    std::cout << g->waiterName << " " << g->waiterWaitTime << std::endl;
    floorWaiters.push_back(g);
}

AbstractTable* Floor::destructTable(){
    return nullptr;
}

void Floor::Decrement() {
    for(auto & floorWaiter : floorWaiters){
        floorWaiter->decrementTimer();
    }
}
void Floor::printWaiters(){
    for(auto & floorWaiter : floorWaiters){
        std::cout << floorWaiter->waiterName << " " << floorWaiter->waiterWaitTime << std::endl;
    }
}

Tab* Floor::getTab(std::string customerName) {
    throw "Not yet implemented";
}

Manager* Floor::getManager() {
    return this->manager;
}

void Floor::setManager(Manager* manager) {
    this->manager = manager;
}

void Floor::getManagerComplaints() {
    throw "Not yet implemented";
 }
