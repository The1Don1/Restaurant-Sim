//
// Created by mathe on 2023/10/31.
//

#include "Tab.h"
Tab::Tab(std::string customerName) {
}

std::string Tab::getName() {
    return this->name;
}

double Tab::getTab() {
    return this->total;
}


void Tab::addToTab(double valueToAdd) {
    this->total += valueToAdd;
}

void Tab::subtractFromTab(double valueToSubtract)
{
    this->total -= valueToSubtract;
}
