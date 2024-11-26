#include "Item.h"
#include "Inventory.h"
#include <iostream>

int main() {
    std::cout << "Hola mundo!" << std::endl;

    constexpr auto useWeapon = []() {
        std::cout << "This is using a weapon" << std::endl;
    };

    constexpr auto usePotion = []() {
        std::cout << "This is using a potion" << std::endl;
    };

    auto sword = std::make_shared<Inventory::Item<decltype(useWeapon), Inventory::ItemType::Weapon>>(useWeapon);
    auto scimitar = std::make_shared<Inventory::Item<decltype(useWeapon), Inventory::ItemType::Weapon>>(useWeapon);

    auto redPotion = std::make_shared<Inventory::Item<decltype(usePotion), Inventory::ItemType::Potion>>(usePotion);
    auto bluePotion = std::make_shared<Inventory::Item<decltype(usePotion), Inventory::ItemType::Potion>>(usePotion);

    Inventory::IInventoryPtr inventory = std::make_shared<Inventory::Inventory>();

    inventory->addItem(sword);
    inventory->addItem(scimitar);
    inventory->addItem(redPotion);
    inventory->addItem(bluePotion);

    inventory->printInventory();
    inventory->loadInventoryFromFile("inventory.txt", ',');
    // inventory->saveInventoryIntoFile("inventory.txt");
}