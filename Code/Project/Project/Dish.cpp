//
// Created by mathe on 2023/10/31.
//

#include "Dish.h"
Dish* Dish::createDish() {
    throw "Not yet implemented";
}

void Dish::dishState() {
    throw "Not yet implemented";
}
DishStatus* Dish::getDishStatus() {
    throw "Not yet implemented";
}

void Dish::change() {
    throw "Not yet implemented";
}

void Dish::setState(DishStatus* state) {
    throw "Not yet implemented";
}

std::string Dish::getCustomerName() {
    return this->customerName;
}

void Dish::setCustomerName(std::string customerName) {
    this->customerName = customerName;
}

int Dish::getCustomerTable() {
    return this->customerTable;
}

void Dish::setCustomerTable(int customerTableID) {
    this->customerTable = customerTableID;
}

void DishStatus::DishState() {
    throw "Not yet implemented";
}

std::string DishStatus::getStatus() {
    throw "Not yet implemented";
}

void Preparing::updateDishStatus() {
    throw "Not yet implemented";
}

void Preparing::getStatus() {
    throw "Not yet implemented";
}

void readyForPickUp::updateDishStatus() {
    throw "Not yet implemented";
}

void readyForPickUp::getStatus() {
    throw "Not yet implemented";
}


void stiiQueued::updateDishStatus() {
    throw "Not yet implemented";
}

void stiiQueued::getStatus() {
    throw "Not yet implemented";
}

