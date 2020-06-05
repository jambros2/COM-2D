#include "rectangle.hpp"

namespace shapes {

virtual std::array<double, 2> rectangle::com() {
    std::array<double, 2> com;
    com[0] = width/2.0 + pos[0];
    com[1] = height/2.0 + pos[1];
    return com;
}

virtual double rectangle::area() {
    return width*height;
}

void rectangle::width(const double & _width) {
    width = _width;
}

const double & rectangle::width() {
    return width;
}

void rectangle::height(const double & _height) {
    height = _height;
}

const double & rectangle::height() {
    return height;
}

} //namespace shapes
