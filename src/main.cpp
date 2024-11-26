#include "Item.h"
#include <iostream>

int main() {
    std::cout << "Hola mundo!" << std::endl;
    // Inventory::Item<float, Inventory::ItemType::Weapon> sword;
    // Player::Player<float, Player::PlayerClass::Warrior> i;

    constexpr auto spendMoney = []() {
        std::cout << "This is using a weapon" << std::endl;
    };

    Inventory::Item<decltype(spendMoney), Inventory::ItemType::Weapon> item(spendMoney);
    item.useItem();
}