//
// Created by mathe on 2023/10/31.
//

#include "Bill.h"
BillItem::BillItem(double price, std::string item, double cost) : Bill(price) {
    name = item;
    this->price = cost;

}

double BillItem::getTotalCost() {
    return price;
}

void BillItem::addItem(SubBill item) {
    throw "Not yet implemented";
}

void BillItem::paymentMethod() {
    Bill::paymentMethod();
}

Bill* BillItem::getSubBill(std::string customerName) {
    if (name == customerName)
        return this;
}


BillDecorator::BillDecorator(Bill* bill) {
    this->bill = bill;
}

double BillDecorator::getTotalCost() {
    return bill->getTotalCost();
}

double SubBill::getTotalCost() {

    double total = 0.0;
    for (auto &item : items) {
        total += item.getTotalCost();
    }
    return total;
}

void SubBill::addItem(BillItem item) {
    items.push_back(item);
}

Bill* SubBill::getSubBill(std::string customerName) {

    // Iterate over all items in the bill
    for (auto &item : items)
    {
        // Check if the item has any customers
        if (!item.getCustomers().empty())
        {
            // Iterate over all customers of the item
            for (auto &customer : item.getCustomers())
            {
                // If the customer's name matches the input, print the item details
                if (customer->getName() == customerName)
                {
                    return &item;
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
    return getBill()->getTotalCost() + _tipAmount;
}


void Bill::handleTip() {
    totalAmount = totalAmount + this->billDecorator->getTotalCost();

}

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


/* ------------Changes--------------*/
/*
1. Changed the return type of getSubBill from void to Bill*
2. Added a getter for customers and items
*/

/*---------Notes------------*/
/*

*/