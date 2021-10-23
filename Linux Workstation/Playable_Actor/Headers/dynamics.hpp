#ifndef DYNAMICS_HPP
#define DYNAMICS_HPP
#include <cmath>
#include <vector>
#include "vector2.hpp"
#include "vector3.hpp"
#include "quaternion.hpp"

namespace LINUX {

struct PhysicsObject3d 
{
    vector3<float> Position;
    vector3<float> Velocity;
    vector3<float> Force;

    float Mass;

};

struct PhysicsObject2d
{
    vector2<float> Position;
    vector2<float> Velocity;
    vector2<float> Force;

    float Mass;

};

class PhysicsWorld 
{
private:
std::vector<PhysicsObject3d*> mObjects;

public:
    void AddObject(PhysicsObject3d* object) 
    {
        mObjects.push_back(object);
    }

    void RemoveObject(PhysicsObject3d* object) 
    {
        if(!object) return;
        auto itr = std::find(mObjects.begin(), mObjects.end(), object);
        if(itr == mObjects.end()) return;
        mObjects.erase(itr);
    }
};


}
#endif