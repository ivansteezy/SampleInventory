#include <vector>
#include <iostream>

#include "IInventory.h"

namespace Inventory {
    class Inventory : public IInventory{
    public:
		virtual void addItem(IItemPtr item) override {
            mItems.push_back(item);
        }

		virtual void printInventory() const override {
            for(const auto& a : mItems) {
                std::cout << "Cantidad: [" << a->getAmount() << "] Nombre: [" << a->getName() << "]\n"; // magia del polimorfismo
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
        std::vector<IItemPtr> mItems;
    };
}