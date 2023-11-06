#include "Table.h"
#include "Customer.h"
#include "Manager.h"


int main()
{
    /**
     * floor needs:
     *  manager
     *  tables
     *  maitreD (1)
     *  general waiters (need to decide on the number of the waiters... one per table)
     *  customers (1,2,4,8)
    */

   Floor* floor = new Floor();
   Manager* manager = new Manager();
   MaitreD* maitreD = new MaitreD();
   generalWaiter* gWaiter;
   HeadChef* headChef = new HeadChef();

   //create tables (prototype)
    Table* table = new Table(1);
    for(int i=0; i<20; i++)
    {
        table->clone(); //assuming clone() calls constructTable()
        gWaiter = new generalWaiter("Don't know what basic string is for", headChef, floor);
    }

    //starting with just one customer
    Customer* customer1 = new Customer("Chloe", 1, table);

    //customer needs to be allocated a table
    maitreD->allocateTable(customer1);
    

    //customer has table, the table needs to be sent to the waiter
    gWaiter->getAllocatedAtable(customer1->table);

    //that we have a waiter for the customer, we need to start with monitoring the customer
    
    customer1->setReadyToOrderStatus(true);
    customer1->placeOrder();
    

    //visitor design pattern
    //customer1->accept();
    return 0;
}


