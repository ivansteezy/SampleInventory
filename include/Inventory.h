#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>

#include "IInventory.h"

namespace Inventory {
    class Inventory : public IInventory, std::enable_shared_from_this<Inventory> {
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
            std::cout << *this;
        }

		virtual bool saveInventoryIntoFile(const std::string& fileName) override {
            std::ofstream file(fileName);
            if (file.is_open()) {
                file << *this;
                file.close();
                return true;
            } else {
                std::cerr << "Error: Can not open file to write inventory" << std::endl;
                return false;
            }
        }

		virtual bool loadInventoryFromFile(const std::string& fileName) override {
            auto x  = fileName;
            return true;
        }

        virtual InventoryMap getInventory() const override {
            return mItems;
        }

        friend std::ostream& operator<<(std::ostream& os, const Inventory& inventory) {
            if (os.rdbuf() == std::cout.rdbuf()) {
                for(const auto& a : inventory.getInventory()) {
                    os << "Cantidad: [" << a.second.first 
                       << "] Nombre: [" << a.second.second->getName() 
                       << "]\n";
                }
                os << std::endl;
            } else {
                for(const auto& i : inventory.getInventory()) {
                    os << i.second.first << "," 
                       << i.second.second->getName() << "," 
                       << static_cast<int>(i.second.second->getType());
                }
            }
            return os;
        }

    private:
        std::map<ItemType, std::pair<int, IItemPtr>> mItems;
    };
}