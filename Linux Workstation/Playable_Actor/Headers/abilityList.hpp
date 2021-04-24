#ifndef ABILITYLIST_H
#define ABILITYLIST_H
#define MAXABILITYSLOTS 9;
#include "ability.hpp"

namespace LINUX 
{
    class AbilityList
    {
    public:
        int numberOfAbilities;
        std::map<int, AbilityHandler> Slot;                    //utilize map to avoid duplicates of keys
    protected:
    };



}

#endif