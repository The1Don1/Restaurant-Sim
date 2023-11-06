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
    Bill();

    virtual void paymentMethod();

    void addTip(double amount);

    void handleTip();

    Bill* getBill();

    Bill(double price) : totalAmount(price){}

    double calculateBill();

    void setPaymentMethod(PaymentStrategy* method);

    double getTotalCost();

//    virtual void addItem(Bill aItem) = 0;

    virtual Bill* getSubBill(std::string customerName);

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
