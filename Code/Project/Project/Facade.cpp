//
// Created by mathe on 2023/10/30.
//

#include <limits>
#include "Facade.h"
using namespace std;

void Facade::Decrement() {
    mediator->notify();
}
void Facade::displayMenu() {
    int choice;
    do{
        floor->printWaiters();
        std::cout << "1. Create waiter\n";
        std::cout << "2. refresh\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        switch(choice){
            case 1:
                createWaiter();
                break;
            case 2:
                continue;
//                floor->printWaiters();
//                system("cls");
//                break;
            case 3:
                std::cout << "Goodbye!\n" << std::endl;
                std::terminate(); //end all threads
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }


    } while (choice != 3);
}

void Facade::createWaiter(){
//    system("clear");
//    floor->printWaiters();1
    std::cout << "Enter the Waiter's name" << std::endl;
    std::string name;
    std::cin >> name;
//    generalWaiter *t;
//    srand((unsigned) time(NULL));
//    int random = 100 + (rand() % 20);
    floor->constructWaiter(name, hc);

}

Facade::Facade() {
}

void Facade::operation() {
    throw "Not yet implemented";
}

Facade::Facade(string aFacade) {
}

