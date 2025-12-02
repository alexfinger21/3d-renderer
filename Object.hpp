#include "Vector.h"
#include <vector>

#ifndef OBJECT_H
#define OBJECT_H

class Object {
    private:
        std::vector<long long> pts;
    public:
        Vector pos{};
        Vector normal{};
};

#endif
