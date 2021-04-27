#include "actorDependencies.hpp"

using namespace LINUX; 
    RandomGenerator::RandomGenerator() {};
    int RandomGenerator::Fetch(int min, int max) 
    {
        std::uniform_int_distribution<int> xx(min, max);
        int rollDamage = xx(generator);
        return rollDamage;
    };
    double RandomGenerator::Fetch(double min, double max) 
    {
        std::uniform_real_distribution<double> xx(min, max);
        double rollDamage = xx(generator);
        return rollDamage;
    };
    int RandomGenerator::Fetch() 
    {
        return rand();
    };

    std::map<CharacterStats, std::string> characterStatsMap =
    {
        {CharacterStats::UNIQUE, "unique"},
        {CharacterStats::PATK, "physical_Attack"},
        {CharacterStats::PDEF, "physical_Defense"},
        {CharacterStats::MDEF, "magic_Resist"},
        {CharacterStats::AAMP,  "ability_Amplification"},
        {CharacterStats::SPED,  "movement_Speed"},
        {CharacterStats::CRTC,  "critical_Chance"},
        {CharacterStats::CRTA,  "critical_Amplification"},
        {CharacterStats::RSLV,  "status_Resistance"},
        {CharacterStats::APRC,  "physical_Armor_Bypass"},
        {CharacterStats::MPRC,  "magical_Armor_Bypass"},
        {CharacterStats::MHP,  "HP"},
        {CharacterStats::MMP,  "MP"},
        {CharacterStats::THROW_ALL,  "typeNull"},
        {CharacterStats::NUMBER_OF_ELEMENTS,  "typeNull"},
    };

    std::map<DamageType, std::string> damageTypeMap = 
    {
        {DamageType::NONE, "none"},
        {DamageType::PHYSICAL, "physical"},
        {DamageType::MAGICAL, "magical"},
        {DamageType::PURE, "pure"},
        {DamageType::PSUEDO_PHYSICAL, "psuedo_Physical"},
        {DamageType::PSUEDO_MAGICAL, "psuedo_Magical"},
        {DamageType::PSUEDO_PURE, "psuedo_Pure"},
        {DamageType::RESTORATION, "healing"},
        {DamageType::THROW_ALL, "error, all flags on"},
        {DamageType::NUMBER_OF_ELEMENTS, "used for the number of elements, or equal to the integer 8"},
    };
    
