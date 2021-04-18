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
        void virtual Execute();                                             //Run through the abilityEffects and apply them one by one                  
    protected:
        std::map<int, EffectHandler> abilityEffects;                        //Each effect that the ability applies, the index is the order in which they occur
    };

    //Used to apply effects/damage to a character via ability classes
    class EffectHandler
    {
    public:
        DamageType effectType;
        virtual void CallEffect();
    protected:

    };

    class DamageEffect : EffectHandler 
    {
    public:
        void CallEffect() override;
    protected:
        int CalculateEffect(DamageType _damageType, Character* _target) 
        {
            
        };
        Damage damage;                          //Damage dealt each tick / second
        double duration;                        //Duration of 0 will mean it only effects a single tick
    };

    class StatusEffect : EffectHandler
    {
    public:
        void CallEffect() override;

    protected:
        void CalculateEffect();
        Status applicableEffect;
        double duration;                        //Duration of 0 will mean it only effects a single tick
    };

    struct Damage 
    {
        double amount;
        double variance;
        DamageType damageElement;
    };

    struct Status
    {
        STATUSTYPE status;
    };
}


#endif