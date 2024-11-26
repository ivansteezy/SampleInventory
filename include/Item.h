#pragma once

#include <iostream>

#include "IItem.h"
#include "Player.h"

namespace Inventory {
    template<typename T>
    concept ItemInvokable = std::invocable<T>;

    // Generic/fallback template
    template<ItemInvokable ItemUsage, ItemType Type>
    class Item : public IItem {
        static_assert(Type == ItemType::Generic, "Please implement specialization for that type"); // fallback for not supported types, werid looking huh?
    public:
        explicit Item(ItemUsage i) : mCallable(i) {}

        virtual std::size_t getAmount() const override {
            return mAmount;
        }

        virtual void setAmount(std::size_t newAmount) override {
            mAmount = newAmount;
        }

        virtual std::string getName() const override {
            return mName;
        }

        virtual void setName(std::string name) override {
            mName = name;
        }

        virtual ItemType getType() const override {
            return Type;
        }

        virtual void useItem() const override {
            std::cout << "Generic call" << std::endl;
            mCallable();
        }

    private:
        std::string mName;
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

        virtual void setAmount(std::size_t newAmount) override {
            mAmount = newAmount;
        }

        virtual std::string getName() const override {
            return mName;
        }

        virtual void setName(std::string name) override {
            mName = name;
        }

        virtual ItemType getType() const override {
            return ItemType::Weapon;
        }

        virtual void useItem() const override {
            mCallable();
        }

        // some other stuff related to Weapons
        void incrementWear() {
            mWearCounter++;
        }

        bool checkIfBroke() const {
            return mWearCounter > 100;
        }
        
    private:
        std::string mName;
        std::size_t mAmount;
        std::size_t mWearCounter;
        ItemUsage mCallable;
    };

    template<ItemInvokable ItemUsage>
    class Item<ItemUsage, ItemType::Potion> : public IItem {
    public:
        explicit Item(ItemUsage i) : mCallable(i) {}

        virtual std::size_t getAmount() const override {
            return mAmount;
        }

        virtual void setAmount(std::size_t newAmount) override {
            mAmount = newAmount;
        }

        virtual std::string getName() const override {
            return mName;
        }

        virtual void setName(std::string name) override {
            mName = name;
        }

        virtual ItemType getType() const override {
            return ItemType::Potion;
        }

        virtual void useItem() const override {
            mCallable();
        }

        // some other stuff related to Weapons
        void combinePotions(/*maybe other potion*/) {
            std::cout << "Combining potions" << std::endl;
        }
        
    private:
        std::string mName;
        std::size_t mAmount;
        ItemUsage mCallable;
    };
}