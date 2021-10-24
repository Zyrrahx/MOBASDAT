#ifndef VECTOR2_HPP
#define VECTOR2_HPP
#include <cfloat>
#include <climits>

namespace LINUX {

template<class T>
    class typeVec2 {
        public:
        T x;
        T y;

        typeVec2(): x(T(0)), y(T(0)) {}
        typeVec2(const& T vx, const& T vy): x(vx), y(vy) {}

        typeVec2& operator+=(const typeVec2& v) { x += v.x; y += v.y; return *this;}
        typeVec2& operator-=(const typeVec2& v) { x -= v.x; y -= v.y; return *this;}
        typeVec2& operator*=(const typeVec2& v) { x *= v.x; y *= v.y; return *this;}
        typeVec2& operator/=(const typeVec2& v) { x /= v.x; y /= v.y; return *this;}
        
        friend bool operator ==(const typeVec2& L, const typeVec2& R)   { return std::tie(L.x, L.y) == std::tie(R.x, R.y);}
        friend bool operator !=(const vector2d& L, const typeVec2& R)   { return !(L == R);}

        friend bool operator<(const typeVec2& L, const typeVec2& R)     { return std::tie(L.x, L.y) < std::tie(R.x, R.y);}
        friend bool operator<=(const typeVec2& L, const typeVec2& R)    { return !(R < L); }
        friend bool operator>(const typeVec2& L, const typeVec2& R)     { return R < L; }
        friend bool operator>=(const typeVec2& L, const typeVec2& R)    { return !(L < R); }

        typeVec2 operator-() const { return typeVec2(-x,-y); }
        typeVec2& operator*=(const& T s) {x *= s; y *= s; return *this;}
        typeVec2& operator/=(const& T s) {x /= s; y /= s; return *this;}
    };

typedef typeVec2<float> vector2;
typedef typeVec2<double> hiFiVector2;

template<class T> typeVec2<T> operator+(const typeVec2<T>& L, const typeVec2<T>& R) { return typeVec2<T>(L) += R; }
template<class T> typeVec2<T> operator-(const typeVec2<T>& L, const typeVec2<T>& R) { return typeVec2<T>(L) -= R; }
template<class T> typeVec2<T> operator*(const typeVec2<T>& L, const typeVec2<T>& R) { return typeVec2<T>(L) *= R; }
template<class T> typeVec2<T> operator/(const typeVec2<T>& L, const typeVec2<T>& R) { return typeVec2<T>(L) /= R; }

template<class T> typeVec2<T> operator*(const T& s, const typeVec2<T>& v) { return typeVec2<T>(v) *= s; }
template<class T> typeVec2<T> operator*(const typeVec2<T>& v, const T& s) { return typeVec2<T>(v) *= s; }
template<class T> typeVec2<T> operator/(const T& s, const typeVec2<T>& v) { return typeVec2<T>(v) /= s; }
template<class T> typeVec2<T> operator/(const typeVec2<T>& v, const T& s) { return typeVec2<T>(v) /= s; }

template<class T> T DotProduct(const typeVec2<T>& s, const typeVec2<T>& v) { return s.x * v.x + s.y * v.y};
template<class T> T EuclideanNorm(const typeVec2<T>&);

//Line template functions, included for post backend functionality.
template<class T> typeVec2<T> Normal(const typeVec2<T>&);
template<class T> typeVec2<T> Perpendicular(const typeVec2<T>&);
template<class T> bool Intersect(const typeVec2<T>&, const typeVec2<T>&, const typeVec2<T>&, const typeVec2<T>&);
template<class T> typeVec2<T> GetIntersect(const typeVec2<T>&, const typeVec2<T>&, const typeVec2<T>&, const typeVec2<T>&);

}
#endif