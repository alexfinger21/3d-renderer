#include <iostream>
#include <memory>
#include "Vector3.hpp"
#include "Object.hpp"

int32_t main() {
    
    std::unique_ptr<Vector3> vec(new Vector3{.x=0, .y=65, .z=0});
    vec->normalize();
    
    std::unique_ptr<Object> obj = std::make_unique<Object>(); 
    
    return 0;
}
