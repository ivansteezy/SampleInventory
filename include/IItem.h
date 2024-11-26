#pragma once
#include <string>
#include <memory>

namespace Inventory {
    enum class ItemType {
        Generic,
        Weapon,
        Equipment,
        Potion,
        CraftingMaterials,
        Quest,
        Cosmetics,
        Money
    };

    std::ostream& operator<<(std::ostream& os, const ItemType& type) {
        switch (type)
        {
        case ItemType::Generic:
            os << "Generic";
            break;
        case ItemType::Weapon:
            os << "Weapon";
            break;
        case ItemType::Equipment:
            os << "Equipment";
            break;
        case ItemType::Potion:
            os << "Potion";
            break;
        case ItemType::CraftingMaterials:
            os << "CraftingMaterials";
            break;
        case ItemType::Quest:
            os << "Quest";
            break;
        case ItemType::Cosmetics:
            os << "Cosmetics";
            break;
        case ItemType::Money:
            os << "Money";
            break;
        default:
            os << "Unsupported value for ItemType: " << static_cast<int>(type);
            break;
        }
        return os;
    }

    // to do: const correctness..
    class IItem {
    public:
        virtual std::size_t getAmount() const = 0;
        virtual void setAmount(std::size_t newAmount) = 0;
        virtual void increaseAmount() = 0;
        virtual void decreaseAmount() = 0;
        virtual std::string getName() const = 0;
        virtual void setName(const std::string& name) = 0;
        virtual ItemType getType() const = 0;
        virtual void useItem() const = 0;
    };

    using IItemPtr = std::shared_ptr<IItem>;
}