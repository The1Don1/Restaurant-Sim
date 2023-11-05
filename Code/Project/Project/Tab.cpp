//
// Created by mathe on 2023/10/31.
//

#include "Tab.h"
Tab::Tab(std::string customerName) {
    name = customerName;
    total = 0;
    payedOff = false;

}

std::string Tab::getName() {
    return this->name;
}


double Tab::getTabTotal() {
    return total;
}

void Tab::addToTab(double amount) {
    total = total + amount;
    
}