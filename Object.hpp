#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vector3.hpp"
#include <vector>

class Object {

    private:
        std::vector<Vector3> pts;
        Vector3 cog();
    public:
        Vector3 pos{};
        Vector3 normal{};
};

#endif
