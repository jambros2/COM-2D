#include <cstdio>
#include <memory>
#include "../include/shape.hpp"
#include "../include/multi_shape.hpp"
#include "../include/parser.hpp"
#include "../include/triangle.hpp"
#include "../include/rectangle.hpp"
#include "../include/semi_circle.hpp"
#include "../include/circle.hpp"

int main() {
    shapes::shapeParser p;
    shapes::MultiShape *s;
    std::array<double, 2> center;

    s = p.parse_input("test_cases/shape.csv");

    center = s->com();

    printf("The center of mass is (%.4lf, %.4lf).\n", center[0], center[1]);
    return 0;
}
