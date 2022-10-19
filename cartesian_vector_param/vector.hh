#pragma once

#include <ostream>
#include <initializer_list>
#include <cassert>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector();

    Vector(const value v[]);

    Vector(std::initializer_list<value> l);

    Vector operator-(const Vector &other) const;

    Vector operator+(const Vector &other) const;

    value operator*(const Vector &other) const; 

    Vector operator*(const value rhs) const; 

    Vector &operator+=(const Vector &rhs);

    Vector &operator+=(const value rhs);

    Vector &operator-=(const Vector &rhs);

    Vector &operator-=(const value rhs);

    Vector &operator*=(const Vector &rhs);

    Vector &operator*=(const value &rhs);

    value operator[](size_t i) const;

    value &operator[](size_t i);


private:
// Private Member functions here (if necessary)

// Member variables are ALWAYS private, and they go here
    value c[NDIM];

};

// Nonmember function operators go here
std::ostream &operator<<(std::ostream &os, const Vector &v);
Vector operator+(const value &s, const Vector &v);
Vector operator*(const value &s, const Vector &v);
Vector operator-(const value &s, const Vector &v);
