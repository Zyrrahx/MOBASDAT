#ifndef ACTORDEPENDENCIES_H
#define ACTORDEPENDENCIES_H
//place all dependencies and inclusions of libraries in this file
#include <string>
#include <iostream>
#include <list>
#include <map>
#include "LuaHeaders/lua.hpp"

namespace LINUX 
{
    // This is a flagged enum
    // Enum is set to only be 16 bit size, FF has all flags open
    enum class DAMAGETYPE : unsigned short{
        NONE = 1 << 0,                                      // Used for pure status, used to avoid damage calculations
        PHYSICAL = 1 << 1,
        MAGICAL = 1 << 2,
        TRUE = 1 << 3,
        PSUEDO_PHYSICAL = 1 << 4,
        PSUEDO_MAGICAL = 1 << 5,
        PSUEDO_TRUE = 1 << 6,
        RESTORATION = 1 << 7,
        THROW_ALL = 1 << 15                                 // Turn on all bitflags, useless for calculations, purely for testing
    };

    enum class STATUSTYPE 
    {
        NONE = 1
    };

}





#endif