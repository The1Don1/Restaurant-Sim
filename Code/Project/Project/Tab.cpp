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

/* ------------Changes--------------*/
/*
1. Added a boolean member variable 'payedOff' to indicate whether the tab is payedOff or not.   
   Initially set to false;
2. Added the functions setPayedOff(), getPayedOff(), payTab() with parameters
3. Included a parameter for the addToTab function to add an amount to the tab.
*/

