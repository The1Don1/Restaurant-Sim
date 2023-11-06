//
// Created by mathe on 2023/10/30.
//

#include <iostream>
#include "Customer.h"

/**
 * @brief Construct a new Customer:: Customer object
 * 
 * @param customerName 
 * @param tableNum 
 * @param table 
 */
Customer::Customer(std::string customerName, int tableNum, Table* table)
{
    order = nullptr;
    readyToPay = false;
    readyToOrder = false;
    readyToLeave = false;
    name = customerName;
    this->tableNum = tableNum;
    myTable = table;
}


/**
 * @brief Destroy the Customer:: Customer object
 * 
 */
Customer::~Customer()
{
    delete this;
}

/**
 * @brief Method gets called when customer is ready to pay
 * need to choose method of payment (strategy design pattern) 
 * @param aMethodOfPayment 
 */
void Customer::pay(PaymentStrategy* aMethodOfPayment)
{
    aMethodOfPayment->paymentMethod();
}

/**
 * @brief Sets the customer mood
 * 
 * @param cstmrMood 
 */
void Customer::setMood(std::string cstmrMood)
{
    customerMood = cstmrMood;
}

/**
 * @brief  Method is called when the customer is ready to leave the restaurant
 * acts as the constructor (conditional)
 * 
 * @param bill 
 */
void Customer::leaveRestaurant(Bill* bill)
{
    this->readyToLeave = true;
    //make payment
    if(bill->getTotalCost() != 0.0 && customerComplaint == "")
    {
        std::cout << this->name << " please settle bill before you leave" << std::endl;
    }
    else if(bill->getTotalCost() != 0.0 && customerComplaint != "")
    {
        std::cout << "Customer cleared to leave without paying due to bad service experienced." << std::endl;
        this->~Customer();
    }
    else
    {
        std::cout << "Thank you " << this->name << "! We hope to see you again soon 🌟" << std::endl;

        //delete customer object
        this->~Customer();
    }
}

/**
 * @brief 
 * gets called when customer is not happy with her waiting period state of the food
 * sends the complaint to the manager
 * customer can still make a complaint even when the manager is not visiting the table
 */
void Customer::makeComplaint(Manager* manager)
{
    std::cout << "Please enter you complaint:" << std::endl;
    std::getline(std::cin, customerComplaint);

    manager->handleComplaint(customerComplaint);
}


/**
 * @brief Returns bill associated with customer
 * 
 * @return Bill* 
 */
Bill* Customer::getBill()
{
    return customerBill;
}

/**
 * @brief Creates a tab for a customer
 * 
 * @return Tab* 
 */
Tab* Customer::createTab()
{
    customerTab = new Tab(name);
    return customerTab;
}

/**
 * @brief Sets a tab for a customer
 * 
 * @param tab 
 */
void Customer::setTab(Tab* tab)
{
    customerTab = tab;
}

/**
 * @brief Places an order
 * 
 */
Dish* Customer::placeOrder()
{
    this->readyToOrder = true;
    order = new Dish(name, tableNum);
    customerBill = new Bill();
    return order;
}

/**
 * @brief Sets table number of customer
 * 
 * @param table 
 */
void Customer::setTableNum(int table)
{
    this->tableNum = table;
}

/**
 * @brief Returns the customers mood
 * 
 * @return std::string 
 */
std::string Customer::getMood()
{
    return customerMood;
}

/**
 * @brief Accepts visitor to table
 * 
 * @param visitor 
 */
void Customer::accept(Visitor* visitor)
{
    visitor->visitTable(this->table);
}

/**
 * @brief Assigns customer to table
 * 
 * @param customerTable 
 */
void Customer::assignCustomerTable(AbstractTable* customerTable)
{
    myTable = customerTable;
}

/**
 * @brief Returns table number in which customer is seated
 * 
 * @return int 
 */
int Customer::getTableNum()
{
    return this->tableNum;
}

/**
 * @brief Returns customer name
 * 
 * @return std::string 
 */
std::string Customer::getName()
{
    return this->name;
}

/**
 * @brief allows customer to add a tip to the Bill
 * customer chooses how much to tip
 * 
 */
void Customer::tip()
{
    float tip = 0.0;
    std::cout << "Enter tip amount:" << std::endl;
    std::cin >> tip;
    customerBill->addTip(tip);
}

/**
 * @brief User input to complement waiter
 * 
 * @return std::string 
 */
std::string Customer::complimentWaiter()
{
    std::string compliment;
    std::cout << "Please enter your compliment for the waiter:\n";
    std::getline(std::cin, compliment);
    return compliment;
}

/**
 * @brief 
 * sets customer mood according to how long it took for
 * their dish to be prepared
 * @param order 
 */
void Customer::checkOrder(Dish* order)
{
    //get time from Engine
    //set customerMood
    throw "Not yet implemented";
}

/**
 * @brief Sets the customer status
 * 
 * @param readyToPayStatus 
 */
void Customer::setReadyToOrderStatus(bool readyToOrderStatus)
{
    this->readyToOrder = readyToOrderStatus;
}

/**
 * @brief Sets the customer status
 * 
 * @param readyToPayStatus 
 */
void Customer::setReadyToLeaveStatus(bool readyToLeaveStatus)
{
    this->readyToLeave = readyToLeaveStatus;
}

/**
 * @brief Sets the customer status
 * 
 * @param readyToPayStatus 
 */
void Customer::setReadyToPayStatus(bool readyToPayStatus)
{
    this->readyToPay = readyToPayStatus;
}