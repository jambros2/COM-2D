#ifndef MULTISHAPE_H
#define MULTISHAPE_H

#include <memory>
#include <vector>
#include <string>
#include "shape.hpp"

namespace shapes {

/**
 * A class to define a group of shapes composing the system
 */
class MultiShape {

    protected:

        ///The position of the shape
        std::vector<shape*> all_shapes;

    public:

        /**
         * The function computes the center of mass of the combined 2D-shapes
         * @return the position of the center of mass relative to the
         * coordinate system
         */
        std::array<double, 2> com();

        /**
         * The function adds a shape to the internal vector of shapes given a
         * string representing a line of input.
         * @param shape_line a vector of strings representing a given shape and
         * its dimensions
         */
        void add_shape(const std::vector<std::string> shape_line);
};

} //namespace shapes

#endif //MULTISHAPE_H
