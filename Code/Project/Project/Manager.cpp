//
// Created by mathe on 2023/10/31.
//

#include "Manager.h"
void Manager::visitTable(Table* table) 
{
    CustomerMood* customerMood = table->cu
}

std::vector<std::string> Manager::getComplaints() {
    return this->complaints;
}


//manager needs to check customer's mood at that table
    CustomerMood* customerMood = customer->getMood();

    if(customerMood != NULL)
    {
        if(/*customerMood == || customerMood == */ )//extremely satisfied & satisfied, tip()
        {
            //ask if they want to tip and rate waiter heheh
            customer->tip();
        }
        else// extremely unsatisfied & unsatisfied, make a complaint
        {
            customer->makeComplaint();
        } 
    }