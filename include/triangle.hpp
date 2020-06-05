#ifndef TRI_H
#define TRI_H

#include "shape.h"

namespace shapes {

/**
 * A base class for right triangles oriented with the
 * right angle in the bottom left corner. The position
 * is defined by the vertex at the right angle
 */
class triangle : shape {

    private:

        ///The base of the triangle
        double base;

        ///The height of the triangle
        double height;

    public:

        virtual std::array<double, 2> com();

        virtual double area();

        /**
         * Sets the base of the triangle
         * @param _base the new base of the triangle
         */
        void base(const double & _base);

        /**
         * Gives the current base of the triangle
         * @return the current base of the triangle
         */
        const double & base();

        /**
         * Sets the height of the triangle
         * @param _height the new height of the triangle
         */
        void height(const double & _height);

        /**
         * Gives the current height of the triangle
         * @return the current height of the triangle
         */
        const double & height();
};

} //namespace shapes

#endif //TRI_H
