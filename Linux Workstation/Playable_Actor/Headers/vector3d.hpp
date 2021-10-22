#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
#include <cfloat>
#include <climits>

namespace LINUX {

template<class T>
    class Vector3d {
        public:
        T x;
        T y;
        T z;

        Vector3d(): x(T(0)), y(T(0)), z(T(0)) {}
        Vector3d(const& T vx, const& T vy, const& T vz): x(vx), x(vy), x(vz) {}

        Vector3d& operator+=(const Vector3d& v) { x += v.x; y += v.y; z += v.z; return *this;}
        Vector3d& operator-=(const Vector3d& v) { x -= v.x; y -= v.y; z -= v.z; return *this;}
        Vector3d& operator*=(const Vector3d& v) { x *= v.x; y *= v.y; z *= v.z; return *this;}
        Vector3d& operator/=(const Vector3d& v) { x /= v.x; y /= v.y; z /= v.z; return *this;}
        
        friend bool operator ==(const Vector3d& L, const Vector3d& R)   { return std::tie(L.x, L.y, L.z) == std::tie(R.x, R.y, R.z);}
        friend bool operator !=(const Vecotr3d& L, const Vector3d& R)   { return !(L == R);}

        friend bool operator<(const Vector3d& L, const Vector3d& R)     { return std::tie(L.x, L.y, L.z) < std::tie(R.x, R.y, R.z);}
        friend bool operator<=(const Vector3d& L, const Vector3d& R)    { return !(R < L); }
        friend bool operator>(const Vector3d& L, const Vector3d& R)     { return R < L; }
        friend bool operator>=(const Vector3d& L, const Vector3d& R)    { return !(L < R); }

        Vector3d operator-() const { return Vector3d(-x,-y,-z); }
        Vector3d& operator*=(const& T s) {x *= s; y *= s; z *= s; return *this;}
        Vector3d& operator/=(const& T s) {x /= s; y /= s; z /= s; return *this;}

        //Rotate vector by quaternion
        Vector3d operator*(const Quaternion& q, const Vector3d& v)
        {
            Vector3d u(q.x, q.y, q.z);
            Vector3d temp;

            float scalar = q.w; 

            temp =  2.0f * DotProduct(u,v) * u +
                    (scalar*scalar - DotProduct(u,u)) * v +
                    2.0f * scalar * CrossProduct(u,v);

        }

    };

template<class T> Vector3d<T> operator+(const Vector3d<T>& L, const Vector3d<T>& R) { return Vector3d<T>(L) += R; }
template<class T> Vector3d<T> operator-(const Vector3d<T>& L, const Vector3d<T>& R) { return Vector3d<T>(L) -= R; }
template<class T> Vector3d<T> operator*(const Vector3d<T>& L, const Vector3d<T>& R) { return Vector3d<T>(L) *= R; }
template<class T> Vector3d<T> operator/(const Vector3d<T>& L, const Vector3d<T>& R) { return Vector3d<T>(L) /= R; }

template<class T> Vector3d<T> operator*(const T& s, const Vector3d<T>& v) { return Vector3d<T>(v) *= s; }
template<class T> Vector3d<T> operator*(const Vector3d<T>& v, const T& s) { return Vector3d<T>(v) *= s; }
template<class T> Vector3d<T> operator/(const T& s, const Vector3d<T>& v) { return Vector3d<T>(v) /= s; }
template<class T> Vector3d<T> operator/(const Vector3d<T>& v, const T& s) { return Vector3d<T>(v) /= s; }

template<class T> T DotProduct(const Vector3d<T>& s, const Vector3d<T>& v) { return s.x * v.x + s.y * v.y + s.z * v.z; };
template<class T> T CrossProduct(const Vector3d<T>& s, const Vector3d<T>& v) 
{   
    Vector3d<T> temp;
    temp.x = s.y * v.z - s.z * v.y;
    temp.y = s.z * v.x - s.x * v.z;
    temp.z = s.x * v.y - s.y * v.x;
    return temp;
};
template<class T> T EuclideanNorm(const Vector3d<T>&);

//Line template functions, included for post backend functionality.
template<class T> Vector3d<T> Normal(const Vector3d<T>&);
template<class T> Vector3d<T> Perpendicular(const Vector3d<T>&);
template<class T> bool Intersect(const Vector3d<T>&, const Vector3d<T>&, const Vector3d<T>&, const Vector3d<T>&);
template<class T> Vector3d<T> GetIntersect(const Vector3d<T>&, const Vector3d<T>&, const Vector3d<T>&, const Vector3d<T>&);

}
#endif