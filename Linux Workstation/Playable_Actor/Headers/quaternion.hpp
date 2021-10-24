#ifndef QUATERNION_H
#define QUATERNION_H
#include <cmath>
#include "vector3.hpp"

#define PI 3.14159265358979323846

namespace LINUX {

class quaternion 
{
    public:
        quaternion();
        ~quaternion();

        void CreateMatrix(float *pMatrix);
        void CreateFromAxisAngle(   const float &in_x,
                                    const float &in_y,
                                    const float &in_z,
                                    const float &in_degrees);
        
        vector3 fetchScalarComponent();
        quaternion operator *(const quaternion &q);
        float x, y, z, w;
};

}

#endif