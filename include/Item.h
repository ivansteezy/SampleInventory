#pragma once
#include "IItem.h"
#include "Player.h"

namespace Inventory {
    template<typename T>
    concept ItemInvokable = std::invocable<T>;

    template<ItemInvokable ItemUsage, ItemType Type>
    class Item : public IItem {
    public:
        explicit Item(ItemUsage i) : mCallable(i) {}

        virtual std::size_t getAmount() const override {
            return mAmount;
        }

        virtual ItemType getType() const override {
            return Type;
        }

        virtual void useItem() const override {
            mCallable();
        }

    private:
        std::size_t mAmount;
        ItemUsage mCallable;
    };

    template<ItemInvokable ItemUsage>
    class Item<ItemUsage, ItemType::Weapon> : public IItem {
    public:
        explicit Item(ItemUsage i) : mCallable(i) {}

        virtual std::size_t getAmount() const override {
            return mAmount;
        }

        virtual ItemType getType() const override {
            return ItemType::Weapon;
        }

        virtual void useItem() const override {
            mCallable();
        }
    private:
        std::size_t mAmount;
        ItemUsage mCallable;
    };
}