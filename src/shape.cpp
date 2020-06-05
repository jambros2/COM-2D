#include "shapes.hpp"

namespace shapes {

void shape::position(const std::array<double, 2> & _pos) {
    pos = _pos;
}

const std::array<double, 2> & shape::position() {
    return pos;
}

void shape::type(const ShapeType & _type) {
    type = _type;

const ShapeType & shape::type() {
    return type;
}

virtual std::array<double, 2> shape::com() {
    return pos;
}

virtual double shape::area() {
    return 0.0;
}

} //namespace shapes

#endif //SHAPE_H
