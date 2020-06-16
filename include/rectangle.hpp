#ifndef RECT_H
#define RECT_H

#include "shape.hpp"

namespace shapes {

/**
 * A base class for rectangles.
 * The rectangle's position is defined by the bottom
 * left corner
 */
class rectangle : public shape {

    private:

        ///The width of the rectangle
        double w;

        ///The height of the rectangle
        double h;

    public:

        virtual std::array<double, 2> com();

        virtual double area();

        /**
         * Sets the width of the rectangle
         * @param _width the new width of the rectangle
         */
        void width(const double & _width);

        /**
         * Gives the current width of the rectangle
         * @return the current width of the rectangle
         */
        const double & width();

        /**
         * Sets the height of the rectangle
         * @param _height the new height of the rectangle
         */
        void height(const double & _height);

        /**
         * Gives the current height of the rectangle
         * @return the current height of the rectangle
         */
        const double & height();
};

} //namespace shapes

#endif //RECT_H
