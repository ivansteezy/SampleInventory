#include "Item.h"
#include "Inventory.h"
#include <iostream>

int main() {
    std::cout << "Hola mundo!" << std::endl;

    constexpr auto useWeapon = []() {
        std::cout << "This is using a weapon" << std::endl;
    };
    auto sword = std::make_shared<Inventory::Item<decltype(useWeapon), Inventory::ItemType::Weapon>>(useWeapon);
    sword->useItem();

    constexpr auto usePotion = []() {
        std::cout << "This is using a potion" << std::endl;
    };
    auto redPotion = std::make_shared<Inventory::Item<decltype(usePotion), Inventory::ItemType::Potion>>(usePotion);
    redPotion->useItem();

    Inventory::IInventoryPtr inventory = std::make_shared<Inventory::Inventory>();
    inventory->addItem(sword);
    inventory->addItem(redPotion);

    inventory->printInventory();
}