#ifndef ABILITY_H
#define ABILITY_H
#include "actorDependencies.hpp"
#include "playable_actor.hpp"

namespace LINUX 
{
    class AbilityBase
    {
    public:
        std::string displayName = "Empty_Ability";
        std::map<int, EffectBase> abilityEffects;
    };

    //Used to apply effects/damage to a character via ability classes
    class EffectBase
    {
    public:
        DAMAGETYPE effectType;
        virtual void CallEffect();
    protected:

    };

    class DamageEffect : EffectBase 
    {
    public:
        void CallEffect() override;
    protected:
        int CalculateEffect(DAMAGETYPE _damageType, Character* _caster, Character* _target);
        Damage applicableEffect;
        double duration;                       //Duration of 0 will mean it only effects a single tick
    };

    class StatusEffect : EffectBase
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
    };

    struct Status
    {
        STATUSTYPE status;
    };
}


#endif