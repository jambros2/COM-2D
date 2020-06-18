#include "../include/multi_shape.hpp"
#include "../include/rectangle.hpp"
#include "../include/triangle.hpp"
#include "../include/semi_circle.hpp"
#include "../include/circle.hpp"

namespace shapes {

MultiShape::~MultiShape() {

    unsigned long int i;

    for(i=0; i<all_shapes.size(); i++) {
        delete(all_shapes[i]);
    }

    all_shapes.resize(0);
}

std::array<double, 2> MultiShape::com() {

    unsigned long int i;
    std::array<double, 2> current_com, temp_com;
    double temp_area;
    ShapeType current_shape;
    double combined_area;

    current_com[0] = 0;
    current_com[1] = 0;
    combined_area = 0;

    for(i=0; i<all_shapes.size(); i++) {

        ///Get the com, area, and type for each shape
        temp_com = all_shapes[i]->com();
        temp_area = all_shapes[i]->area();
        current_shape = all_shapes[i]->type();

        ///If the shape is a hole, negate the area
        if (current_shape == ShapeType::Hole)
            temp_area *= -1.0;

        ///Update the total com
        current_com[0] += temp_area*temp_com[0];
        current_com[1] += temp_area*temp_com[1];

        ///Update the combined area
        combined_area += temp_area;
    }

    ///Find the final com
    current_com[0] /= combined_area;
    current_com[1] /= combined_area;

    return current_com;
}

void MultiShape::add_shape(const std::vector<std::string> shape_line) {

    shape *temp_shape;
    ShapeType types[2] = {Hole, Solid};
    std::array<double, 2> pos;

    ///Get the shape position
    pos[0] = strtod(shape_line[2].c_str(), NULL);
    pos[1] = strtod(shape_line[3].c_str(), NULL);

    ///Get the proper parameters for each shape
    if(shape_line[0] == "Rectangle") {
        temp_shape = new rectangle();
        ((rectangle *) temp_shape)->width(strtod(shape_line[4].c_str(), NULL));
        ((rectangle *) temp_shape)->height(strtod(shape_line[5].c_str(), NULL));
    }

    else if (shape_line[0] == "Triangle") {
        temp_shape = new triangle();
        ((triangle *) temp_shape)->base(strtod(shape_line[4].c_str(), NULL));
        ((triangle *) temp_shape)->height(strtod(shape_line[5].c_str(), NULL));
    }

    else if (shape_line[0] == "Circle") {
        temp_shape = new circle();
        ((circle *) temp_shape)->radius(strtod(shape_line[4].c_str(), NULL));
    }

    else {
        temp_shape = new semiCircle();
        ((semiCircle *) temp_shape)->radius(strtod(shape_line[4].c_str(), NULL));
    }

    ///Set the position of the shape
    temp_shape->position(pos);

    ///Get the type of the shape using the array of types
    temp_shape->type(types[atoi(shape_line[1].c_str())]);

    all_shapes.push_back(temp_shape);
}

} //namespace shapes
