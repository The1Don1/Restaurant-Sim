//
// Created by mathe on 2023/10/31.
//
#include "Menu.h"
std::string Menu::getDescription()
{
    return this->description;
}

double Menu::getPrice()
{
    return this->price;
}

int Menu::getTimeToPrepare()
{
    return this->timeToPrepare;
}

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

Coke::Coke()
{
    this->description = "Coke";
    this->price = 20.00;
    this->timeToPrepare = 1;
}

Sprite::Sprite()
{
    this->description = "Sprite";
    this->price = 20.00;
    this->timeToPrepare = 1;
}

BubblegumMilkshake::BubblegumMilkshake()
{
    this->description = "Bubblegum milkshake";
    this->price = 25.00;
    this->timeToPrepare = 1;
}

StrawberryMilkshake::StrawberryMilkshake()
{
    this->description = "Strawberry milkshake";
    this->price = 25.00;
    this->timeToPrepare = 1;
}

//////
/*
    Starters:
*/
OnionRings::OnionRings()
{
    this->description = "Onion rings";
    this->price = 79.99;
    this->timeToPrepare = 5;
}

ChickenWings::ChickenWings()
{
    this->description = "Chicken wings";
    this->price = 125.95;
    this->timeToPrepare = 5;
}

Chips::Chips()
{
    this->description = "Chips";
    this->price = 39.99;
    this->timeToPrepare = 5;
}

ChickenNuggets::ChickenNuggets()
{
    this->description = "Chicken nuggets";
    this->price = 54.99;
    this->timeToPrepare = 5;
}
////

/*
    Main dishes:
*/

CheeseBurger::CheeseBurger()
{
    this->description = "Cheese burger";
    this->price = 74.99;
    this->timeToPrepare = 10;
}

HotDog::HotDog()
{
    this->description = "Hot dog";
    this->price = 49.99;
    this->timeToPrepare = 10;
}

Cheesesteak::Cheesesteak()
{
    this->description = "Cheesesteak";
    this->price = 169.99;
    this->timeToPrepare = 10;
}

BBQRibs::BBQRibs()
{
    this->description = "BBQ ribs";
    this->price = 199.99;
    this->timeToPrepare = 10;
}

ChickenTenders::ChickenTenders()
{
    this->description = "Chicken tenders";
    this->price = 129.99;
    this->timeToPrepare = 10;
}

MacAndCheese::MacAndCheese()
{
    this->description = "Mac and cheese";
    this->price = 109.99;
    this->timeToPrepare = 10;
}

BBQSteak::BBQSteak()
{
    this->description = "BBQ steak";
    this->price = 209.99;
    this->timeToPrepare = 10;
}

BuffaloWings::BuffaloWings()
{
    this->description = "Buffalo wings";
    this->price = 179.99;
    this->timeToPrepare = 10;
}
/////


/*
    Desserts:
*/
Pancakes::Pancakes()
{
    this->description = "Pancakes";
    this->price = 49.99;
    this->timeToPrepare = 3;
}

Donuts::Donuts()
{
    this->description = "Donuts";
    this->price = 59.99;
    this->timeToPrepare = 3;
}

Waffles::Waffles()
{
    this->description = "Waffles";
    this->price = 69.99;
    this->timeToPrepare = 3;
}

ChocolateBrownies::ChocolateBrownies()
{
    this->description = "Chocolate brownies";
    this->price = 89.99;
    this->timeToPrepare = 3;
}