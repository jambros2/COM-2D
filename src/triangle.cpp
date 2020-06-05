#include "triangle.hpp"

namespace shapes {

virtual std::array<double, 2> triangle::com() {
    std::array<double, 2> com;
    com[0] = base/3.0 + pos[0];
    com[1] = height/3.0 + pos[1];
    return com;
}

virtual double triangle::area() {
    return base * height / 2.0;
}

void triangle::base(const double & _base) {
    base = _base;
}

const double & triangle::base() {
    return base;
}

void triangle::height(const double & _height) {
    height = _height;
}

const double & triangle::height() {
    return height;
}

} //namespace shapes
