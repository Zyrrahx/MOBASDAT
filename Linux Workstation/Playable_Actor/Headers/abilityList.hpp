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
        std::vector<AbilityHandler> Slot();
        AbilityList(int nAbilitySlots);
        AbilityList(int nAbilitySlots, std::vector<AbilityHandler> _abilityList);
    protected:
    };



}

#endif