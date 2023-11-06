//
// Created by mathe on 2023/10/31.
//

#include "Bill.h"
BillItem::BillItem(std::string item, double cost){
    name = item;
    this->price = cost;

}

double BillItem::getTotalCost() {
    return price;
}

void BillItem::addItem(SubBill item) {
    return;
}

void BillItem::paymentMethod() {
    if(getPaymentStrategy() != NULL)
        getPaymentStrategy()->paymentMethod();
    else
        std::cout << "Payment strategy not set.\n";
}

Bill* BillItem::getSubBill(std::string customerName) {
   
    // for (Customer* customer : getCustomers())
    // {
    //     if (customer->getName() == customerName)
    //     {
    //         return customer->getBill();
    //     }
    // }

    return NULL;
}


BillDecorator::BillDecorator(Bill* bill) {
    this->bill = bill;
}

double BillDecorator::getTotalCost() {
    if (bill != NULL)
        return bill->getTotalCost();
    else return 0;
}

double SubBill::getTotalCost() {

    double total = 0.0;
    for (auto item : items) {
        total += item->getTotalCost();
    }
    return total;
}

void SubBill::addItem(BillItem* item) {
    if (item != NULL)
        items.push_back(item);
}

Bill* SubBill::getSubBill(std::string customerName) {

    for (auto item : items)
    {
        if (!item->getCustomers().empty())
        {
            for (auto customer : item->getCustomers())
            {
                if (customer->dish->getCustomerName() == customerName)
                {
                    return item;
                }
            }
        }
    }

    return NULL;
}

void SubBill::paymentMethod()
{
    bill->paymentMethod();
}

void PaymentStrategy::paymentMethod() {
    std::cout << "Processing payment..." << std::endl;
}

void Cash::paymentMethod() {
    std::cout << "Payment made by cash." << std::endl;
}

void Cash::getPaymentMethod() {
    std::cout << "Cash." << std::endl;
}
void Card::paymentMethod() {
    std::cout << "Payment made by card." << std::endl;
}

void Card::getPaymentMethod() {
    std::cout << "Card" << std::endl;
}


CustomTipDecorator::CustomTipDecorator(Bill *bill, double tip) : BillDecorator(bill) {
    _tipAmount = tip;
}

double CustomTipDecorator::getTotalCost() {
    return  _tipAmount;
}

void Bill::addTip(double amount)
{
    this->totalAmount += amount;
}

void Bill::handleTip() {
    //Billdecorator->getTotalCost() function returns the custom tip given
    //totalAmount = totalAmount + this->billDecorator->getTotalCost();

    if (splitBill)
    {
        totalAmount = totalAmount + (totalAmount * 0.15);
    }
    else
    {
        totalAmount = totalAmount + (totalAmount * 0.20);
    }

}

Bill::Bill()
{}

Bill* Bill::getBill() {
    return this;
 
}

double Bill::calculateBill() {
    totalAmount = totalAmount + subBill->getTotalCost();
    return totalAmount;
}

void Bill::setPaymentMethod(PaymentStrategy *method) {
    paymentStrategy = method;

}

double Bill::getTotalCost() {
    return totalAmount;
        
}

/*Bill::Bill(double price)
{
    this->totalAmount = price;
    this->paymentStrategy = NULL;
    this->splitBill = false;
}*/

/* ------------Changes--------------*/
/*
1. Changed the return type of getSubBill from void to Bill*
2. Added a getter for customers and items
*/

/*---------Notes------------*/
/*

*/