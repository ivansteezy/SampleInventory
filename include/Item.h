#pragma once
#include "IItem.h"
#include "Player.h"

namespace Inventory {
    // T could be an std function
    template<typename Scalator, ItemType Type>
    class Item : public IItem {
    public:
        virtual std::size_t getAmount() const override {
            return mAmount;
        }

        virtual ItemType getType() const override {
            return Type;
        }

        virtual void useItem() const override {

        }

    private:
        std::size_t mAmount;
        Scalator mScaling;
    };

    // Partial specialization for Weapons
    template<typename Scalator>
    class Item<Scalator, ItemType::Weapon> : public IItem {
    public:
        virtual std::size_t getAmount() const override {
            return mAmount;
        }

        virtual ItemType getType() const override {
            return ItemType::Weapon;
        }

        virtual void useItem() const override {
            
        }
    private:
        std::size_t mAmount;
        Scalator mScaling;
    };

    // Partial specialization for Equipment
    template<typename Scalator>
    class Item<Scalator, ItemType::Equipment> : public IItem{
    public:
        virtual std::size_t getAmount() const override {
            return mAmount;
        }

        virtual ItemType getType() const override {
            return ItemType::Equipment;
        }

        virtual void useItem() const override {

        }
    private:
        std::size_t mAmount;
        Scalator mScaling;
    };

    // Partial specialization for Consumables
    template<typename Scalator>
    class Item<Scalator, ItemType::Consumables> : public IItem{
    public:
        virtual std::size_t getAmount() const override {
            return mAmount;
        }

        virtual ItemType getType() const override {
            return ItemType::Consumables;
        }

        virtual void useItem() const override {

        }
    private:
        std::size_t mAmount;
        Scalator mScaling;
    };

}