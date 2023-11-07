//
// Created by mathe on 2023/10/31.
//

#include "Bill.h"
BillItem::BillItem(std::string item, double cost)
{
    this->name = item;
    this->price = cost;
}

double BillItem::getTotalCost()
{
    return this->price;
}


BillDecorator::BillDecorator(Bill* bill) {
}

double BillDecorator::getTotalCost() {
    throw "Not yet implemented";
}

double SubBill::getTotalCost() {
    throw "Not yet implemented";
}

void SubBill::addItem(SubBill item) {
    throw "Not yet implemented";
}

void SubBill::getSubBill(std::string customerName) {
    throw "Not yet implemented";
}

void PaymentStrategy::paymentMethod() {
    throw "Not yet implemented";
}

void Cash::paymentMethod() {
    throw "Not yet implemented";
}

void Cash::getPaymentMethod() {
    throw "Not yet implemented";
}
void Card::paymentMethod() {
    throw "Not yet implemented";
}

void Card::getPaymentMethod() {
    throw "Not yet implemented";
}


CustomTipDecorator::CustomTipDecorator(Bill *bill, double tip) : BillDecorator(bill) {
}

double CustomTipDecorator::getTotalCost() {
    throw "Not yet implemented";
}


void Bill::handleTip() {

}

void Bill::addTip(float tip)
{
    totalAmount += tip;
}

void Bill::getBill() {

}

double Bill::calculateBill() {
    return 0;
}

void Bill::setPaymentMethod(PaymentStrategy *method) {

}

double Bill::getTotalCost() {
    return 0;
}

void Bill::paymentMethod() {

}

Bill::Bill() {

}

void Bill::getSubBill(std::string customerName) {

}