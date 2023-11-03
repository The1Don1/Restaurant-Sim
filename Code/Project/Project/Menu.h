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

class Beverage: public Menu
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class Starter: public Menu
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};

class MainDish: public Menu
{

public:
    std::string getDescription();

    double getPrice();

    int getTimeToPrepare();
};
class Dessert: public Menu
{

public: std::string getDescription();

public: double getPrice();

public: int getTimeToPrepare();
};

#endif //PROJECT_MENU_H

