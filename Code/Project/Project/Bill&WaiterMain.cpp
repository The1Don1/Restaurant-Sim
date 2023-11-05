#include "Bill.h"
#include "Waiter.h"
#include "Floor.h"
#include "Table.h"

int main() {
    // Create a Floor
    Floor* floor;

    // Create a Table
    Table* table = new Table(01);

    // Create a generalWaiter
    generalWaiter* waiter = new generalWaiter("John", table, floor);

    // Test generalWaiter methods
    waiter->performTask();
    waiter->visitTable(*table);
    waiter->addToTab("Customer1", 100.0);
    waiter->payTab("Customer1", 50.0);
    waiter->getTab("Customer1");
    waiter->decrementTimer();

    // Create a MaitreD
    MaitreD* maitreD;

    // Test MaitreD methods
    maitreD->performTask();
    maitreD->allocateTable();
    maitreD->checkReservation();
    maitreD->mergeTables(1, 2);
    maitreD->splitTables(waiter, 1);

    // Create a BillItem
    BillItem* billItem = new BillItem(100.0, "Pizza", 100.0);

    // Test BillItem methods
    billItem->paymentMethod();
    std::cout << "Total cost: " << billItem->getTotalCost() << std::endl;

    // Create a SubBill and add it to the BillItem
    SubBill* subBill;
    BillItem* item = new BillItem(50.0, "Drink", 50.0);
    subBill->addItem(*item);

    // Test SubBill methods
    subBill->paymentMethod();
    std::cout << "Total cost: " << subBill->getTotalCost() << std::endl;

    // Create a BillDecorator
    BillDecorator* billDecorator = new BillDecorator(billItem);

    // Test BillDecorator methods
    std::cout << "Total cost: " << billDecorator->getTotalCost() << std::endl;

    // Create a CustomTipDecorator
    CustomTipDecorator* customTipDecorator = new CustomTipDecorator(billItem, 20.0);

    // Test CustomTipDecorator methods
    std::cout << "Total cost: " << customTipDecorator->getTotalCost() << std::endl;

    // Create a PaymentStrategy
    PaymentStrategy* paymentStrategy = new Card();

    // Test PaymentStrategy methods
    paymentStrategy->paymentMethod();

    // Clean up
    delete waiter;
    delete maitreD;
    delete table;
    delete floor;
    delete billItem;
    delete subBill;
    delete billDecorator;
    delete customTipDecorator;
    delete paymentStrategy;

    return 0;
}

/*
Expected output:

Performing task...
Visiting table 1
Adding 100 to Customer1's tab.
Customer1 is paying 50 from their tab.
Getting Customer1's tab.
John time out resetting
Performing task...
Allocating table...
Checking reservation...
Merging table 1 and table 2
Splitting table 1 for waiter John
Payment method: BillItem
Total cost: 100
Payment method: SubBill
Total cost: 50
Total cost: 100
Total cost: 120
Payment method: Card

*/