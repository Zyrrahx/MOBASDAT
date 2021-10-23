#ifndef QUATERNION_H
#define QUATERNION_H
#include <cmath>
#include "vector3d.hpp"

#define PI 3.14159265358979323846


class Quaternion 
{
    public:
        Quaternion();
        ~Quaternion();

        void CreateMatrix(float *pMatrix);
        void CreateFromAxisAngle(   const float &in_x,
                                    const float &in_y,
                                    const float &in_z,
                                    const float &in_degrees);
        
        LINUX::Vector3d<float> fetchScalarComponent();
        Quaternion operator *(const Quaternion &q);
        float x, y, z, w;
};

#endif