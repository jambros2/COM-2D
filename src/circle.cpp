#include "circle.hpp"
#include <math>

namespace shapes {

virtual std::array<double, 2> circle::com() {
    return pos;
}

virtual double circle::area() {
    return M_PI*radius*radius;
}

void circle::radius(const double & _radius) {
    radius = _radius;
}

const double & circle::radius() {
    return radius;
}

} //namespace shapes
