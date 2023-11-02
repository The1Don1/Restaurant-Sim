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

/*------------------------Tash Implementation-------------------------------------*/

/* Bill */

#include "Bill.h"

Bill::Bill(double price)
{
    totalAmount = price;
}

void Bill::paymentMethod()
{
    paymentStrategy->pay(totalAmount);
}

void Bill::handleTip(Engine* engine)
{
    //Tip amount is set for now until engine class is implemented
    if (splitBill == true)
    {
        totalAmount = totalAmount + (totalAmount * 0.15);
    }
    else
    {
        totalAmount = totalAmount + (totalAmount * 0.20);
    }
}

void Bill::setPaymentStrategy(PaymentStrategy* paymentStrategy)
{
    this->paymentStrategy = paymentStrategy;
}

Bill* Bill::getBill()
{
    return this;
}

double Bill::calculateTotal()
{
    return totalAmount;
}   

double Bill::getTotalCost()
{
    return totalAmount;
}


/* BillItem */

#include "BillDecorator.h"

BillDecorator::BillDecorator(Bill* bill)
{
    this->bill = bill;
}

double BillDecorator::getTotalCost()
{
    return bill->getTotalCost();
}

/* BillDecorator */

#include "BillDecorator.h"

BillDecorator::BillDecorator(Bill* bill)
{
    this->bill = bill;
}

double BillDecorator::getTotalCost()
{
    return bill->getTotalCost();
}

/* CustomTipDecorator */

#include "CustomTipDecorator.h"

CustomTipDecorator::CustomTipDecorator(Bill* bill, double tip)
    : BillDecorator(bill)
{
    tipAmount = tip;
}

double CustomTipDecorator::getTotalCost()
{
    return BillDecorator::getTotalCost() + tipAmount;
}

/* SubBill */ 

#include "SubBill.h"

double SubBill::getTotalCost()
{
    double total = 0;
    for (int i = 0; i < items.size(); i++)
    {
        total += items[i]->getTotalCost();
    }
    return total;
}

void SubBill::addItem(Bill* bill)
{
    items.push_back(bill);
}








