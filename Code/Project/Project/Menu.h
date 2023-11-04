//
// Created by mathe on 2023/10/31.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H
#include "iostream"
#include "Dish.h"
class Menu{
protected:
    std::string description;
    int timeToPrepare;
    double price;
public:
    std::string getDescription();
    double getPrice();
    int getTimeToPrepare();
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
    int getTimeToPrepare() ;
};

class Coleslaw: public MenuDecorator
{
private:
    std::string additionDescription;
    double additionPrice;
    int additionTimeToPrepare;
public:
    std::string getDescription();
    double getPrice();
    Coleslaw(Menu* baseItem, std::string description, double price, int timeToprepare);
    int getTimeToPrepare();
};

class MushroomSauce: public MenuDecorator
{
private:
    std::string additionDescription;
    double additionPrice;
    int additionTimeToPrepare;
public:
    std::string getDescription();
    double getPrice();
    MushroomSauce(Menu* baseItem, std::string description, double price, int timeToprepare);
    int getTimeToPrepare();
};

class Salad: public MenuDecorator
{
private:
    std::string additionDescription;
    double additionPrice;
    int additionTimeToPrepare;
public:
    std::string getDescription();
    double getPrice();
    Salad(Menu* baseItem, std::string description, double price, int timeToprepare);
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
};

class CokeZero: public Beverage
{
    public:
        CokeZero();
};

class Coke: public Beverage
{
    public:
        Coke();
};

class Sprite: public Beverage
{
    public:
        Sprite();
};

class StrawberryMilkshake: public Beverage

    public:
        StrawberryMilkshake();
};


class BubblegumMilkshake: public Beverage
{
    public:
        BubblegumMilkshake();
}; 

////////
class Starter: public Menu
{
    /**
     * @brief Starters base class
     * Starters are onion rings, chicken wings and chicken nuggets
     * Starters will all take 5 seconds to prepare
     */
};

class OnionRings: public Starter
{

public:
    OnionRings();
};

class ChickenWings: public Starter
{

public:
    ChickenWings();
};

class Chips: public Starter
{

public:
    Chips();
};

class ChickenNuggets: public Starter
{

public:
    ChickenNuggets();
};

///////
class MainDish: public Menu
{
    /**
     * @brief Main dishes base class
     * Main dishes are cheeseburgers, hot dogs, mac and cheese, bbq ribs, chicken tenders, cheesesteak, bbq steak and buffalo wings
     * Main dishes will all take 10 seconds to prepare
     */
};

class CheeseBurger: public MainDish
{

public:
    CheeseBurger();
};

class HotDog: public MainDish
{

public:
    HotDog();
};

class MacAndCheese: public MainDish
{

public:
    MacAndCheese();
};

class BBQRibs: public MainDish
{

public:
    BBQRibs();
};

class ChickenTenders: public MainDish
{

public:
    ChickenTenders();
};

class CheeseSteak: public MainDish
{

public:
    CheeseSteak();
=======
};

class BBQSteak: public MainDish
{

public:
    BBQSteak();
};

class BuffaloWings: public MainDish
{

public:
    BuffaloWings();
};

/////
class Dessert: public Menu
{
    /**
     * @brief Desserts base class
     * Desserts are waffle, chocolate brownies, donuts and pancakes
     * Desserts will all take 3 seconds to prepare
     */
};

class Pancakes: public Dessert
{

public: 
    Pancakes();
};


class Donuts: public Dessert
{

public: 
    Donuts();
};


class Waffles: public Dessert
{
public:
    Waffles();
};

class ChocolateBrownies: public Dessert
{
public:
    ChocolateBrownies();
};

#endif //PROJECT_MENU_H

