#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include "../include/parser.hpp"

namespace shapes {

    /**
     * A function to parse the input of a shape file and
     * construct a multi-shape
     * @param inputFile a string for the path to the input file
     * @return a multi-shape defined by the input file
     */
    MultiShape *shapeParser::parse_input(const std::string &inputFile) {

        std::string line;
        std::string word;
        std::vector<std::string> words;
        std::ifstream file;
        std::stringstream stream;
        MultiShape *the_shape;

        the_shape = new MultiShape();

        file.open(inputFile.c_str());

        if(file.is_open()) {
            while(std::getline(file, line)) {
                stream.clear();
                stream.str(line.c_str());
                words.clear();
                while(std::getline(stream, word, ',')) {
                    words.push_back(word);
                }
                the_shape->add_shape(words);
            }
        }
        else {
            printf("File could not be opened. Please check current working directory\n");
            exit(1);
        }

        return the_shape;
    }

} //namespace shapes
