#ifndef ACTORDEPENDENCIES_HPP
#define ACTORDEPENDENCIES_HPP
// place any constants here to keep track of size of arrays that change with an increase in elements/etc
#define NSTATS (int)(CharacterStats::NUMBER_OF_ELEMENTS)                //Used to keep track of the number of stats units have
#define NDAMAGET (int)(DamageType::NUMBER_OF_ELEMENTS)                  //Used to keep track of how many damage types are in the game
#define NSTATUSES (int)(StatusType::NUMBER_OF_ELEMENTS)                 //Used to keep track of how many status types are in the game
// place all dependencies and inclusions of libraries in this file
#include <string>
#include <iostream>
#include <list>
#include <random>
#include <map>
#include <vector>
#include "lua.hpp"
#include "vector2d.hpp"
#include "vector3d.hpp"

namespace LINUX 
{
    // This is a flagged enum
    // Enum is set to only be 16 bit size, FF has all flags open
    // Any new damage types are to be added inside this enum class
    // If required the size of the enum can be changed
    enum class DamageType : unsigned short{
        NONE = 1 << 0,                                              // Used for pure status, used to avoid damage calculations
        PHYSICAL = 1 << 1,
        MAGICAL = 1 << 2,
        PURE = 1 << 3,
        PSUEDO_PHYSICAL = 1 << 4,
        PSUEDO_MAGICAL = 1 << 5,
        PSUEDO_PURE = 1 << 6,
        RESTORATION = 1 << 7,
        THROW_ALL = 0xFFFF,                                        // Turn on all bitflags, useless for calculations, purely for testing
        NUMBER_OF_ELEMENTS = 8
    };
    std::map<CharacterStats, std::string> damageTypeMap;

    // This is a flagged enum
    // Enum is set to only be 16 bit size, FF has all flags open
    // Any new stats for units are to be added inside this enum class
    // If required the size of the enum can be changed
    enum class CharacterStats : unsigned short
    {
        UNIQUE = 1 << 0,                                                // No stat Type / Unique stat
        PATK = 1 << 1,                                                  // Physcial Attacks
        PDEF = 1 << 2,                                                  // Physical Armor
        MDEF = 1 << 3,                                                  // Magical Defense / Magic Resist
        AAMP = 1 << 4,                                                  // Ability Amplification
        SPED = 1 << 5,                                                  // Movement Speed
        CRTC = 1 << 6,                                                  // Critical Chance / Critical Hit Rate
        CRTA = 1 << 7,                                                  // Critical Damage / Critical Amplficiation
        RSLV = 1 << 8,                                                  // Resolve / Status Resistance
        APRC = 1 << 9,                                                  // Armor Pierce / Ignore Physical Armor
        MPRC = 1 << 10,                                                 // Magical Pierce / Ignore Magical Defense|Magic Resist
        MHP = 1 << 11,                                                  // Maximum Health Points
        MMP = 1 << 12,                                                  // Maximum Mana Points
        THROW_ALL = 0xFFFF,                                             // Turn on all bitflags, useless for calculations, purely for testing
        NUMBER_OF_ELEMENTS = 13
    };
    std::map<CharacterStats, std::string> characterStatsMap;
    // This is a flagged enum
    // Enum is set to only be 32 bit size, FFFF has all flags open
    // Any new Status types are to be added inside this enum class
    // If required the size of the enum can be changed
    enum class StatusType : unsigned int
    {
        //First Byte
        STATUS = 1 << 0,
        DAMAGE = 1 << 1,
        SEAL_SKILL = 1 << 2,
        SEAL_ITEM = 1 << 3,
        STAT_AMP = 1 << 4,
        STAT_FLAT = 1 << 5,
        DAMAGE_AMP = 1 << 6,
        STATUS_AMP = 1 << 7,

        //Second Byte
        STUN = 1 << 8,
        SILENCE = 1 << 9,
        KNOCKUP = 1 << 10,
        ROOTED = 1 << 11,
        SLOW = 1 << 12,
        FEAR = 1 << 13,
        DISABLED = 1 << 14,
        DEATH = 1 << 15,

        //Third Byte

        //Fourth Byte

        //Utility for StatusType Functions
        NUMBER_OF_ELEMENTS = 16
    };
    std::map<CharacterStats, std::string> statusTypeMap;

    class RandomGenerator
    {
        public:
        int Fetch();
        int Fetch(int min, int max);
        double Fetch(double min, double max);
        RandomGenerator();
        private:
        std::default_random_engine generator;
    };

    class StatHandler 
    {
    public:
    double amount;
    CharacterStats statType;
    std::string displayName;
    virtual void fetchStat();
    protected:
    };

    class Stats
    {
    public:
    StatHandler * slots;
    Stats(StatHandler test[NSTATS]):slots(test){};
        Stats operator+(const Stats& other);
        Stats operator-(const Stats& other);
        Stats operator/(const Stats& other);
        Stats operator*(const Stats& other);
    protected:
        void GetStats();
        void GetStats(CharacterStats x);
        void GetStats(CharacterStats x[]);
    };

    //Custom operators to add the Stats class together
    Stats Stats::operator+(const Stats& other) 
    {
    StatHandler placeHolderSlots[NSTATS];
        for(int i = 0; i < NSTATS; i++) 
        {
            placeHolderSlots[i].amount = slots[i].amount + other.slots[i].amount;
        }
        return Stats(placeHolderSlots);
    };
    Stats Stats::operator-(const Stats& other)
    {
    StatHandler placeHolderSlots[NSTATS];
        for(int i = 0; i < NSTATS; i++) 
        {
            placeHolderSlots[i].amount = slots[i].amount - other.slots[i].amount;
        }
        return Stats(placeHolderSlots);
    };
    Stats Stats::operator*(const Stats& other)
    {
    StatHandler placeHolderSlots[NSTATS];
        for(int i = 0; i < NSTATS; i++) 
        {
            placeHolderSlots[i].amount = slots[i].amount * other.slots[i].amount;
        }
        return Stats(placeHolderSlots);
    };
    Stats Stats::operator/(const Stats& other)
    {
    StatHandler placeHolderSlots[NSTATS];
        for(int i = 0; i < NSTATS; i++) 
        {
            placeHolderSlots[i].amount = slots[i].amount / other.slots[i].amount;
        }
        return Stats(placeHolderSlots);
    };

    class PassiveHandler
    {




    };

    class Passive : PassiveHandler
    {



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
        int CalculateEffect(DamageType _damageType) 
        {
            
        };
        DamagePotential damage;                 //Damage dealt each tick / second
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

    struct DamagePotential
    {
        double base;
        double variance;
        double high, low;

        DamageType damageElement;
    };

    struct Status
    {
        StatusType status;
    };

}
#endif