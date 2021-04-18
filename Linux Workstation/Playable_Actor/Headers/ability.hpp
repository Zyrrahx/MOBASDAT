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
        std::string displayName = "Empty_Ability";
        std::map<int, EffectHandler> abilityEffects;
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
        int CalculateEffect(DamageType _damageType, Character* _caster, Character* _target);
        Damage applicableEffect;
        double duration;                       //Duration of 0 will mean it only effects a single tick
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
    };

    struct Status
    {
        STATUSTYPE status;
    };
}


#endif