//
// Created by mathe on 2023/10/31.
//

#include "Manager.h"
void Manager::visitTable(Table* table) 
{
    std::string customerMood = table->getCustomer()->getMood();
    if(customerMood == "extremely unsatisfied" || customerMood == " unsatisfied")
    {
        //make complaint and leave
        table->getCustomer()->makeComplaint(this);
        table->getCustomer()->leaveRestaurant(table->getBill(table->getCustomer()));
    }
    else if (customerMood == "satisfied" || customerMood == "extremely satisfied")
    {
        //compliment and add tip
        std::string waiterCompliment = table->getCustomer()->complimentWaiter();
        table->getWaiter()->receiveCompliment(waiterCompliment);

    }
}

std::vector<std::string> Manager::getComplaints() 
{
    return this->complaints;
}

void Manager::handleComplaint(const std::string& complaint)
{
    std::cout << "Restaurant Manager: Thank you for your feedback. We will address your complaint.\n";
    std::cout << "Complaint details: " << complaint << "\n";
}