#include "Waiter.h"
// void generalWaiter::visitTable(Table *table)
// {
//     throw "Not yet implemented";
// }


/**
 * @brief Gets the orders of all the customers and sends each to the head chef
 * use place order function of all customers at table
 * 
 */
void Waiter::getOrders() 
{
    
}

/**
 * @brief Send order function for the waiter class
 * This function sends all the customer orders to the head chef and
 * changes the state of the dishes sent to "preparing"
 * @param order 
 * 
 */
void Waiter::sendOrder(Dish* order) 
{
    order->setDishStatus(new Preparing);
    headChef->AddDish(order);
}

/**
 * @brief Delivers an order from the head chef to the relevant customer
 * 
 * @param order 
 */
void Waiter::deliverOrder(Dish* order) 
{
    AbstractTable* curr = waiterHeadTable;
    while(curr != NULL){
        if(curr->getTableID() == order->getCustomerTable())
        {
            for(auto customer : curr->getCustomers())
            {       
                if(customer->getName() == order->getCustomerName())
                {
                    customer->setReadyToPayStatus(true);
                    std::cout << "Waiter: " << this->waiterName << " delivered order to customer: " << order->getCustomerName();
                }
            }
        }
        curr = curr->next;
    }
}

/**
 * @brief Adds the total of the dish to the customers tab
 * 
 * @param customerName 
 * @param amount 
 */
void generalWaiter::addToTab(std::string customerName, double amount) 
{
    Tab* customerTab = this->waiterFloor->getTab(customerName);
    customerTab->addToTab(amount);
}

/**
 * @brief Deduct from the total of a customers tab
 * 
 * @param customerName 
 * @param amount 
 */
void generalWaiter::payTab(std::string customerName, double amount) 
{
    Tab* tabToBePaid = this->waiterFloor->getTab(customerName);
    tabToBePaid->subtractFromTab(amount);
}

/**
 * @brief Returns a reference to a customers tab
 * 
 * @param customerName 
 * @return Tab* 
 */
Tab* generalWaiter::getTab(std::string customerName) {
    return this->waiterFloor->getTab(customerName);
}

void generalWaiter::performTask() 
{
     std::cout << "Waiter: " << waiterName << " performing task \n";
}

void generalWaiter::visitTable(AbstractTable *table)
{
    std::cout << "Waiter: " << waiterName << " visiting table "<< table->getTableID() << "\n";
}

/**
 * @brief Allocate an available table to 1 or more customers 
 * 
 * @param customers 
 */
void MaitreD::allocateTable(std::vector<Customer*> customers) {
    AbstractTable* curr = this->waiterHeadTable;

    while(curr != NULL)
    {
        if(curr->getState() == new Unoccupied)
        {
            curr->setState(new Occupied);
            curr->setWaiter(this);
            curr->setCustomers(customers);

            for(auto customer : customers)
            {
                customer->assignCustomerTable(curr);
                customer->setReadyToOrderStatus(true);
            }

            break;
        }

        curr = curr->next;
    }
}

void MaitreD::mergeTables(int table1, int table2) {
    throw "Not yet implemented";
}

void MaitreD::splitTables(Waiter* waiter, int tableNumber) {
    throw "Not yet implemented";
}

void MaitreD::performTask() {
    std::cout << "Waiter: " << waiterName << " performing task\n";
}

void generalWaiter::receiveCompliment(const std::string& compliment)
{
    std::cout << "Waiter: Thank you for your kind words! I'm glad you enjoyed your dining experience.\n";
    std::cout << "Compliment details: " << compliment << "\n";
}