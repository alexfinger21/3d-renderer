#include <iostream>

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

struct Vector3 {
    double x{}, y{}, z{}; 

    double magnitude();
    void normalize();
};

std::ostream& operator<<(std::ostream& os, const Vector3& v);

#endif
