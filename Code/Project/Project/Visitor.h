//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_VISITOR_H
#define PROJECT_VISITOR_H
#include "Customer.h"
#include "Table.h"
class Customer; //just changed from Table (not sure why we need this)
class AbstractTable;
class Visitor
{
public:
    virtual void visitTable(AbstractTable*) ;
};
#endif //PROJECT_VISITOR_H
