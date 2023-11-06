//
// Created by mathe on 2023/10/31.
//

#include "Kitchen.h"
void Kitchen::receiveOrder(std::vector<Dish*> orders) {
    for (auto* order : orders) {
        headChef->AddDish(order);
    }
}