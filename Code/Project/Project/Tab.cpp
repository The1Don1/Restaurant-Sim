//
// Created by mathe on 2023/10/31.
//

#include "Tab.h"
Tab::Tab(std::string customerName) {
}

/**
 * @brief Returns the customer name assosiated with this tab
 * 
 * @return std::string 
 */
std::string Tab::getName() {
    return this->name;
}

/**
 * @brief Returns the running total for this tab
 * 
 * @return double 
 */
double Tab::getTab() {
    return this->total;
}

/**
 * @brief Adds valueToAdd to the current tab
 * 
 * @param valueToAdd 
 */
void Tab::addToTab(double valueToAdd) {
    this->total += valueToAdd;
}

/**
 * @brief Deducts valueToSubtract from current tab
 * 
 * @param valueToSubtract 
 */
void Tab::subtractFromTab(double valueToSubtract)
{
    this->total -= valueToSubtract;
}
