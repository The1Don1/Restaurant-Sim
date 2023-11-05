//
// Created by mathe on 2023/10/31.
//

#include "Manager.h"
void Manager::visitTable(Table* table) 
{
    CustomerMood* customerMood = table->cu
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