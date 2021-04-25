#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#define NINVENTORYSLOTS 6
#include "abilityList.hpp"

namespace LINUX {
    class Inventory {
    public:
        Item items[NINVENTORYSLOTS];
        Stats bonusStats;
    protected:
        void addItemStats();
        void addItemStats(CharacterStats singleStat);

    };

    class Item {
    public:
        std::string displayName;
        Stats stats;
    protected:
        std::map<int, Passive> passives;
    };
}
    //Acts as the database for buyable items
namespace ItemPool {




}



#endif