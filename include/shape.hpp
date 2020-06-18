//Author: Jonathan Ambrose
//Date:   6-18-2020


#ifndef SHAPE_H
#define SHAPE_H

#include <memory>

namespace shapes {

/**
 * An enumeration representing whether a given shape is a hole or a solid as
 * a part of the system
 */
enum ShapeType {
    Hole,
    Solid
};

/**
 * A base class to define the commonalities between shapes that will be part
 * of the system
 */
class shape {

    protected:

        ///The position of the shape
        std::array<double, 2> pos;

        ///The way in which this shape is a part of the system (hole or solid)
        ShapeType t;

    public:

        virtual ~shape();

        /**
         * Sets the position of the shape
         * @param _pos the new position of the shape
         */
        void position(const std::array<double, 2> & _pos);

        /**
         * Gives the current position of the shape
         * @return the current position of the shape
         */
        const std::array<double, 2> & position();

        /**
         * Sets the type of the shape
         * @param _type the new type of the shape
         */
        void type(const ShapeType & _type);

        /**
         * Gives the current type of the shape
         * @return the current type of the shape
         */
        const ShapeType & type();

        /**
         * The function computes the center of mass of the 2D-shape
         * @return the position of the center of mass relative to the
         * coordinate system
         */
        virtual std::array<double, 2> com();

        /**
         * This function computes the area of the 2D-shape
         * @return the area of the 2D-shape
         */
        virtual double area();
};

} //namespace shapes

#endif //SHAPE_H
