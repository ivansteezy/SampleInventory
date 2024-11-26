#include <map>
#include <iostream>
#include <algorithm>

#include "IInventory.h"

namespace Inventory {
    class Inventory : public IInventory{
    public:
		virtual void addItem(IItemPtr item) override {
            auto it = mItems.find(item->getType());
            if (it != mItems.end()) {
                it->second.first++;
            } else {
                mItems.insert({item->getType(), {1, item}});
            }
        }

		virtual void printInventory() const override {
            for(const auto& a : mItems) {
                std::cout << "Cantidad: [" << a.second.first << "] Nombre: [" << a.second.second->getName() << "]\n"; // magia del polimorfismo
            }

            std::cout << std::endl;
        }

		virtual bool saveInventoryIntoFile(const std::string& fileName) override {
            // to do...
        }

		virtual bool loadInventoryFromFile(const std::string& fileName) override {
            // to do...
        }

    private:
        std::map<ItemType, std::pair<int, IItemPtr>> mItems;
    };
}