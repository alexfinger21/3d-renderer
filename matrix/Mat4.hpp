#ifndef MAT4_HPP
#define MAT4_HPP

#include "Vector3.hpp"

struct Mat4 {
    double m[4][4];

    Mat4(): Mat4(Vector3{0, 0, 0}) {};
    Mat4(const Vector3& v);

    void translation(const Vector3& trans);
    void rotation(double angle, char dir);
    void updateVector(Vector3& pos);

    private:
        Mat4 multiply(Mat4 m);
};

std::ostream& operator<<(std::ostream& os, const Mat4& m);

#endif

