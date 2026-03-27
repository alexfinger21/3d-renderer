#ifndef MAT4_HPP
#define MAT4_HPP

#include "Vector3.hpp"

struct Mat4 {
    double m[4][4];

    Mat4(): Mat4(Vector3{0, 0, 0}) {};
    Mat4(Vector3 v);

    void translation(Vector3 trans);
    void rotation(double angle, char dir);

    private:
        Mat4 multiply(Mat4 m);
};

#endif

