//
// Created by mathe on 2023/10/31.
//
#include "Menu.h"
MenuDecorator::MenuDecorator(Menu *baseItem)
{
    this->menu = baseItem;
}

MenuDecorator::MenuDecorator()
{

}
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

MushroomSauce::MushroomSauce(Menu *baseItem, std::string description, double price, int timeToprepare)
{
    this->menu = baseItem;
    this->additionDescription = description;
    this->additionPrice = price;
    this->additionTimeToPrepare = timeToprepare;
}

int MushroomSauce::getTimeToPrepare() {
    return 3 + menu->getTimeToPrepare();
}

std::string MushroomSauce::getDescription() {
    return menu->getDescription() +  " and mushroom sauce";
}

double MushroomSauce::getPrice() {
    return 24.99 + menu->getPrice();
}


Salad::Salad(Menu *baseItem, std::string description, double price, int timeToprepare)
{
    this->menu = baseItem;
    this->additionDescription = description;
    this->additionPrice = price;
    this->additionTimeToPrepare = timeToprepare;
}

int Salad::getTimeToPrepare() {
    return 3 + menu->getTimeToPrepare();
}

std::string Salad::getDescription() {
    return menu->getDescription() +  " and a salad";
}

double Salad::getPrice() {
    return 34.99 + menu->getPrice();
}
////

/*
    Beverages:
*/
///
CokeZero::CokeZero()
{
    this->description = "CokeZero";
    this->price = 20.00;
    this->timeToPrepare = 1;
}

std::string CokeZero::getDescription()
{
    return this->description;
}

double CokeZero::getPrice()
{
    return this->price;
}

int CokeZero::getTimeToPrepare()
{
    return this->timeToPrepare;
}
///

Coke::Coke()
{
    this->description = "Coke";
    this->price = 20.00;
    this->timeToPrepare = 1;
}

std::string Coke::getDescription()
{
    return this->description;
}

double Coke::getPrice()
{
    return this->price;
}

int Coke::getTimeToPrepare()
{
    return this->timeToPrepare;
}
///

Sprite::Sprite()
{
    this->description = "Sprite";
    this->price = 20.00;
    this->timeToPrepare = 1;
}

std::string Sprite::getDescription()
{
    return this->description;
}

double Sprite::getPrice()
{
    return this->price;
}

int Sprite::getTimeToPrepare()
{
    return this->timeToPrepare;
}
///

BubblegumMilkshake::BubblegumMilkshake()
{
    this->description = "Bubblegum milkshake";
    this->price = 25.00;
    this->timeToPrepare = 1;
}

std::string BubblegumMilkshake::getDescription()
{
    return this->description;
}

double BubblegumMilkshake::getPrice()
{
    return this->price;
}

int BubblegumMilkshake::getTimeToPrepare()
{
    return this->timeToPrepare;
}
////
StrawberryMilkshake::StrawberryMilkshake()
{
    this->description = "Strawberry milkshake";
    this->price = 25.00;
    this->timeToPrepare = 1;
}

std::string StrawberryMilkshake::getDescription()
{
    return this->description;
}

double StrawberryMilkshake::getPrice()
{
    return this->price;
}

int StrawberryMilkshake::getTimeToPrepare()
{
    return this->timeToPrepare;
}

//////
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


