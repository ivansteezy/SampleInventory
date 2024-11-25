#pragma once
#include <functional>
#include "IInventory.h"

namespace Parser {
    class IFileParser {
    public:
        virtual Inventory::InventoryPtr parseFromFile(const std::string& filePath, std::function<bool(char)> delimiterFilter) = 0;
    };
}
