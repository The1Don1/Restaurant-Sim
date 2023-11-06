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
    std::cout << "Table ID: " << t->getTableID() << std::endl;
    
    return t;
}

void Floor::constructWaiter(std::string name, AbstractTable* table){
    generalWaiter* g = new generalWaiter(name, this);
    floorWaiters.push_back(g);
    std::cout << "Waiter constructed" << std::endl;
    std::cout << g->waiterName << std::endl;
}

Floor::~Floor() {
    for(auto & floorWaiter : floorWaiters){
        delete floorWaiter;
    }
    if(headTable != nullptr){
        AbstractTable* temp = headTable;
        while(temp != nullptr){
            AbstractTable* next = temp->next;
            delete temp;
            temp = next;
        }
    }
}
// void Floor::Decrement() {
//     for(auto & floorWaiter : floorWaiters){
//         floorWaiter->decrementTimer();
//     }
//     for(auto & floorTable : floorTables){
//         floorTable->decrementTimer();
//     }
// }
void Floor::printWaiters(){
    for(auto & floorWaiter : floorWaiters){
        std::cout << floorWaiter->waiterName << std::endl;
    }
}

Tab* Floor::getTab(std::string customerName) {
    for(auto & tab : tabs){
        if(tab->getName() == customerName){
            return tab;
        }
    }
    return nullptr;
}

void Floor::storeTab(Tab* aTab) {
    tabs.push_back(aTab);
}

Manager* Floor::getManager() {
    return this->manager;
}

void Floor::setManager(Manager* manager) {
    this->manager = manager;
}

void Floor::getManagerComplaints() {
    manager->getComplaints();
}