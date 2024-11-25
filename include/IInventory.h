#pragma once

#include <memory>
#include "IItem.h"

namespace Inventory {
	class IInventory {
	public:
		virtual void addItem() = 0;
		virtual void printInventory() const = 0;
		virtual const IItem& combineItems(const IItem& items) = 0;
		virtual bool saveInventoryIntoFile(const std::string& fileName) = 0;
		virtual bool loadInventoryFromFile(const std::string& fileName) = 0;
	};

	using InventoryPtr = std::shared_ptr<IInventory>;
}
