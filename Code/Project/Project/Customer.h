//
// Created by mathe on 2023/10/30.
//

#ifndef PROJECT_CUSTOMER_H
#define PROJECT_CUSTOMER_H


#include <iostream>
#include "Dish.h"
#include "Table.h"
#include "Bill.h"
class CustomerMood;
class Tab;
class AbstractBill;
class SubBill;
class Customer {
private:
    Dish* order;
    CustomerMood* customerMood;
    bool readyToPay;
    bool readyToOrder;
    bool readyToLeave;
    std::string name;
    AbstractBill* bill;
    int tableNum;
public:
    Dish* dish;
    Table* table;
    Customer(Bill* bill);
    float pay();
    bool tip();
    void customer();
    void checkOrder(Dish* order);
//    CustomerMood getMood();
    void setMood();
    void leaveRestaurant(Bill* bill);
    std::string makeComplaint();
    SubBill getBill();
//    CustomerMood getCustomerState();
    Tab createTab();
    void setTab(Tab table);
    void placeOrder();
    void setTableNum(int table);
    int getTableNum();
    std::string getName()
    {
        return name;
    }
};

class CustomerMood{
public: Customer* customer;

public: virtual bool considerTip() = 0;
};
class extremelySatisfied: public CustomerMood
{

public: bool considerTip();
};
class extremelyUnsatisfied: public CustomerMood
{

public: bool considerTip();
};

class Unsatisfied: public CustomerMood
{

public: bool considerTip();
};

class Satisfied: public CustomerMood
{

public: bool considerTip();
};
#endif //PROJECT_CUSTOMER_H
