#pragma once
#include <string>

namespace Inventory {
    enum class ItemType {
        Weapon,
        Equipment,
        Consumables,
        CraftingMaterials,
        Quest,
        Cosmetics,
        Money
    };

    class IItem {
    public:
        virtual std::size_t getAmount() const = 0;
        virtual ItemType getType() const = 0;
        virtual void useItem() const = 0;
    };
}