//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_TAB_H
#define PROJECT_TAB_H
#include <iostream>
#include "Floor.h"

class Tab {
    private:
        std::string name;
        double total;
        bool payedOff;
    public:
        Floor* floor;
        Tab(std::string customerName);
        std::string getName();
        double getTabTotal();
        void addToTab(double amount);
        void payTab(double amount)
        {
            total = total - amount;
        }
        void setPayedOff(bool payed)
        {
            this->payedOff = payed;
        }
        bool getPayedOff()
        {
            return payedOff;
        }
};


#endif //PROJECT_TAB_H
