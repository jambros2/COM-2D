//Author: Jonathan Ambrose
//Date:   6-18-2020


#ifndef SEMICIRC_H
#define SEMICIRC_H

#include "shape.hpp"
#include "circle.hpp"

namespace shapes {

/**
 * A base class for semi-circles
 * A semi-circle's position is defined by the point in the middle of diameter
 */
class semiCircle : public circle {

    public:

        virtual std::array<double, 2> com();

        virtual double area();

};

} //namespace shapes

#endif //SEMICIRC_H
