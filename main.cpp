#include <iostream>
#include "Vector.hpp"

int32_t main() {
    
    Vector vec = {1,1,1};
    vec.normalize();

    std::cout << vec << '\n';
    
    return 0;
}
