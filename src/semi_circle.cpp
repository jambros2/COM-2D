#include "../include/semi_circle.hpp"
#include <math.h>

namespace shapes {

std::array<double, 2> semiCircle::com() {
    std::array<double, 2> center;
    center[0] = pos[0];
    center[1] = pos[1] + 4.0*r/(3.0*M_PI);
    return center;
}

double semiCircle::area() {
    return M_PI/2.0 * r * r;
}

} //namespace shapes
