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
        {CharacterStats::PATK, "physical_attack"},
        {CharacterStats::PDEF, "physical_defense"},
        {CharacterStats::MDEF, "magic_resist"},
        {CharacterStats::AAMP,  "ability_amplification"},
        {CharacterStats::SPED,  "movement_speed"},
        {CharacterStats::CRTC,  "critical_chance"},
        {CharacterStats::CRTA,  "critical_amplification"},
        {CharacterStats::RSLV,  "status_resistance"},
        {CharacterStats::APRC,  "physical_armor_bypass"},
        {CharacterStats::MPRC,  "magical_armor_bypass"},
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
        {DamageType::PSUEDO_PHYSICAL, "psuedo_physical"},
        {DamageType::PSUEDO_MAGICAL, "psuedo_magical"},
        {DamageType::PSUEDO_PURE, "psuedo_pure"},
        {DamageType::RESTORATION, "healing"},
        {DamageType::THROW_ALL, "error, all flags on"},
        {DamageType::NUMBER_OF_ELEMENTS, "used for the number of elements, or equal to the integer 8"},
    };
    
