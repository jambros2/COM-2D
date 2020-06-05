#ifndef SEMICIRC_H
#define SEMICIRC_H

#include "shape.h"

namespace shapes {

/**
 * A base class for semi-circles
 * A semi-circle's position is defined by the point in the middle of diameter
 */
class semiCircle : circle {

    public:

        virtual std::array<double, 2> com();

        virtual double area();

};

} //namespace shapes

#endif //SEMICIRC_H
