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
    typeVec3<float> Position;
    typeVec3<float> Velocity;
    typeVec3<float> Force;

    float Mass;

};

class PhysicsWorld 
{
private:
std::vector<PhysicsObject3d*> mObjects;
vector3 mGravity = vector3(0.0f,-9.81f,0.0f);

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

    void Step(float dt) 
    {
        for(PhysicsObject3d* obj : mObjects) 
        {
            obj->Force += obj->Mass * mGravity;
            obj->Velocity += obj->Force / obj->Mass * dt;
            obj->Position += obj->Velocity * dt;
            
            obj->Force = vector3(0.0f,0.0f,0.0f);
        }
    }

};


}
#endif