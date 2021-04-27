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
        void addItemStats();                                                                //Add all stats from every item
        void addItemStats(int slotNumber, CharacterStats singleStat);                       //Add a single stat from a single item
        void addItemStats(int slotNumbers[], CharacterStats singleStat);                    //Add a single stat from an array of items IE... {1,3,5};
        void addItemStats(int slotNumber);                                                  //Add all stats from a single item
        void addItemStats(int slotNumbers[]);                                               //Add all stats from an array of items IE... {2,3,6};
        void addItemStats(CharacterStats singleStat);                                       //Add a single stat from every item
        void addItemStats(CharacterStats multipleStats[]);                                  //Add an array of stats IE... {PATK, PDEF, AAMP, SPED} from every item
        void addItemStats(int slotNumber, CharacterStats multipleStats[]);                  //Add an array of stats IE... {PDEF, SPED, AAMP} from a single item
        void addItemStats(int slotNumbers[], CharacterStats multipleStats[]);               //Add an array of stats IE... {AAMP, CRTC, PDEF} from an array of items IE... {2,3,5};
    };

    class Item {
    public:
        std::string displayName;
        Stats stats;
        //std::vector<int, std::string> passiveNames;               <--Concept is correct but a tag system is required {tag class must be created}
    protected:
        //std::map<int, Passive> passives;                          <--Concept is correct but a tag system is required {tag class must be created}
    };
}
    //Acts as the database for buyable items
namespace ItemPool {




}



#endif