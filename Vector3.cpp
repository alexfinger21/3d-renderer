#include "Vector3.hpp"
#include <cmath>
#include <iostream>

double Vector3::magnitude() {
    return std::sqrt(x*x + y*y + z*z);
}

void Vector3::normalize() {
    double magn = magnitude();

    if (magn == 0.0) {
        return;
    }

    x = x/magn;
    y = y/magn;
    z = z/magn;
}

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    return os << '<' << v.x << ", " << v.y << ", " << v.z << '>';
}
