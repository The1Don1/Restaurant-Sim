//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_TAB_H
#define PROJECT_TAB_H
#include <iostream>
#include "Floor.h"

/**
 * @brief The Tab class holds the running tab of a restaurant customer
 * 
 */
class Tab {
private:
    std::string name;
    double total;
public:
    Floor* floor;
    Tab(std::string customerName);
    std::string getName();
    double getTab();
    void addToTab(double);
    void subtractFromTab(double);
};


#endif //PROJECT_TAB_H
