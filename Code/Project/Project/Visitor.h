//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_VISITOR_H
#define PROJECT_VISITOR_H
#include "Table.h"
class Table;
class Visitor {
public:
    void visitTable(Table* table);
};


#endif //PROJECT_VISITOR_H
