//
// Created by mathe on 2023/10/30.
//

#include "Customer.h"
Customer::Customer(/*Bill* */std::string customerName, int tableNum, Table* table) 
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
 * need to choose method of payment
*/
float Customer::pay(PaymentStrategy* aMethodOfPayment) 
{
    aMethodOfPayment->paymentMethod();
}

bool Customer::tip() {
    throw "Not yet implemented";
}

void Customer::customer() {
    throw "Not yet implemented";
}

void Customer::checkOrder(Dish* order) {
    throw "Not yet implemented";
}

//CustomerMood Customer::getMood() {
//    throw "Not yet implemented";
//}

void Customer::setMood() {
    throw "Not yet implemented";
}

void Customer::leaveRestaurant(Bill* bill) {
    throw "Not yet implemented";
}

std::string Customer::makeComplaint() {
    throw "Not yet implemented";
}

SubBill Customer::getBill() {
    throw "Not yet implemented";
}

//CustomerMood Customer::getCustomerState() {
//    throw "Not yet implemented";
//}

Tab Customer::createTab() {
    throw "Not yet implemented";
}

void Customer::setTab(Tab tab) {
    throw "Not yet implemented";
}

void Customer::placeOrder() {
    throw "Not yet implemented";
}

void Customer::setTableNum(int table) {
    throw "Not yet implemented";
}

CustomerMood* Customer::getMood()
{
    return this->customerMood;
}

void Customer::accept(Visitor* visitor)
{
    visitor->visitTable(this);
}

void Customer::assignCustomerTable(Table* customerTable)
{
    myTable = customerTable;
}

int Customer::getTableNum() {
    return this->tableNum;
}
bool extremelySatisfied::considerTip() {
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



