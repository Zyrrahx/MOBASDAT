#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP
#include <cfloat>
#include <climits>

namespace LINUX {

template<class T>
    class Vector2d {
        public:
        T x;
        T y;

        Vector2d(): x(T(0)), y(T(0)) {}
        Vector2d(const& T vx, const& T vy): x(vx), x(vy) {}

        Vector2d& operator+=(const Vector2d& v) { x += v.x; y += v.y; return *this;}
        Vector2d& operator-=(const Vector2d& v) { x -= v.x; y -= v.y; return *this;}
        Vector2d& operator*=(const Vector2d& v) { x *= v.x; y *= v.y; return *this;}
        Vector2d& operator/=(const Vector2d& v) { x /= v.x; y /= v.y; return *this;}
        
        friend bool operator ==(const Vector2d& L, const Vector2d& R)   { return std::tie(L.x, L.y) == std::tie(R.x, R.y);}
        friend bool operator !=(const Vecotr2d& L, const Vector2d& R)   { return !(L == R);}

        friend bool operator<(const Vector2d& L, const Vector2d& R)     { return std::tie(L.x, L.y) < std::tie(R.x, R.y);}
        friend bool operator<=(const Vector2d& L, const Vector2d& R)    { return !(R < L); }
        friend bool operator>(const Vector2d& L, const Vector2d& R)     { return R < L; }
        friend bool operator>=(const Vector2d& L, const Vector2d& R)    { return !(L < R); }

        Vector2d operator-() const { return Vector2d(-x,-y); }
        Vector2d& operator*=(const& T s) {x *= s; y *= s; return *this;}
        Vector2d& operator/=(const& T s) {x /= s; y /= s; return *this;}
    };

template<class T> Vector2d<T> operator+(const Vector2d<T>& L, const Vector2d<T>& R) { return Vector2d<T>(L) += R; }
template<class T> Vector2d<T> operator-(const Vector2d<T>& L, const Vector2d<T>& R) { return Vector2d<T>(L) -= R; }
template<class T> Vector2d<T> operator*(const Vector2d<T>& L, const Vector2d<T>& R) { return Vector2d<T>(L) *= R; }
template<class T> Vector2d<T> operator/(const Vector2d<T>& L, const Vector2d<T>& R) { return Vector2d<T>(L) /= R; }

template<class T> Vector2d<T> operator*(const T& s, const Vector2d<T>& v) { return Vector2d<T>(v) *= s; }
template<class T> Vector2d<T> operator*(const Vector2d<T>& v, const T& s) { return Vector2d<T>(v) *= s; }
template<class T> Vector2d<T> operator/(const T& s, const Vector2d<T>& v) { return Vector2d<T>(v) /= s; }
template<class T> Vector2d<T> operator/(const Vector2d<T>& v, const T& s) { return Vector2d<T>(v) /= s; }

template<class T> T DotProduct(const Vector2d<T>&, const Vector2d<T>&);
template<class T> T CrossProduct(const Vector2d<T>&, const Vector2d<T>&);
template<class T> T EuclideanNorm(const Vector2d<T>&);

//Line template functions, included for post backend functionality.
template<class T> Vector2d<T> Normal(const Vector2d<T>&);
template<class T> Vector2d<T> Perpendicular(const Vector2d<T>&);
template<class T> bool Intersect(const Vector2d<T>&, const Vector2d<T>&, const Vector2d<T>&, const Vector2d<T>&);
template<class T> Vector2d<T> GetIntersect(const Vector2d<T>&, const Vector2d<T>&, const Vector2d<T>&, const Vector2d<T>&);

}
#endif