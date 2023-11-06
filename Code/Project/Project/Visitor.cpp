#include "Visitor.h"
//
// Created by mathe on 2023/10/31.
//

/*#include "Visitor.h"

void Visitor::visitTable(Table *table) {

}*/
void Visitor::visitTable(AbstractTable *table)
{
    std::cout << "Table ID: " << std::endl;
}
