#include "../include/semi_circle.hpp"
#include <math.h>

namespace shapes {

std::array<double, 2> semiCircle::com() {
    return pos;
}

double semiCircle::area() {
    return M_PI/2.0 * r * r;
}

} //namespace shapes
