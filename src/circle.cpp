#include "../include/circle.hpp"
#include <math.h>

namespace shapes {

std::array<double, 2> circle::com() {
    return pos;
}

double circle::area() {
    return M_PI*r*r;
}

void circle::radius(const double & _radius) {
    r = _radius;
}

const double & circle::radius() {
    return r;
}

} //namespace shapes
