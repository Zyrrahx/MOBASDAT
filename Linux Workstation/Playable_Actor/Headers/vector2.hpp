#ifndef VECTOR2_HPP
#define VECTOR2_HPP
#include <cfloat>
#include <climits>

namespace LINUX {

template<class T>
    class vector2 {
        public:
        T x;
        T y;

        vector2(): x(T(0)), y(T(0)) {}
        vector2(const& T vx, const& T vy): x(vx), x(vy) {}

        vector2& operator+=(const vector2& v) { x += v.x; y += v.y; return *this;}
        vector2& operator-=(const vector2& v) { x -= v.x; y -= v.y; return *this;}
        vector2& operator*=(const vector2& v) { x *= v.x; y *= v.y; return *this;}
        vector2& operator/=(const vector2& v) { x /= v.x; y /= v.y; return *this;}
        
        friend bool operator ==(const vector2& L, const vector2& R)   { return std::tie(L.x, L.y) == std::tie(R.x, R.y);}
        friend bool operator !=(const Vecotr2d& L, const vector2& R)   { return !(L == R);}

        friend bool operator<(const vector2& L, const vector2& R)     { return std::tie(L.x, L.y) < std::tie(R.x, R.y);}
        friend bool operator<=(const vector2& L, const vector2& R)    { return !(R < L); }
        friend bool operator>(const vector2& L, const vector2& R)     { return R < L; }
        friend bool operator>=(const vector2& L, const vector2& R)    { return !(L < R); }

        vector2 operator-() const { return vector2(-x,-y); }
        vector2& operator*=(const& T s) {x *= s; y *= s; return *this;}
        vector2& operator/=(const& T s) {x /= s; y /= s; return *this;}
    };

template<class T> vector2<T> operator+(const vector2<T>& L, const vector2<T>& R) { return vector2<T>(L) += R; }
template<class T> vector2<T> operator-(const vector2<T>& L, const vector2<T>& R) { return vector2<T>(L) -= R; }
template<class T> vector2<T> operator*(const vector2<T>& L, const vector2<T>& R) { return vector2<T>(L) *= R; }
template<class T> vector2<T> operator/(const vector2<T>& L, const vector2<T>& R) { return vector2<T>(L) /= R; }

template<class T> vector2<T> operator*(const T& s, const vector2<T>& v) { return vector2<T>(v) *= s; }
template<class T> vector2<T> operator*(const vector2<T>& v, const T& s) { return vector2<T>(v) *= s; }
template<class T> vector2<T> operator/(const T& s, const vector2<T>& v) { return vector2<T>(v) /= s; }
template<class T> vector2<T> operator/(const vector2<T>& v, const T& s) { return vector2<T>(v) /= s; }

template<class T> T DotProduct(const vector2<T>& s, const vector2<T>& v) { return s.x * v.x + s.y * v.y};
template<class T> T EuclideanNorm(const vector2<T>&);

//Line template functions, included for post backend functionality.
template<class T> vector2<T> Normal(const vector2<T>&);
template<class T> vector2<T> Perpendicular(const vector2<T>&);
template<class T> bool Intersect(const vector2<T>&, const vector2<T>&, const vector2<T>&, const vector2<T>&);
template<class T> vector2<T> GetIntersect(const vector2<T>&, const vector2<T>&, const vector2<T>&, const vector2<T>&);

}
#endif