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
        AbilityList abilities;
        Stats baseStats;
        Inventory inventory;
        
    private:
        void FetchActorFile();
    };





}
#endif