//Author: Jonathan Ambrose
//Date:   6-18-2020


#include "../include/shape.hpp"

namespace shapes {

shape::~shape() {}

void shape::position(const std::array<double, 2> & _pos) {
    pos = _pos;
}

const std::array<double, 2> & shape::position() {
    return pos;
}

void shape::type(const ShapeType & _type) {
    t = _type;
}

const ShapeType & shape::type() {
    return t;
}

std::array<double, 2> shape::com() {
    return pos;
}

double shape::area() {
    return 0.0;
}

} //namespace shapes
