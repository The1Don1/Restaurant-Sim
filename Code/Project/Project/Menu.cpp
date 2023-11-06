//
// Created by mathe on 2023/10/31.
//
#include "Menu.h"
/**
 * @brief Construct a new Menu:: Menu object
*/
std::string Menu::getDescription()
{
    return this->description;
}

/**
 * @brief Construct a new Menu:: Menu object
*/
double Menu::getPrice()
{
    return this->price;
}

/**
 * @brief Returns preparation time for the menu object
*/
int Menu::getTimeToPrepare()
{
    return this->timeToPrepare;
}

/**
 * @brief Sets the base menu item that the customer wants to add custom additions to
*/
MenuDecorator::MenuDecorator(Menu *baseItem)
{
    this->menu = baseItem;
}

MenuDecorator::MenuDecorator()
{

}
////
/**
 * @brief Constrcutor for coleslaw custom addition
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
/**
 * @brief Constrcutor for mushroom sauce custom addition
 * 
 * @param baseItem 
 * @param description 
 * @param price 
 * @param timeToprepare 
 */
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

/**
 * @brief Constrcutor for salad custom addition
 * 
 * @param baseItem 
 * @param description 
 * @param price 
 * @param timeToprepare 
 */
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

/**
 * @brief Constrcutor for CokeZero beverage
*/
CokeZero::CokeZero()
{
    this->description = "CokeZero";
    this->price = 20.00;
    this->timeToPrepare = 1;
}

/**
 * @brief Constrcutor for Coke beverage
*/
Coke::Coke()
{
    this->description = "Coke";
    this->price = 20.00;
    this->timeToPrepare = 1;
}

/**
 * @brief Constrcutor for Sprite beverage
*/
Sprite::Sprite()
{
    this->description = "Sprite";
    this->price = 20.00;
    this->timeToPrepare = 1;
}

/**
 * @brief Constrcutor for bubblegum milkshake beverage
*/
BubblegumMilkshake::BubblegumMilkshake()
{
    this->description = "Bubblegum milkshake";
    this->price = 25.00;
    this->timeToPrepare = 1;
}

/**
 * @brief Constrcutor for Strawberry milkshake beverage
*/
StrawberryMilkshake::StrawberryMilkshake()
{
    this->description = "Strawberry milkshake";
    this->price = 25.00;
    this->timeToPrepare = 1;
}

/**
 * @brief Constrcutor for onion rings starter
*/
OnionRings::OnionRings()
{
    this->description = "Onion rings";
    this->price = 79.99;
    this->timeToPrepare = 5;
}

/**
 * @brief Constrcutor for chicken wings starter
*/
ChickenWings::ChickenWings()
{
    this->description = "Chicken wings";
    this->price = 125.95;
    this->timeToPrepare = 5;
}


/**
 * @brief Constrcutor for chips starter
*/
Chips::Chips()
{
    this->description = "Chips";
    this->price = 39.99;
    this->timeToPrepare = 5;
}

/**
 * @brief Constrcutor for chicken nuggets starter
*/
ChickenNuggets::ChickenNuggets()
{
    this->description = "Chicken nuggets";
    this->price = 54.99;
    this->timeToPrepare = 5;
}
////

/**
 * @brief Constrcutor for cheese burger main dish
*/
CheeseBurger::CheeseBurger()
{
    this->description = "Cheese burger";
    this->price = 74.99;
    this->timeToPrepare = 10;
}

/**
 * @brief Constrcutor for hot dog main dish
*/
HotDog::HotDog()
{
    this->description = "Hot dog";
    this->price = 49.99;
    this->timeToPrepare = 10;
}

/**
 * @brief Constrcutor for cheesesteak main dish
*/
CheeseSteak::CheeseSteak()
{
    this->description = "CheeseSteak";
    this->price = 169.99;
    this->timeToPrepare = 10;
}

/**
 * @brief Constrcutor for BBQ ribs main dish
*/
BBQRibs::BBQRibs()
{
    this->description = "BBQ ribs";
    this->price = 199.99;
    this->timeToPrepare = 10;
}

/**
 * @brief Constrcutor for chicken tenders main dish
*/
ChickenTenders::ChickenTenders()
{
    this->description = "Chicken tenders";
    this->price = 129.99;
    this->timeToPrepare = 10;
}

/**
 * @brief Constrcutor for mac and cheese main dish
*/
MacAndCheese::MacAndCheese()
{
    this->description = "Mac and cheese";
    this->price = 109.99;
    this->timeToPrepare = 10;
}


/**
 * @brief Constrcutor for BBQ steak main dish
*/
BBQSteak::BBQSteak()
{
    this->description = "BBQ steak";
    this->price = 209.99;
    this->timeToPrepare = 10;
}

/**
 * @brief Constrcutor for buffalo wings main dish
*/
BuffaloWings::BuffaloWings()
{
    this->description = "Buffalo wings";
    this->price = 179.99;
    this->timeToPrepare = 10;
}
/////


/**
 * @brief Constrcutor for pancakes dessert
*/
Pancakes::Pancakes()
{
    this->description = "Pancakes";
    this->price = 49.99;
    this->timeToPrepare = 3;
}

/**
 * @brief Constrcutor for donuts dessert
*/
Donuts::Donuts()
{
    this->description = "Donuts";
    this->price = 59.99;
    this->timeToPrepare = 3;
}

/**
 * @brief Constrcutor for waffles dessert
*/
Waffles::Waffles()
{
    this->description = "Waffles";
    this->price = 69.99;
    this->timeToPrepare = 3;
}

/**
 * @brief Constrcutor for chocolate brownies dessert
*/
ChocolateBrownies::ChocolateBrownies()
{
    this->description = "Chocolate brownies";
    this->price = 89.99;
    this->timeToPrepare = 3;
}