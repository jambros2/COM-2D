#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE shapes

#if defined __GNUC__ && __GNUC__>=6
  #pragma GCC diagnostic ignored "-Wwrite-strings"
#endif

#include <boost/test/included/unit_test.hpp>
#include <memory>
#include <fstream>
#include <math.h>
#include <string>
#include <random>
#include "../include/multi_shape.hpp"
#include "../include/parser.hpp"
#include "../include/shape.hpp"
#include "../include/rectangle.hpp"
#include "../include/triangle.hpp"
#include "../include/circle.hpp"
#include "../include/semi_circle.hpp"


using namespace std;
using namespace shapes;

shape * create_shape(const string &name, const ShapeType &t, const std::array<double, 2> &p, const double &param1, const double &param2) {

    shape *temp_shape;

    ///Get the proper parameters for each shape
    if(name == "Rectangle") {
        temp_shape = new rectangle();
        ((rectangle *) temp_shape)->width(param1);
        ((rectangle *) temp_shape)->height(param2);
    }

    else if (name == "Triangle") {
        temp_shape = new triangle();
        ((triangle *) temp_shape)->base(param1);
        ((triangle *) temp_shape)->height(param2);
    }

    else if (name == "Circle") {
        temp_shape = new circle();
        ((circle *) temp_shape)->radius(param1);
    }

    else if (name == "SemiCircle") {
        temp_shape = new semiCircle();
        ((semiCircle *) temp_shape)->radius(param1);
    }
    else {
        fprintf(stderr, "Unrecognized shape %s\n", name.c_str());
        return NULL;
    }

    ///Set the position of the shape
    temp_shape->position(p);

    ///Get the type of the shape using the array of types
    temp_shape->type(t);

    return temp_shape;
}

std::array<double, 2> write_test(const string &fileName) {
    mt19937 rng(0);

    vector<string> shapeName = {"Rectangle", "Triangle", "Circle", "SemiCircle"};

    int shape_id;
    std::array<double, 2> pos, com;
    double param1, param2;
    double area_sum;
    shape *s;
    ofstream output(fileName.c_str());
    output << std::fixed << std::setprecision(8);

    com[0] = 0;
    com[1] = 0;
    area_sum = 0;

    //Generate the solid. We make it big
    shape_id = ((int) rng()) % 4;
    pos[0] = 0;
    pos[1] = 0;
    param1 = (double) ((int) rng() % 900) + 100;
    if(shape_id < 2)
        param2 = (double) ((int) rng() % 900) + 100;

    s = create_shape(shapeName[shape_id], ShapeType::Solid, pos, param1, param2);

    //Calculate the necessary part of the com for this shape
    com[0] += s->com()[0]*s->area();
    com[1] += s->com()[1]*s->area();
    area_sum += s->area();

    //Write out this shape
    output << shapeName[shape_id] << ",1," << pos[0] << "," << pos[1] << "," << param1;
    if(shape_id < 2)
        output << "," << param2;
    output << std::endl;

    //Generate the hole. We make it small and ensure that it is within the solid
    shape_id = ((int) rng()) % 4;
    pos[0] = 50;
    pos[1] = 5;
    param1 = (double) ((int) rng() % 3) + 1;
    if(shape_id < 2)
        param2 = (double) ((int) rng() % 3) + 1;

    delete(s);
    s = create_shape(shapeName[shape_id], ShapeType::Solid, pos, param1, param2);

    //Calculate the necessary part of the com for this shape
    com[0] -= s->com()[0]*s->area();
    com[1] -= s->com()[1]*s->area();
    area_sum -= s->area();

    //Write out this shape
    output << shapeName[shape_id] << ",0," << pos[0] << "," << pos[1] << "," << param1;
    if(shape_id < 2)
        output << "," << param2;
    output << std::endl;

    delete(s);

    //Finish the com calc
    com[0] /= area_sum;
    com[1] /= area_sum;

    return com;
}

struct f {

    std::array<double, 2> com;

    f() {
        com = write_test("temp_test.csv");
    }

    ~f() {
        remove("temp_test.csv");
    }
};

BOOST_FIXTURE_TEST_SUITE(s, f)

/**
 * Check to make sure the center of mass calculation works properly with a solid
 * and a hole
 */
BOOST_AUTO_TEST_CASE(solidAndHole) {

    MultiShape *s;
    shapeParser p;

    s = p.parse_input("temp_test.csv");

    BOOST_REQUIRE_CLOSE(com[0], s->com()[0], 1.0e-15);
    BOOST_REQUIRE_CLOSE(com[1], s->com()[1], 1.0e-15);
    return;
}

BOOST_AUTO_TEST_SUITE_END()
