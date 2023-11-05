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
class Customer 
{
private:
    Dish* order;
    std::string customerMood;
    bool readyToPay;
    bool readyToOrder;
    bool readyToLeave;
    std::string name;
    AbstractBill* bill;
    int tableNum;
    Table* myTable;
    Bill* customerBill;
    std::string customerComplaint;
    Tab* customerTab;
public:
    Dish* dish;
    Table* table;
    Customer(std::string customerName, int tableNum, Table* table);
    ~Customer();
    float pay(PaymentStrategy* aMethodOfPayment);
    bool tip();
    void customer();
    void checkOrder(Dish* order);
    void setMood(std::string cstmrMood);
    std::string getMood(); 
    void leaveRestaurant(Bill* bill);
    std::string makeComplaint(Manager* manager);
    Bill* getBill();
    Tab createTab();
    void setTab(Tab* table);
    void placeOrder();
    void setTableNum(int table);
    int getTableNum();
    void accept(Visitor* visitor);
    void assignCustomerTable(Table* customerTable);
};
#endif //PROJECT_CUSTOMER_H
