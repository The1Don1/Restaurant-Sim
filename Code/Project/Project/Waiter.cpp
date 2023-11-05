#include "Waiter.h"
void Waiter::visitTable(Table *table)
{

    std::cout << "Visiting table " << table->getTableID() << std::endl;
}

void Waiter::prepareDish(Dish* dish)
{
    // headChef->prepareDish(dish);
    // Note, i need to indicate what dish to prepare and the only way to do that it to pass
    // the Dish object as a parameter to this function.
    std::cout << "Preparing dish..." << std::endl;

    headChef->getDishQueue().push(dish);
    //headChef->PrepareDish();
}

void Waiter::getOrders()
{
    waiterHeadTable->getOrders();
}

void Waiter::sendOrders()
{
    std::cout << "Sending order to table with table ID of " << waiterHeadTable->getTableID() << std::endl;
}

void Waiter::deliverOrder()
{
    std::cout << "Delivering order to table with table ID of " << waiterHeadTable->getTableID() << std::endl;
}

void generalWaiter::visitTable(Table occupiedTable)
{
    std::cout << "Visiting table " << occupiedTable.getTableID() << std::endl;
}

void generalWaiter::addToTab(std::string customerName, double amount)
{
    // need to be able to add the amount to a tab as well.
    for (auto tab : tabs)
    {
        if (tab->getName() == customerName)
        {
            tab->addToTab(amount);
        }
    }
}

void generalWaiter::payTab(std::string customerName, double amount)
{
    for (auto tab : tabs)
    {
        if (tab->getName() == customerName)
        {
            tab->payTab(amount);
            if (tab->getTabTotal() == 0)
            {
                tab->setPayedOff(true);
            }
            else
            {
                std::cout << "Tab for " << customerName << " is not fully payed off yet." << std::endl;
            }
        }
    }

    std::cout << "No tab found for " << customerName << std::endl;
}

Tab *generalWaiter::getTab(std::string customerName)
{
    for (auto tab : tabs)
    {
        if (tab->getName() == customerName)
        {
            std::cout << "Returning tab for " << customerName << std::endl;
            return tab;
        }
    }

    std::cout << "Tab for " << customerName << " is not found." << std::endl;

    return NULL;
}

void generalWaiter::performTask()
{
    std::cout << "General waiter is performing task..." << std::endl;
}

void MaitreD::checkReservation(int tableNo)
{
    std::cout << "Checking reservation..." << std::endl;

    Reserved* reserved = new Reserved();

    for (Table* table : waiterFloor->getFloorTables())
    {
        if (table->getTableID() == tableNo)
        {
            if (table->getTableState() == reserved)
            {
                std::cout << "Table " << tableNo << " has been reserved." << std::endl;
            }
            else
            {
                std::cout << "Table " << tableNo << " has not been reserved yet." << std::endl;
            }
        }
    }
}

void MaitreD::allocateTable(int partySize)
{
    std::cout << "Allocating table..." << std::endl;

    Occupied *occupied = new Occupied();

    Table *bestFitTable = NULL;
    int minExcessSeats = 15;

    for (Table *table : waiterFloor->getFloorTables())
    {
        int excessSeats = table->getCustomerNumber() - partySize;

        // Check if the table can accommodate the party and is not occupied
        if (excessSeats >= 0 && table->getTableState() != occupied && excessSeats < minExcessSeats)
        {
            bestFitTable = table;
            minExcessSeats = excessSeats;
        }
    }

    if (bestFitTable != NULL)
    {
        // If a suitable table is found, allocate it
        std::cout << "Allocating table " << bestFitTable->getTableID()
                  << ". Current table state: Occupied" << std::endl;

        Occupied *occupied = new Occupied();
        bestFitTable->setState(occupied);

        for (int i = 0; i <= partySize; i++)
            waitingList.pop();
    }
    else
    {
        // If no suitable table is found, merge tables
        std::cout << "No suitable table available for a party size of " << partySize << ". Merging tables..." << std::endl;

        for (int i = 0; i <= waiterFloor->getFloorTables().size(); i++)
        {
            int table1 = waiterFloor->getFloorTables()[i]->getCustomerNumber();

            for (int j = i + 1; j < waiterFloor->getFloorTables().size() - 1; j++)
            {
                int table2 = waiterFloor->getFloorTables()[j]->getCustomerNumber();

                if ((table1 + table2) >= partySize)
                {
                    mergeTables(table1, table2);
                    for (int i = 0; i <= partySize; i++)
                        waitingList.pop();

                    break;
                }
            }
        }
    }
}

void MaitreD::mergeTables(int table1, int table2)
{

    std::cout << "Merging table " << table1 << " with table " << table2 << std::endl;
    Table *merged = new Table(table1 + table2);
    waiterFloor->getFloorTables().push_back(merged);

    for (auto it = waiterFloor->getFloorTables().begin(); it != waiterFloor->getFloorTables().end(); /* no increment here */)
    {
        if ((*it)->getTableID() == table1 || (*it)->getTableID() == table2)
        {
            it = waiterFloor->getFloorTables().erase(it);
        }
        else
        {
            ++it;
        }
    }

    Occupied *occupied = new Occupied();

    merged->setState(occupied);
}

void MaitreD::splitTables(Waiter *waiter, int tableNumber)
{
    std::cout << "Splitting table " << tableNumber << " for waiter " << waiter->waiterName << std::endl;

    // Find the table to split
    std::vector<Table *>::iterator it;
    for (it = waiterFloor->getFloorTables().begin(); it != waiterFloor->getFloorTables().end(); ++it)
    {
        if ((*it)->getTableID() == tableNumber)
        {
            break;
        }
    }

    if (it != waiterFloor->getFloorTables().end())
    {
        // If the table is found, split it into two smaller tables
        Table *table1 = new Table(tableNumber / 2);
        Table *table2 = new Table(tableNumber / 2);

        // Add the new tables to the floor
        waiterFloor->getFloorTables().push_back(table1);
        waiterFloor->getFloorTables().push_back(table2);

        // Remove the original table from the floor
        waiterFloor->getFloorTables().erase(it);

        std::cout << "Table " << tableNumber << " has been split into two smaller tables." << std::endl;
    }
    else
    {
        std::cout << "Table " << tableNumber << " not found." << std::endl;
    }
}

void MaitreD::performTask()
{
    std::cout << "Maitre D is performing task..." << std::endl;
}

/* ---------Notes---------*/
/*
1. For the function, void Waiter::prepareDish(Dish* dish), i need the headchef to prepare the specific
dish, hence the prepareDish() function needs a parameter.


/* ------------Changes--------------*/
/*
1. Added a dish parameter for the function void Waiter::prepareDish(Dish* dish).
2. Added a partySize parameter for the function void MaitreD::allocateTable(int partySize) to 
indicate the party size that needs to be allocated to a table, and allowing us to allocate a big
enough table for them (or merge if necessary).
3. For checkReservation(), i included tableNo as a parameter to reference a specific tableID and 
check if that specific table has already been reserved or not.
4. Added a tabs vector to keep track of all the tabs. Each tab has a name and amount associated with
it.

*/