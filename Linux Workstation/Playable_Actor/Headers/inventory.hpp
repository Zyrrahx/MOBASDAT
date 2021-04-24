#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "abilityList.hpp"

namespace LINUX {
    class Inventory {
    public:
        Item items[6];
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