#include "../include/semi_circle.h"
#include <math.h>

namespace shapes {

std::array<double, 2> semiCircle::com() {
    return pos;
}

double semiCircle::area() {
    return M_PI/2.0 * radius * radius;
}

} //namespace shapes
