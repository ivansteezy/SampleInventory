#pragma once

#include <memory>
#include "IItem.h"

namespace Inventory {
	class IInventory {
	public:
		virtual void addItem(IItemPtr item) = 0;
		virtual void printInventory() const = 0;
		virtual bool saveInventoryIntoFile(const std::string& fileName) = 0;
		virtual bool loadInventoryFromFile(const std::string& fileName) = 0;
	};

	using IInventoryPtr = std::shared_ptr<IInventory>;
}
