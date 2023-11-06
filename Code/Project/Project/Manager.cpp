//
// Created by mathe on 2023/10/31.
//

#include "Manager.h"
void Manager::visitTable(Table* table) 
{
    std::string customerMood = table->getCustomers()[0]->getMood();
    if(customerMood == "extremely unsatisfied" || customerMood == " unsatisfied")
    {
        //make complaint and leave
        table->getCustomers()[0]->makeComplaint(this);
        table->getCustomers()[0]->leaveRestaurant(table->getBill(table->getCustomers()[0]));
    }
    else if (customerMood == "satisfied" || customerMood == "extremely satisfied")
    {
        //compliment and add tip
        std::string waiterCompliment = table->getCustomers()[0]->complimentWaiter();
        //table->getWaiter()->receiveCompliment(waiterCompliment);

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