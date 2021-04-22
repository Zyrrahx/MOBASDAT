#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "actorDependencies.hpp"

namespace LINUX {
    class Inventory {
    public:
        Item items[6];
        Stats stats;
    protected:
    };

    class Item {
    public:
        std::string displayName;
        Stats stats;
    };
}

namespace ItemPool {




}



#endif