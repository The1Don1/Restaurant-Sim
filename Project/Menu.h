//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H
#include "iostream"
#include "Dish.h"
class Menu{
    virtual std::string getDescription() = 0;
    virtual double getPrice() = 0;
    virtual void menu() = 0;
    virtual int getTimeToPrepare() = 0;
};
class MenuDecorator: public Menu
{
protected: Menu* item;
public:
    Menu* menu;
    std::string getDescription();
    double getPrice();
    MenuDecorator();
    MenuDecorator(Menu* baseItem);
    int getTimeToPrepare();
};

class CustomAddition: public MenuDecorator
{
private:
    std::string additionDescription;
    double additionPrice;
    int additionTimeToPrepare;
public:
    std::string getDescription();
    double getPrice();
    CustomAddition(Menu* baseItem, std::string description, double price, int timeToprepare);
    int getTimeToPrepare();
};
///////////
class Beverage: public Menu
{
    /**
     * @brief Beverages base class
     * Beverages are coke zero, coke, sprite, strawberry milkshakes and bubblegum milkshakes
     * Beverages will all take 1 second to prepare
     */
public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class CokeZero: public Beverage
{
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class Coke: public Beverage
{
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class Sprite: public Beverage
{
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class StrawberryMilkshake: public Beverage
{
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};


class BubblegumMilkshake: public Beverage
{
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
}; 

////////
class Starter: public Menu
{
    /**
     * @brief Starters base class
     * Starters are onion rings, chicken wings and chicken nuggets
     * Starters will all take 5 seconds to prepare
     */

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class OnionRings: public Starter
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class ChickenWings: public Starter
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class Chips: public Starter
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class ChickenNuggets: public Starter
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

///////
class MainDish: public Menu
{
    /**
     * @brief Main dishes base class
     * Main dishes are cheeseburgers, hot dogs, mac and cheese, bbq ribs, chicken tenders, cheesesteak, bbq steak and buffalo wings
     * Main dishes will all take 10 seconds to prepare
     */
public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class CheeseBurger: public MainDish
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class HotDog: public MainDish
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class MacAndCheese: public MainDish
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class BBQRibs: public MainDish
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class ChickenTenders: public MainDish
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class Cheesesteak: public MainDish
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class BBQSteak: public MainDish
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class BuffaloWings: public MainDish
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

/////
class Dessert: public Menu
{
    /**
     * @brief Desserts base class
     * Desserts are waffle, chocolate brownies, donuts and pancakes
     * Desserts will all take 3 seconds to prepare
     */

public: std::string getDescription();

public: double getPrice();

public: int getTimeToPrepare();
};

class Pancakes: public Dessert
{

public: std::string getDescription();

public: double getPrice();

public: int getTimeToPrepare();
};


class Donuts: public Dessert
{

public: std::string getDescription();

public: double getPrice();

public: int getTimeToPrepare();
};


class Waffles: public Dessert
{

public: std::string getDescription();

public: double getPrice();

public: int getTimeToPrepare();
};

class ChocolateBrownies: public Dessert
{

public: std::string getDescription();

public: double getPrice();

public: int getTimeToPrepare();
};

#endif //PROJECT_MENU_H

