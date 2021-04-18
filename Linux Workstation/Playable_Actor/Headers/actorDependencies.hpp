#ifndef ACTORDEPENDENCIES_H
#define ACTORDEPENDENCIES_H
// place any constants here to keep track of size of arrays that change with an increase in elements/etc
#define NSTATS (int)(CharacterStats::NUMBER_OF_ELEMENTS)            //Used to keep track of the number of stats units have
#define NDAMAGET (int)(DamageType::NUMBER_OF_ELEMENTS)              //Used to keep track of how many damage types are in the game
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
        TRUE = 1 << 3,
        PSUEDO_PHYSICAL = 1 << 4,
        PSUEDO_MAGICAL = 1 << 5,
        PSUEDO_TRUE = 1 << 6,
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
        THROW_ALL = 1 << 15,                                            // Turn on all bitflags, useless for calculations, purely for testing
        NUMBER_OF_ELEMENTS = 10
    };

    // This is a flagged enum
    // Enum is set to only be 32 bit size, FFFF has all flags open
    // Any new Status types are to be added inside this enum class
    // If required the size of the enum can be changed
    enum class STATUSTYPE : unsigned int
    {
        NONE = 1
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