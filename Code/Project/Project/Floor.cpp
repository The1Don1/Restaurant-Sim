//
// Created by mathe on 2023/10/30.
//

#include "Floor.h"
//using namespace std;

Table* Floor::constructTable(){
    Table* t = new Table(4);
    floorTables.push_back(t);
    std::cout << "Floor construct table" << std::endl;
    return t;
}

void Floor::constructWaiter(std::string name, Table* table){
    generalWaiter* g = new generalWaiter(name, this);
    std::cout << g->waiterName << " " << g->waiterWaitTime << std::endl;
    floorWaiters.push_back(g);
}

Table* Floor::destructTable(){
    return nullptr;
}

void Floor::Decrement() {
    for(auto & floorWaiter : floorWaiters){
        floorWaiter->decrementTimer();
    }
    for(auto & floorTable : floorTables){
        // floorTable->decrementTimer();
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
