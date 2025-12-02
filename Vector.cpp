#include "Vector.hpp"
#include <cmath>
#include <iostream>

void Vector::normalize() {
    double magn = std::sqrt(x*x + y*y + z*z);

    if (magn == 0.0) {
        return;
    }

    x = x/magn;
    y = y/magn;
    z = z/magn;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    return os << '<' << v.x << ", " << v.y << ", " << v.z << '>';
}
