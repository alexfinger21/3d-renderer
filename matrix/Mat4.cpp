#include "Mat4.hpp"
#include "Vector3.hpp"
#include <cmath>

Mat4::Mat4(Vector3 v) {
   for (int i = 0; i<4; ++i) {
       for (int j = 0; j<4; ++j) {
           this->m[i][j] = (i == j ? 1 : 0);
        }
   }

   this->translation(v); 
}

void Mat4::translation(Vector3 v) {
    m[0][3] = v.x;
    m[1][3] = v.y;
    m[2][3] = v.z;
}

Mat4 Mat4::multiply(Mat4 matrix2) {
    Mat4 result = Mat4(); 

    for (int i = 0; i<4; ++i) {
        for (int j = 0; j<4; ++j) {
            result.m[i][j] = 
                this->m[i][0] * matrix2.m[0][j] + 
                this->m[i][1] * matrix2.m[1][j] + 
                this->m[i][2] * matrix2.m[2][j] + 
                this->m[i][3] * matrix2.m[3][j]; 
        }
    }

    return result;
}

void Mat4::rotation(double angle, char dir) {
    double c = cos(angle);   
    double s = sin(angle);   

    switch(dir) {
        case 'x':
            // x
            m[0][0] = 1;
            m[1][0] = 0;
            m[2][0] = 0;

            // y
            m[0][1] = 0;
            m[1][1] = c;
            m[2][1] = s;

            // z
            m[0][2] = 0;
            m[1][2] = -s;
            m[2][2] = c;
            break;

        case 'y':
            // x
            m[0][0] = c;
            m[1][0] = 0;
            m[2][0] = -s;

            // y
            m[0][1] = 0;
            m[1][1] = 1;
            m[2][1] = 0;

            // z
            m[0][2] = s;
            m[1][2] = 0;
            m[2][2] = c;
            break;
            
        case 'z':
            // x
            m[0][0] = c;
            m[1][0] = s;
            m[2][0] = 0;

            // y
            m[0][1] = -s;
            m[1][1] = c;
            m[2][1] = 0;

            // z
            m[0][2] = 0;
            m[1][2] = 0;
            m[2][2] = 1;
            break;
    }
} 
