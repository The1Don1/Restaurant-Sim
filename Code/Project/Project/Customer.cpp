//
// Created by mathe on 2023/10/30.
//

#include <iostream>
#include "Customer.h"

using namespace std;
Customer::Customer(std::string customerName, int tableNum, Table* table) //DONE
{
    order = NULL;
    readyToPay = false;
    readyToOrder = false;
    readyToLeave = false;
    name = customerName;
    this->tableNum = tableNum;
    myTable = table;
}

/**
 * method gets called when customer is ready to pay
 * need to choose method of payment (strategy design pattern)
*/
float Customer::pay(PaymentStrategy* aMethodOfPayment) //DONE
{
    aMethodOfPayment->paymentMethod();
}

/**
 * allows customer to add a tip to the Bill
 * customer chooses how much to tip
*/
bool Customer::tip() //PARTIALLY IMPLEMENTED
{
    //prompt user to enter tip
    float tip = 0.0;
    cout << "Enter tip amount:" << endl;
    cin >> tip;

    //need to add tip to the bill
    
    throw "Not yet implemented";
}

/**
 * sets customer mood according to how long it took for
 * their dish to be prepared
*/
void Customer::checkOrder(Dish* order) 
{
    throw "Not yet implemented";
}

void Customer::setMood(CustomerMood* cstmrMood) //PARTIALLY DONE
{
    if(customerMood!= nullptr)
        delete customerMood;

    customerMood = cstmrMood;
}

void Customer::leaveRestaurant(Bill* bill) {
    throw "Not yet implemented";
}

std::string Customer::makeComplaint() {
    throw "Not yet implemented";
}

SubBill Customer::getBill() 
{
    throw "Not yet implemented";
}

//CustomerMood Customer::getCustomerState() {
//    throw "Not yet implemented";
//}

Tab Customer::createTab() 
{
    throw "Not yet implemented";
}

void Customer::setTab(Tab tab) {
    throw "Not yet implemented";
}

void Customer::placeOrder()  //PARTIAL IMPLEMENTATION
{
    order = new Dish(name, myTable);
}

void Customer::setTableNum(int table) //DONE
{
    this->tableNum = table;
}

CustomerMood* Customer::getMood() //DONE
{
    return this->customerMood;
}

void Customer::accept(Visitor* visitor) //DONE
{
    visitor->visitTable(this);
}

void Customer::assignCustomerTable(Table* customerTable) //DONE
{
    myTable = customerTable;
}

int Customer::getTableNum() //DONE
{
    return this->tableNum;
}
bool extremelySatisfied::considerTip() 
{
    throw "Not yet implemented";
}

bool extremelyUnsatisfied::considerTip() {
    throw "Not yet implemented";
}
bool Unsatisfied::considerTip() {
    throw "Not yet implemented";
}
bool Satisfied::considerTip() {
    throw "Not yet implemented";
}



