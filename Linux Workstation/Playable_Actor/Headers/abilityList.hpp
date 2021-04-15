#ifndef ABILITYLIST_H
#define ABILITYLIST_H
#include "ability.hpp"

namespace LINUX 
{
    class AbilityList
    {
    public:
        int numberOfAbilities;
        std::map<int, AbilityBase> Slot;                    //utilize map to avoid duplicates of keys
    protected:
    };



}

#endif