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

        void position(const std::array<double, 2> & _pos);

        const std::array<double, 2> & position();

        void type(const ShapeType & _type);

        const ShapeType & type();

        virtual std::array<double, 2> com();

        virtual double area();

        virtual void radius(const double & _radius);

        virtual const double & radius();
};

} //namespace shapes

#endif //SEMICIRC_H
