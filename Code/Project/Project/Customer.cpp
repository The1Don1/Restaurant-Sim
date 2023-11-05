//
// Created by mathe on 2023/10/30.
//

#include <iostream>
#include "Customer.h"

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
 * Customer destructor
 * deletes the object that calls the destructor
*/
Customer::~Customer()
{
    delete this;
}


/**
 * method gets called when customer is ready to pay
 * need to choose method of payment (strategy design pattern)
*/
float Customer::pay(PaymentStrategy* aMethodOfPayment)
{
    aMethodOfPayment->paymentMethod();
}


/**
 * method sets customer's mood
*/
void Customer::setMood(std::string cstmrMood)
{
    customerMood = cstmrMood;
}


/**
 * method is called when the customer is ready to leave the restaurant
 * acts as the constructor (conditional)
*/
void Customer::leaveRestaurant(Bill* bill) 
{
    //make payment
    if(bill->getTotalCost() != 0.0)
    {
        std::cout << this->name << " please settle bill before you leave" << std::endl;
    }
    else
    {
        std::cout << "Thank you " << this->name << "!" << std::endl;
        
        //delete customer object
        this->~Customer();
    } 
}


/**
 * gets called when customer is not happy with her waiting period state of the food
 * sends the complaint to the manager
 * customer can still make a complaint even when the manager is not visiting the table
*/
std::string Customer::makeComplaint(Manager* manager) 
{
    std::cout << "Please enter you complaint:" << std::endl;
    std::getline(std::cin, customerComplaint);

    manager->handleComplaint(customerComplaint);
}

Bill* Customer::getBill() 
{
    return customerBill;
}


Tab Customer::createTab() 
{
    customerTab = new Tab(name);
}

void Customer::setTab(Tab* tab) 
{
    customerTab = tab;
}

void Customer::placeOrder()
{
    order = new Dish(name, tableNum);
    customerBill = new Bill();
}

void Customer::setTableNum(int table)
{
    this->tableNum = table;
}

std::string Customer::getMood()
{
    return customerMood;
}

void Customer::accept(Visitor* visitor)
{
    visitor->visitTable(this);
}

void Customer::assignCustomerTable(Table* customerTable)
{
    myTable = customerTable;
}

int Customer::getTableNum()
{
    return this->tableNum;
}

/**
 * allows customer to add a tip to the Bill
 * customer chooses how much to tip
*/
bool Customer::tip()
{
    float tip = 0.0;
    std::cout << "Enter tip amount:" << std::endl;
    std::cin >> tip;
    customerBill->addTip(tip);
}

/**
 * sets customer mood according to how long it took for
 * their dish to be prepared
*/
void Customer::checkOrder(Dish* order) 
{
    //get time from Engine
    //set customerMood
    throw "Not yet implemented";
}
