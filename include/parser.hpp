#ifndef PARSER_H
#define PARSER_H

#include "multi_shape.hpp"

namespace shapes {


/**
 * A class for parsing the input of shape files to define
 * a multi-shape
 */
class shapeParser {

    public:

    /**
     * A function to parse the input of a shape file and
     * construct a multi-shape
     * @param inputFile a string for the path to the input file
     * @return a multi-shape defined by the input file
     */
    MultiShape *parse_input(const std::string &inputFile);

};

} //namespace shapes

#endif //PARSER_H
