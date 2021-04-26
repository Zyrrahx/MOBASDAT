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
    }

    
