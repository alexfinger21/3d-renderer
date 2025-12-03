#include "Object.hpp"
#include "Vector3.hpp"

Vector3 Object::cog() {
    double x = 0;
    double y = 0;
    double z = 0;

    for (Vector3 pt : pts) {
        x += pt.x;
        y += pt.y;
        z += pt.z;
    }

    return Vector3{x/pts.size(), y/pts.size(), z/pts.size()};
}
