#ifndef ACTORDEPENDENCIES_H
#define ACTORDEPENDENCIES_H
// place any constants here to keep track of size of arrays that change with an increase in elements/etc
#define NSTATS (int)(CharacterStats::NUMBER_OF_ELEMENTS)                //Used to keep track of the number of stats units have
#define NDAMAGET (int)(DamageType::NUMBER_OF_ELEMENTS)                  //Used to keep track of how many damage types are in the game
#define NSTATUSES (int)(StatusType::CURRENT_NUMBER_OF_STATUS_EFFECTS)   //Used to keep track of how many status types are in the game
// place all dependencies and inclusions of libraries in this file
#include <string>
#include <iostream>
#include <list>
#include <map>
#include "LuaHeaders/lua.hpp"

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
        THROW_ALL = 1 << 15,                                        // Turn on all bitflags, useless for calculations, purely for testing
        NUMBER_OF_ELEMENTS = 9
    };

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
        THROW_ALL = 1 << 15,                                            // Turn on all bitflags, useless for calculations, purely for testing
        NUMBER_OF_ELEMENTS = 12
    };

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
        CURRENT_NUMBER_OF_STATUS_EFFECTS = 16
    };

    class StatHandler 
    {
    public:
    double amount;
    std::string displayName;
    virtual void fetchStat();
    protected:
    };

    class Stats
    {
    public:
    StatHandler slots[NSTATS];


    protected:




    };
}





#endif