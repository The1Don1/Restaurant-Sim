#include "TableIterator.h"

AbstractTable* ConcreteTableIterator::next() 
{
    currTable = currTable->next;
    return currTable;
}

bool ConcreteTableIterator::hasNext()
{
    return currTable->next != nullptr;
}

ConcreteTableIterator::ConcreteTableIterator(AbstractTable* aTable) 
{
    this->currTable = aTable;
}

