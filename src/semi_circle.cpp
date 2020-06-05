#include "semi_circle.h"

namespace shapes {

virtual std::array<double, 2> semiCircle::com() {
    return pos;
}

virtual double semiCircle::area() {
    return M_PI/2.0 * radius * radius;
}

} //namespace shapes
