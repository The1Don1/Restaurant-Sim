//
// Created by mathe on 2023/10/31.
//

#include "Bill.h"
BillItem::BillItem(double price, std::string item, double cost) : Bill(price) {
}

double BillItem::getTotalCost() {
    throw "Not yet implemented";
}

void BillItem::addItem(SubBill item) {
    throw "Not yet implemented";
}

void BillItem::paymentMethod() {

}

void BillItem::getSubBill(std::string customerName) {

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
    throw "Not implemented yet";
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


CustomTipDecorator::CustomTipDecorator(Bill *bill, Bill *bill2, double tip) : BillDecorator(bill) {
}

double CustomTipDecorator::getTotalCost() {
    throw "Not yet implemented";
}


void Bill::handleTip() {

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
