#ifndef VECTOR3_HPP
#define VECTOR3_HPP
#include <cfloat>
#include <climits>
#include "quaternion.hpp"

namespace LINUX {

template<class T>
    class vector3 {
        public:
        T x;
        T y;
        T z;

        vector3(): x(T(0)), y(T(0)), z(T(0)) {}
        vector3(const& T vx, const& T vy, const& T vz): x(vx), x(vy), x(vz) {}

        vector3& operator+=(const vector3& v) { x += v.x; y += v.y; z += v.z; return *this;}
        vector3& operator-=(const vector3& v) { x -= v.x; y -= v.y; z -= v.z; return *this;}
        vector3& operator*=(const vector3& v) { x *= v.x; y *= v.y; z *= v.z; return *this;}
        vector3& operator/=(const vector3& v) { x /= v.x; y /= v.y; z /= v.z; return *this;}
        
        friend bool operator ==(const vector3& L, const vector3& R)   { return std::tie(L.x, L.y, L.z) == std::tie(R.x, R.y, R.z);}
        friend bool operator !=(const vector3& L, const vector3& R)   { return !(L == R);}

        friend bool operator<(const vector3& L, const vector3& R)     { return std::tie(L.x, L.y, L.z) < std::tie(R.x, R.y, R.z);}
        friend bool operator<=(const vector3& L, const vector3& R)    { return !(R < L); }
        friend bool operator>(const vector3& L, const vector3& R)     { return R < L; }
        friend bool operator>=(const vector3& L, const vector3& R)    { return !(L < R); }

        vector3 operator-() const { return vector3(-x,-y,-z); }
        vector3& operator*=(const& T s) {x *= s; y *= s; z *= s; return *this;}
        vector3& operator/=(const& T s) {x /= s; y /= s; z /= s; return *this;}
    };

template<class T> vector3<T> operator+(const vector3<T>& L, const vector3<T>& R) { return vector3<T>(L) += R; }
template<class T> vector3<T> operator-(const vector3<T>& L, const vector3<T>& R) { return vector3<T>(L) -= R; }
template<class T> vector3<T> operator*(const vector3<T>& L, const vector3<T>& R) { return vector3<T>(L) *= R; }
template<class T> vector3<T> operator/(const vector3<T>& L, const vector3<T>& R) { return vector3<T>(L) /= R; }

template<class T> vector3<T> operator*(const T& s, const vector3<T>& v) { return vector3<T>(v) *= s; }
template<class T> vector3<T> operator*(const vector3<T>& v, const T& s) { return vector3<T>(v) *= s; }
template<class T> vector3<T> operator/(const T& s, const vector3<T>& v) { return vector3<T>(v) /= s; }
template<class T> vector3<T> operator/(const vector3<T>& v, const T& s) { return vector3<T>(v) /= s; }

template<class T> vector3<T> operator*(const quaternion& q, const vector3<T>& v)                                  //Rotate vector by quaternion
{
    vector3<float> u = q.fetchScalarComponent();
    vector3<T> temp;                                       //Temporary vector3<T> to return
    float scalar = q.w;                                     //Scalar
    temp =  2.0f * DotProduct(u,v) * u +            
            (scalar*scalar - DotProduct(u,u)) * v +
            2.0f * scalar * CrossProduct(u,v);
    return temp;
}

template<class T> T DotProduct(const vector3<T>& s, const vector3<T>& v) { return s.x * v.x + s.y * v.y + s.z * v.z; };

template<class T> T CrossProduct(const vector3<T>& s, const vector3<T>& v) 
{   
    vector3<T> temp;
    temp.x = s.y * v.z - s.z * v.y;
    temp.y = s.z * v.x - s.x * v.z;
    temp.z = s.x * v.y - s.y * v.x;
    return temp;
};
template<class T> T EuclideanNorm(const vector3<T>&);

//Line template functions, included for post backend functionality.
template<class T> vector3<T> Normal(const vector3<T>&);
template<class T> vector3<T> Perpendicular(const vector3<T>&);
template<class T> bool Intersect(const vector3<T>&, const vector3<T>&, const vector3<T>&, const vector3<T>&);
template<class T> vector3<T> GetIntersect(const vector3<T>&, const vector3<T>&, const vector3<T>&, const vector3<T>&);

}
#endif