//
// Created by mathe on 2023/10/30.
//

#ifndef PROJECT_CUSTOMER_H
#define PROJECT_CUSTOMER_H


#include <iostream>
#include "Dish.h"
#include "Table.h"
#include "Bill.h"
#include "Visitor.h"
#include "Manager.h"

class Manager;
class CustomerMood;
class Tab;
class AbstractBill;
class SubBill;
class Visitor;
class PaymentStrategy;

/**
 * @brief Represents a restaurant customer
 * 
 */
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
    AbstractTable* myTable;
    Bill* customerBill;
    std::string customerComplaint;
    Tab* customerTab;
public:
    Dish* dish;
    Table* table;
    Customer(std::string customerName, int tableNum, Table* table);
    ~Customer();
    void pay(PaymentStrategy* aMethodOfPayment);
    void tip();
    void customer();
    void checkOrder(Dish* order);
    void setMood(std::string cstmrMood);
    std::string getMood();
    void leaveRestaurant(Bill* bill);
    void makeComplaint(Manager* manager);
    Bill* getBill();
    Tab* createTab();
    void setTab(Tab* table);
    Dish* placeOrder();
    void setTableNum(int table);
    int getTableNum();
    std::string getName();
    void accept(Visitor* visitor);
    void assignCustomerTable(AbstractTable* customerTable);
    std::string complimentWaiter();
    void setReadyToOrderStatus(bool readyToOrderStatus);
    void setReadyToLeaveStatus(bool readyToLeaveStatus);
    void setReadyToPayStatus(bool readyToPayStatus);
};
#endif //PROJECT_CUSTOMER_H