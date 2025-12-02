#include <iostream>

#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
    double x{}, y{}, z{}; 

    void normalize();
};

std::ostream& operator<<(std::ostream& os, const Vector& v);

#endif
