//Author: Jonathan Ambrose
//Date:   6-18-2020


#ifndef CIRC_H
#define CIRC_H

#include "shape.hpp"

namespace shapes {

/**
 * A base class for circles
 * A circle's position is defined by its center point
 */
class circle : public shape {

    protected:

        ///The radius of the circle
        double r;

    public:

        virtual std::array<double, 2> com();

        virtual double area();

        /**
         * Sets the radius of the circle
         * @param _radius the new radius of the circle
         */
        void radius(const double & _radius);

        /**
         * Gives the current radius of the circle
         * @return the current radius of the circle
         */
        const double & radius();
};

} //namespace shapes

#endif //CIRC_H
