//
// Created by mathe on 2023/10/31.
//

#include "Menu.h"
std::string MenuDecorator::getDescription() {
    throw "Not yet implemented";
}

double MenuDecorator::getPrice() {
    throw "Not yet implemented";
}

MenuDecorator::MenuDecorator(Menu* baseItem) {
}

int MenuDecorator::getTimeToPrepare() {
    throw "Not yet implemented";
}
/**
 * @brief Custom additions can be added to an original menu item
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
    return menu->getDescription() +  "and coleslaw";
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
    return menu->getDescription() +  "and mushroom sauce";
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
/*
    Beverages:
*/
std::string CokeZero::getDescription()
{
    return "Coke Zero";
}

double CokeZero::getPrice()
{
    return 20.00;
}

int CokeZero::getTimeToPrepare()
{
    return 1;
}

std::string Coke::getDescription()
{
    return "Coke";
}

double Coke::getPrice()
{
    return 20.00;
}

int Coke::getTimeToPrepare()
{
    return 1;
}

std::string Sprite::getDescription()
{
    return "Sprite";
}

double Sprite::getPrice()
{
    return 20.00;
}

int Sprite::getTimeToPrepare()
{
    return 1;
}

std::string BubblegumMilkshake::getDescription()
{
    return "Bubblegum Milkshake";
}

double BubblegumMilkshake::getPrice()
{
    return 25.00;
}

int BubblegumMilkshake::getTimeToPrepare()
{
    return 1;
}

std::string StrawberryMilkshake::getDescription()
{
    return "Strawberry Milkshake";
}

double StrawberryMilkshake::getPrice()
{
    return 25.00;
}

int StrawberryMilkshake::getTimeToPrepare()
{
    return 1;
}


/*
    Starters:
*/
std::string ChickenWings::getDescription()
{
    return "Chicken Wings";
}

double ChickenWings::getPrice()
{
    return 125.95;
}

int ChickenWings::getTimeToPrepare()
{
    return 5;
}

std::string OnionRings::getDescription()
{
    return "Onion Rings";
}

double OnionRings::getPrice()
{
    return 79.99;
}

int OnionRings::getTimeToPrepare()
{
    return 5;
}

std::string Chips::getDescription()
{
    return "Chips";
}

double Chips::getPrice()
{
    return 59.99;
}

int Chips::getTimeToPrepare()
{
    return 5;
}

std::string ChickenNuggets::getDescription()
{
    return "Chicken Nuggets";
}

double ChickenNuggets::getPrice()
{
    return 54.99;
}

int ChickenNuggets::getTimeToPrepare()
{
    return 5;
}

/*
    Main dishes:
*/
std::string CheeseBurger::getDescription()
{
    return "Cheese Burger";
}

double CheeseBurger::getPrice()
{
    return 75.00;
}

int CheeseBurger::getTimeToPrepare()
{
    return 10;
}


std::string HotDog::getDescription()
{
    return "Hot dog";
}

double HotDog::getPrice()
{
    return 65.00;
}

int HotDog::getTimeToPrepare()
{
    return 10;
}


std::string Cheesesteak::getDescription()
{
    return "Cheesesteak";
}

double Cheesesteak::getPrice()
{
    return 169.99;
}

int Cheesesteak::getTimeToPrepare()
{
    return 10;
}


std::string BBQRibs::getDescription()
{
    return "BBQRibs";
}

double BBQRibs::getPrice()
{
    return 199.99;
}

int BBQRibs::getTimeToPrepare()
{
    return 10;
}


std::string ChickenTenders::getDescription()
{  
    return "Chicken tenders";
}

double ChickenTenders::getPrice()
{
    return 149.99;
}

int ChickenTenders::getTimeToPrepare()
{
    return 10;
}

std::string MacAndCheese::getDescription()
{
    return "Mac and cheese";
}

double MacAndCheese::getPrice()
{
    return 179.99;
}

int MacAndCheese::getTimeToPrepare()
{
    return 10;
}


std::string BBQSteak::getDescription()
{
    return "BBQ Steak";
}

double BBQSteak::getPrice()
{
    return 209.99;
}

int BBQSteak::getTimeToPrepare()
{
    return 10;
}


std::string BuffaloWings::getDescription()
{
    return "Buffalo wings";
}

double BuffaloWings::getPrice()
{
    return 219.99;
}

int BuffaloWings::getTimeToPrepare()
{
    return 10;
}


/*
    Desserts
*/
std::string Pancakes::getDescription()
{
    return "Pancakes";
}

double Pancakes::getPrice()
{
    return 79.99;
}

int Pancakes::getTimeToPrepare()
{
    return 3;
}


std::string Donuts::getDescription()
{
    return "Donuts";
}

double Donuts::getPrice()
{
    return 49.99;
}

int Donuts::getTimeToPrepare()
{
    return 3;
}


std::string Waffles::getDescription()
{
    return "Waffles";
}

double Waffles::getPrice()
{
    return 69.99;
}

int Waffles::getTimeToPrepare()
{
    return 3;
}


std::string ChocolateBrownies::getDescription()
{
    return "Chocolate Brownies";
}

double ChocolateBrownies::getPrice()
{
    return 79.99;
}

int ChocolateBrownies::getTimeToPrepare()
{
    return 3;
}


