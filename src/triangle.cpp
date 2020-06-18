//Author: Jonathan Ambrose
//Date:   6-18-2020


#include "../include/triangle.hpp"

namespace shapes {

std::array<double, 2> triangle::com() {
    std::array<double, 2> com;
    com[0] = b/3.0 + pos[0];
    com[1] = h/3.0 + pos[1];
    return com;
}

double triangle::area() {
    return b * h / 2.0;
}

void triangle::base(const double & _base) {
    b = _base;
}

const double & triangle::base() {
    return b;
}

void triangle::height(const double & _height) {
    h = _height;
}

const double & triangle::height() {
    return h;
}

} //namespace shapes
