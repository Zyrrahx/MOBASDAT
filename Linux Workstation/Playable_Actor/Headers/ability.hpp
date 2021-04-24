#ifndef ABILITY_H
#define ABILITY_H
#include "actorDependencies.hpp"
#include "playableActor.hpp"

namespace LINUX 
{
    //Ability writing and reading is to be done in lua, fed back into C++ using their respective handlers
    class AbilityHandler
    {
    public:
        std::string displayName = "Empty_Ability";                          //Display name of the ability
        void virtual Execute(int from, int to);                             //Run through the abilityEffects with a range, from and to, ex index 2 to 7 etc...
        void virtual Execute(int index);                                    //Run a single effect in the effect list with the number supplied via index
        void virtual Execute();                                             //Run through the abilityEffects and apply them one by one                  
    protected:
        std::map<int, EffectHandler> abilityEffects;                        //Each effect that the ability applies, the index is the order in which they occur
    };
}


#endif