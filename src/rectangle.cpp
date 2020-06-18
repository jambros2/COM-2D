//Author: Jonathan Ambrose
//Date:   6-18-2020


#include "../include/rectangle.hpp"

namespace shapes {

std::array<double, 2> rectangle::com() {
    std::array<double, 2> com;
    com[0] = w/2.0 + pos[0];
    com[1] = h/2.0 + pos[1];
    return com;
}

double rectangle::area() {
    return w*h;
}

void rectangle::width(const double & _width) {
    w = _width;
}

const double & rectangle::width() {
    return w;
}

void rectangle::height(const double & _height) {
    h = _height;
}

const double & rectangle::height() {
    return h;
}

} //namespace shapes
