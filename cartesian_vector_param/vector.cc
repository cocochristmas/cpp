#include "vector.hh"

Vector::Vector(){
    for (size_t i = 0; i < NDIM; i++)
        c[i] = 0;
}

Vector::Vector(const value v[]){
    for (size_t i = 0; i < NDIM; ++i)
        c[i] = v[i];
}

Vector::Vector(std::initializer_list<value> l){
    assert(l.size() == NDIM);
    std::copy(l.begin(), l.end(), c);
}

Vector Vector::operator+(const Vector &other) const{
    Vector v = Vector{};
    for (size_t i = 0; i < NDIM; ++i)
        v.c[i] = c[i] + other.c[i];
    return v;
}

// Dot product
value Vector::operator*(const Vector &other) const{
    value sum = 0;
    for (size_t i = 0; i < NDIM; ++i)
        sum += c[i] * other.c[i];

    return sum;
}

// Product with a scalar
Vector Vector::operator*(const value rhs) const{
    Vector v = Vector{};
    for (size_t i = 0; i < NDIM; ++i)
        v.c[i] = c[i] * rhs;
    return v;
}

Vector Vector::operator-(const Vector &other) const{
    Vector v = Vector{};
    for (size_t i = 0; i < NDIM; ++i)
        v.c[i] = c[i] - other.c[i];
    return v;
}

// Public Member functions here
Vector &Vector::operator+=(const Vector &rhs){
    for (size_t i = 0; i < NDIM; ++i)
        c[i] += rhs.c[i];

    return *this;
}

Vector &Vector::operator+=(const value rhs){
    for (size_t i = 0; i < NDIM; ++i)
        c[i] += rhs;

    return *this;
}

Vector &Vector::operator-=(const Vector &rhs){
    for (size_t i = 0; i < NDIM; ++i)
        c[i] -= rhs.c[i];

    return *this;
}

Vector &Vector::operator*=(const Vector &rhs){
    for (size_t i = 0; i < NDIM; ++i)
        c[i] *= rhs.c[i];

    return *this;
}

Vector &Vector::operator*=(const value &rhs){
    for (size_t i = 0; i < NDIM; ++i)
        c[i] *= rhs;

    return *this;
}

value &Vector::operator[](size_t i){
    assert(i < NDIM);
    return c[i];
}

value Vector::operator[](size_t i) const{
    assert(i < NDIM);
    return c[i];
}

// Not vector operators
std::ostream &operator<<(std::ostream &os, const Vector &v){
    os << "{";
    for (size_t i = 0; i < NDIM; ++i){
        os << v[i];
        if (i != NDIM - 1)
            os << ",";
    }
    os << "}";
    return os;
}

Vector operator*(const value &s, const Vector &v){
    value l[NDIM];
    for (size_t i = 0; i < NDIM; ++i)
        l[i] = v[i] * s;

    return Vector(l);
}

Vector operator+(const value &s, const Vector &v){
    value l[NDIM];
    for (size_t i = 0; i < NDIM; ++i)
        l[i] = v[i] + s;

    return Vector(l);
}

Vector operator-(const value &s, const Vector &v){
    value l[NDIM];
    for (size_t i = 0; i < NDIM; ++i)
        l[i] = v[i] - s;

    return Vector(l);
}
