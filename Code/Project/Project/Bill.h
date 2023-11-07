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

class AbstractBill
{
public:
    BillDecorator* billDecorator{};
    virtual double getTotalCost() = 0;

};

class Bill : public AbstractBill
{
    private:
        Customer* mood;
        std::vector<Customer*> customers;
        std::vector<SubBill*> subBills;
        PaymentStrategy* paymentStrategy;
        Table* table;
        SubBill* subBill;
        bool splitBill;
        double totalAmount;

    public:
        virtual void paymentMethod();
        void handleTip();
        void getBill();
        void addTip(float tip);
        Bill();
        Bill(double price) : totalAmount(price){}
        double calculateBill();
        void setPaymentMethod(PaymentStrategy* method);
        double getTotalCost();
//    virtual void addItem(Bill aItem) = 0;
        virtual void getSubBill(std::string customerName);
};

class BillItem: public Bill
{
    private:
        std::string name;
        double price;

    public:
        BillItem(std::string item, double cost);
        double getTotalCost();
};

class SubBill: public Bill
{
    private:
        std::vector<BillItem> items;

    public:
        void paymentMethod();
        Bill* bill;
        double getTotalCost();
        void addItem(SubBill item);
        void getSubBill(std::string customerName);
};

class BillDecorator: public AbstractBill
{
    private:
        Bill* bill;

    public:
        AbstractBill* abstractBill;
        BillDecorator(Bill* bill);
        double getTotalCost();
};

class CustomTipDecorator: public BillDecorator
{
    private:
        double _tipAmount;

    public:
        CustomTipDecorator(Bill *bill, double tip);
        double getTotalCost();
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
