#include "Waiter.h"
/**
 * @brief Gets the orders of all the customers and sends each to the head chef
 * use place order function of all customers at table
 * 
 */
void Waiter::getOrder(Dish* customerOrder) 
{
    sendOrder(customerOrder);
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
    std::cout << "Waiter: " << this->waiterName << " sending order to head chef \n";
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
    std::cout << "Waiter: " << this->waiterName << " delivering order to customer: " << order->getCustomerName() << "\n";
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
    std::cout << "Waiter: " << this->waiterName << " adding to " << customerName << "'s tab \n";
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
            std::cout << "MaitreD: " << waiterName << " allocating table to customer(s): ";
            //Loop throgh each customers names and write to console, if the last customer is reached 
            //add a full stop after printing the name else print a comma
            for(auto customer : customers)
            {
                std::cout << customer->getName();
                if(customer != customers.back())
                {
                    std::cout << ", ";
                }
                else
                {
                    std::cout << ".\n";
                }
            }
            curr->setState(new Occupied);
            curr->setWaiter(this);
            curr->setCustomers(customers);

            for(auto customer : customers)
            {
                customer->assignCustomerTable(curr);
                customer->setReadyToOrderStatus(true);
                getOrder(customer->placeOrder());
            }

            break;
        }

        curr = curr->next;
    }
}

/**
 * @brief Merge 2 tables together
 * 
 * @param table1 
 * @param table2 
 */
void MaitreD::mergeTables(int table1, int table2) {
    this->waiterFloor->mergeTables(table1, table2);
}

/**
 * @brief Split a table into 2
 * 
 * @param table 
 */
void MaitreD::splitTables(TableGroup* table) {
    this->waiterFloor->splitTables(table);
}

/**
 * @brief Constructor for the MaitreD class
 * 
 */
void MaitreD::performTask() {
    std::cout << "Waiter: " << waiterName << " performing task\n";
}

/**
 * @brief Constructor for the MaitreD class
 * 
 */
void generalWaiter::receiveCompliment(const std::string& compliment)
{
    std::cout << "Waiter: Thank you for your kind words! I'm glad you enjoyed your dining experience.\n";
    std::cout << "Compliment details: " << compliment << "\n";
}