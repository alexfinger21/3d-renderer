#include "Vector3.hpp"
#include <vector>

#ifndef OBJECT_HPP
#define OBJECT_HPP

class Object {
    private:
        std::vector<long long> pts;
    public:
        Vector3 pos{};
        Vector3 normal{};
};

#endif
