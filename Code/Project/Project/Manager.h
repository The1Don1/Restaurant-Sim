//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include <iostream>
#include <vector>
#include "Visitor.h"

class Manager: public Visitor
{
    private: 
        std::vector<std::string> complaints;

    public:
        virtual void visitTable(Customer* customer);
        std::vector<std::string> getComplaints();
        void handleComplaint(const std::string& complaint);

};


#endif //PROJECT_MANAGER_H
