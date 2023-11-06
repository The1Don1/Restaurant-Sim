//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_BILL_H
#define PROJECT_BILL_H
#include <iostream>
#include <vector>
#include "Customer.h"
#include "Table.h"
#include "Bill.h"
class BillDecorator;
class SubBill;
class Table;
class PaymentStrategy;
class AbstractBill{
public:
    BillDecorator* billDecorator{};
    virtual double getTotalCost() = 0;

};
class Bill : public AbstractBill{
private:
    Customer* mood;

    std::vector<Customer*> customers;

    bool splitBill;

    double totalAmount;

    PaymentStrategy* paymentStrategy;

    Table* table;

    SubBill* subBill;

public:
    virtual void paymentMethod() = 0;

    void handleTip();

    Bill* getBill();

    Bill(double price) : totalAmount(price){}

    double calculateBill();

    void setPaymentMethod(PaymentStrategy* method);

    double getTotalCost();

//    virtual void addItem(Bill aItem) = 0;

    virtual Bill* getSubBill(std::string customerName) = 0;

    std::vector<Customer*> getCustomers()
    {
        return customers;
    }

    PaymentStrategy* getPaymentStrategy()
    {
        return paymentStrategy;
    }
};

class BillItem: public Bill{
private:
        std::string name;
        double price;
public:
        BillItem(double price, std::string item, double cost);
        void paymentMethod();
    Bill* getSubBill(std::string customerName);
        double getTotalCost();
        void addItem(SubBill item);
};

class SubBill: public Bill{
private:
    std::vector<BillItem*> items;
public:
    void paymentMethod();
    Bill* bill;
    double getTotalCost();
    void addItem(BillItem* item);
    Bill* getSubBill(std::string customerName);

};
class BillDecorator: public AbstractBill{
private:
        Bill* bill;
public:
        AbstractBill* abstractBill;
        BillDecorator(Bill* bill);
        double getTotalCost();
        Bill* getBill()
        {
            return bill;
        }

};

class CustomTipDecorator: public BillDecorator
{
private: double _tipAmount;

public: CustomTipDecorator(Bill *bill, double tip);

public: double getTotalCost();
};


class PaymentStrategy
{
public: Bill* bill;

public: void paymentMethod();
};

class Card: public PaymentStrategy
{

public:
    void paymentMethod();

    void getPaymentMethod();
};

class Cash: public PaymentStrategy
{

public:
    void paymentMethod();
    void getPaymentMethod();
};

#endif //PROJECT_BILL_H


Bill.cpp:
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
                if (customer->getName() == customerName)
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

Bill::Bill(double price) : totalAmount(price), paymentStrategy(NULL), splitBill(false)
{
    
}

/* ------------Changes--------------*/
/*
1. Changed the return type of getSubBill from void to Bill*
2. Added a getter for customers and items
*/

/*---------Notes------------*/
/*

*/
