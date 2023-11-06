//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_TABLEITERATOR_H
#define PROJECT_TABLEITERATOR_H
#include "Table.h"
class AbstractTable;
class Table;
class TableIterator{
public:
    AbstractTable* currTable;
    AbstractTable* head;
    virtual AbstractTable* next() = 0;
    virtual bool hasNext() = 0;
    virtual AbstractTable* first()
    {
        return head;
    }
    virtual AbstractTable* CurrentItem()
    {
        return currTable;
    }
};

class ConcreteTableIterator : public TableIterator{
public:
    AbstractTable* next();
    bool hasNext();
    ConcreteTableIterator(AbstractTable* aTable) : TableIterator(){
        this->currTable = aTable;
        head = aTable;
    }
};
#endif //PROJECT_TABLEITERATOR_H
