#ifndef VECTOR3EXTENSIONS_HPP
#define VECTOR3EXTENSIONS_HPP
//The point of this file is to extend the functionality of the vector3 class
//Adds functionality if vector3.hpp and quaternion.hpp are included.
#if __has_include("vector3.hpp") && __has_include("quaternion.hpp")        
#include "vector3.hpp"
#include "quaternion.hpp"
namespace LINUX 
{
    template<class T> typeVec3<T> operator *(const quaternion& q, const typeVec3<T>& v)                                  //Rotate vector by quaternion
{
    typeVec3<float> u = typeVec3<float>(q.x, q.y, q.z);
    typeVec3<T> temp;                                       //Temporary vector3<T> to return
    float scalar = q.w;                                     //Scalar
    temp =  2.0f * DotProduct(u,v) * u +            
            (scalar*scalar - DotProduct(u,u)) * v +
            2.0f * scalar * CrossProduct(u,v);
    return temp;
}

}
#endif
//This class is used to extend the functionality of the vector3 template/type

namespace LINUX 
{





}



#endif