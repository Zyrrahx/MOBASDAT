#ifndef PLAYABLE_ACTOR_HPP
#define PLAYABLE_ACTOR_HPP
#include "inventory.hpp"

//Namespace for keeping what was made in a Linux environment clear
namespace LINUX {
    //Class for handling all character related components of a GameObject
    class Character 
    {
    public:
        std::string displayName = "Empty_Character";
        Stats currentStats;
    protected:
        lua_State* L;
        std::string characterArchivePath;
        AbilityList abilities;
        Stats baseStats;
        Stats growthRates;
        Inventory inventory;

        //Read functions utilize Lua functionality to fetch the data
        //Use of lua_state is required
        void ReadCharacterFile();
        void ReadCharacterFile(std::string toFetch);
        void ReadCharacterFile(std::string toFetch[]);

        void ReadAbility();
        void ReadAbility(int x);
        void ReadAbility(int x[]);
        
    private:
        void FetchActorFile();
    };
}
#endif