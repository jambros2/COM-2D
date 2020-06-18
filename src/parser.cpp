//Author: Jonathan Ambrose
//Date:   6-18-2020


#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include "../include/parser.hpp"

namespace shapes {

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

            ///Get lines from the file
            while(std::getline(file, line)) {
                stream.clear();
                stream.str(line.c_str());
                words.clear();

                ///Create a list of words from the line of CSV
                while(std::getline(stream, word, ',')) {
                    words.push_back(word);
                }

                ///Add the shape to the multi-shape given the word list
                the_shape->add_shape(words);
            }
        }
        else {
            fprintf(stderr, "File could not be opened. Please check current working directory\n");
            exit(1);
        }

        return the_shape;
    }

} //namespace shapes
