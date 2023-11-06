cmake_minimum_required(VERSION 3.26)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project
        Table.cpp
        Table.h
        Customer.cpp
        Customer.h
        Waiter.cpp
        Waiter.h
        Floor.cpp
        Floor.h
        App.cpp
        Facade.cpp
        Facade.h
        Engine.cpp
        Engine.h
        Bill.cpp
        Bill.h
        Visitor.cpp
        Visitor.h
        TableIterator.h
        TableIterator.cpp
        Kitchen.cpp
        Kitchen.h
        Chef.cpp
        Chef.h
        Menu.cpp
        Menu.h
        Dish.cpp
        Dish.h
        Tab.cpp
        Tab.h
        Manager.cpp
        Manager.h
)
