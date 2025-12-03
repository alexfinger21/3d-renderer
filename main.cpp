#include <iostream>
#include <memory>
#include "Vector3.hpp"

int32_t main() {
    
    std::unique_ptr<Vector3> vec(new Vector3{.x=0, .y=65, .z=0});
    vec->normalize();

    std::cout << *vec << '\n';
    
    return 0;
}
