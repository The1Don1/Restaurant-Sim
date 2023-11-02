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

std::string CustomAddition::getDescription() {
    throw "Not yet implemented";
}

double CustomAddition::getPrice() {
    throw "Not yet implemented";
}
/**
 * @brief Construct a new Custom Addition:: Custom Addition object
 * 
 * @param baseItem 
 * @param description 
 * @param price 
 * @param timeToprepare 
 */
CustomAddition::CustomAddition(Menu *baseItem, std::string description, double price, int timeToprepare)
{
    this->additionDescription = description;
    this->additionPrice = price;
    this->additionTimeToPrepare = timeToprepare;
    
}

int CustomAddition::getTimeToPrepare() {
    throw "Not yet implemented";
}


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

/*
    Beverages:
*/
std::string CokeZero::getDescription()
{
    return "Coke Zero\n";
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
    return "Coke\n";
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
    return "Sprite\n";
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
    return "Bubblegum Milkshake\n";
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
    return "Strawberry Milkshake\n";
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
    return "Chicken Wings\n";
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
    return "Onion Rings\n";
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
    return "Chips\n";
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
    return "Chicken Nuggets\n";
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
    return "Cheese Burger\n";
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
    return "Hot dog\n";
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
    return "Cheesesteak\n";
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
    return "BBQRibs\n";
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
    return "Chicken tenders\n";
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
    return "Mac and cheese\n";
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
    return "BBQ Steak\n";
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
    return "Buffalo wings\n";
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
    return "Pancakes\n";
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
    return "Donuts\n";
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
    return "Waffles\n";
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
    return "Chocolate Brownies\n";
}

double ChocolateBrownies::getPrice()
{
    return 79.99;
}

int ChocolateBrownies::getTimeToPrepare()
{
    return 3;
}


