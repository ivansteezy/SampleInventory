#include "Item.h"
#include <iostream>

int main() {
    std::cout << "Hola mundo!" << std::endl;
    Inventory::Item<float, Inventory::ItemType::Weapon> sword;
    Player::Player<float, Player::PlayerClass::Warrior> i;
}