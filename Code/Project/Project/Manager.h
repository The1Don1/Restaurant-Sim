//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include <iostream>
#include <vector>
#include "Visitor.h"

class Manager
{
private: std::vector<std::string> complaints;

public: void visitTable(Table* table);

public: std::vector<std::string> getComplaints();
};


#endif //PROJECT_MANAGER_H
