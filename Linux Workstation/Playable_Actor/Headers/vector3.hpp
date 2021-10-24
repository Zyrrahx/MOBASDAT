#ifndef VECTOR3_HPP
#define VECTOR3_HPP
#include <cfloat>
#include <climits>
#include <tuple>

namespace LINUX {

template<class T>
    class typeVec3 {
        public:
        T x;
        T y;
        T z;

        typeVec3(): x(T(0)), y(T(0)), z(T(0)) {}
        //typeVec3(float, float, float);
        typeVec3(const T& vx, const T& vy, const T& vz): x(vx), y(vy), z(vz) {}

        typeVec3& operator+=(const typeVec3& v) { x += v.x; y += v.y; z += v.z; return *this;}
        typeVec3& operator-=(const typeVec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this;}
        typeVec3& operator*=(const typeVec3& v) { x *= v.x; y *= v.y; z *= v.z; return *this;}
        typeVec3& operator/=(const typeVec3& v) { x /= v.x; y /= v.y; z /= v.z; return *this;}
        
        friend bool operator ==(const typeVec3& L, const typeVec3& R)   { return std::tie(L.x, L.y, L.z) == std::tie(R.x, R.y, R.z);}
        friend bool operator !=(const typeVec3& L, const typeVec3& R)   { return !(L == R);}

        friend bool operator<(const typeVec3& L, const typeVec3& R)     { return std::tie(L.x, L.y, L.z) < std::tie(R.x, R.y, R.z);}
        friend bool operator<=(const typeVec3& L, const typeVec3& R)    { return !(R < L); }
        friend bool operator>(const typeVec3& L, const typeVec3& R)     { return R < L; }
        friend bool operator>=(const typeVec3& L, const typeVec3& R)    { return !(L < R); }

        typeVec3 operator-() const { return typeVec3(-x,-y,-z); }
        typeVec3& operator*=(const T& s) {x *= s; y *= s; z *= s; return *this;}
        typeVec3& operator/=(const T& s) {x /= s; y /= s; z /= s; return *this;}

    };

typedef typeVec3<float> vector3;
typedef typeVec3<double> hiFiVector3;

template<class T> typeVec3<T> operator+(const typeVec3<T>& L, const typeVec3<T>& R) { return typeVec3<T>(L) += R; }
template<class T> typeVec3<T> operator-(const typeVec3<T>& L, const typeVec3<T>& R) { return typeVec3<T>(L) -= R; }
template<class T> typeVec3<T> operator*(const typeVec3<T>& L, const typeVec3<T>& R) { return typeVec3<T>(L) *= R; }
template<class T> typeVec3<T> operator/(const typeVec3<T>& L, const typeVec3<T>& R) { return typeVec3<T>(L) /= R; }

template<class T> typeVec3<T> operator*(const T& s, const typeVec3<T>& v) { return typeVec3<T>(v) *= s; }
template<class T> typeVec3<T> operator*(const typeVec3<T>& v, const T& s) { return typeVec3<T>(v) *= s; }
template<class T> typeVec3<T> operator/(const T& s, const typeVec3<T>& v) { return typeVec3<T>(v) /= s; }
template<class T> typeVec3<T> operator/(const typeVec3<T>& v, const T& s) { return typeVec3<T>(v) /= s; }

template<class T> T DotProduct(const typeVec3<T>& s, const typeVec3<T>& v) { return s.x * v.x + s.y * v.y + s.z * v.z; };

template<class T> T CrossProduct(const typeVec3<T>& s, const typeVec3<T>& v) 
{   
    typeVec3<T> temp;
    temp.x = s.y * v.z - s.z * v.y;
    temp.y = s.z * v.x - s.x * v.z;
    temp.z = s.x * v.y - s.y * v.x;
    return temp;
};
template<class T> T EuclideanNorm(const typeVec3<T>&);

//Line template functions, included for post backend functionality.
template<class T> typeVec3<T> Normal(const typeVec3<T>&);
template<class T> typeVec3<T> Perpendicular(const typeVec3<T>&);
template<class T> bool Intersect(const typeVec3<T>&, const typeVec3<T>&, const typeVec3<T>&, const typeVec3<T>&);
template<class T> typeVec3<T> GetIntersect(const typeVec3<T>&, const typeVec3<T>&, const typeVec3<T>&, const typeVec3<T>&);

}
#endif