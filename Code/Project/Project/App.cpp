//
// Created by mathe on 2023/10/30.
//
#include "Facade.h"
#include "Engine.h"
#include <thread>
#include <iostream>

using namespace std;
class App{
public:
        explicit App(int timerSeconds);

        void startSimulation(){
//            std::thread timerThread(&App::timerFunction, this);
            f->displayMenu();
        }
        void setFacade(Facade* f){
            this->f = f;
        }
private:
    Facade* f;
        int timerSeconds;
            /*void timerFunction() {
                while (timerSeconds > 0) {
                    std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleep for 1 second
                    timerSeconds--;
                    f->Decrement();
                }
                std::cout << "Timer has reached 0 seconds." << std::endl;
        }*/
};

App::App(int timerSeconds) : timerSeconds(timerSeconds), f(nullptr){}


int main(){
    Engine* e = new Engine();
    Floor* floor = new Floor();
    floor->constructTable();
    Facade* facade = new Facade(floor, e);
    int simulationTime = 99999;
    App sim(simulationTime);
    sim.setFacade(facade);
    sim.startSimulation();
    delete facade;
    return 0;
}