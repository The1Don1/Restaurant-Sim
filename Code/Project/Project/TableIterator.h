//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_TABLEITERATOR_H
#define PROJECT_TABLEITERATOR_H
#include "Table.h"
class Table;
class ConcreteTableIterator;

class TableIterator{
public:
    virtual Table* next() = 0;
    virtual bool hasNext() = 0;
};
class ConcreteTableIterator : public TableIterator{
public:
    Table* table;
    Table* next();
    bool hasNext();
    ConcreteTableIterator();
};

#endif //PROJECT_TABLEITERATOR_H
