//
// Created by mathe on 2023/10/31.
//

#include "Menu.h"

////
/**
 * @brief Custom additions can be added to an original menu item by a customer
 * 
 * @param baseItem 
 * @param description 
 * @param price 
 * @param timeToprepare 
 */
Coleslaw::Coleslaw(Menu *baseItem, std::string description, double price, int timeToprepare)
{
    this->menu = baseItem;
    this->additionDescription = description;
    this->additionPrice = price;
    this->additionTimeToPrepare = timeToprepare;
}

int Coleslaw::getTimeToPrepare() {
    return 3 + menu->getTimeToPrepare();
}

std::string Coleslaw::getDescription() {
    return menu->getDescription() +  " and coleslaw";
}

double Coleslaw::getPrice() {
    return 19.99 + menu->getPrice();
}

////


std::string Beverage::getDescription() {
    throw "Not yet implemented";
}

double Beverage::getPrice() {
    throw "Not yet implemented";
}

int Beverage::getTimeToPrepare() {
    throw "Not yet implemented";
}

std::string Starter::getDescription() {
    throw "Not yet implemented";
}

double Starter::getPrice() {
    throw "Not yet implemented";
}

int Starter::getTimeToPrepare() {
    throw "Not yet implemented";
}

std::string MainDish::getDescription() {
    throw "Not yet implemented";
}

double MainDish::getPrice() {
    throw "Not yet implemented";
}

int MainDish::getTimeToPrepare() {
    throw "Not yet implemented";
}

std::string Dessert::getDescription() {
    throw "Not yet implemented";
}

double Dessert::getPrice() {
    throw "Not yet implemented";
}

int Dessert::getTimeToPrepare() {
    throw "Not yet implemented";
}