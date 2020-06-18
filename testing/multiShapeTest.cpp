#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE shapes

#if defined __GNUC__ && __GNUC__>=6
  #pragma GCC diagnostic ignored "-Wwrite-strings"
#endif

#include <boost/test/included/unit_test.hpp>
#include <memory>
#include <math.h>
#include "../include/rectangle.hpp"
#include "../include/triangle.hpp"
#include "../include/circle.hpp"
#include "../include/semi_circle.hpp"
#include "../include/multi_shape.hpp"

using namespace std;
using namespace shapes;

/**
 * Checks the ability to add a shape and calculate COM for one shape
 */
BOOST_AUTO_TEST_CASE(shapeAddition) {

    MultiShape s;
    vector<string> line;

    //Verify that there are no shapes is empty (com at 0,0)

    BOOST_REQUIRE_CLOSE(0.0, s.com()[0], 1.0e-15);
    BOOST_REQUIRE_CLOSE(0.0, s.com()[1], 1.0e-15);

    //Add a shape and verify that the com is now changed
    //Solid Circle - Radius 2 - Center (2,2) - COM (2,2)

    line.push_back("Circle");
    line.push_back("1");
    line.push_back("2");
    line.push_back("2");
    line.push_back("2");

    s.add_shape(line);

    BOOST_REQUIRE_CLOSE(2.0, s.com()[0], 1.0e-15);
    BOOST_REQUIRE_CLOSE(2.0, s.com()[1], 1.0e-15);

	return;
}

/**
 * Check to make sure the center of mass calculation works properly with two solids
 */
BOOST_AUTO_TEST_CASE(twoSolids) {

    MultiShape s;
    vector<string> line;
    std::array<double, 2> com, circC, rectC;
    double circA, rectA;


    //Add a shape
    //Solid Circle - Radius 2 - Center (2,6) - COM (2,6)

    line.push_back("Circle");
    line.push_back("1");
    line.push_back("2");
    line.push_back("6");
    line.push_back("2");

    circC[0] = 2;
    circC[1] = 6;
    circA = M_PI * 4.0;

    s.add_shape(line);

    //Add a shape
    //Solid Rectangle - Dims 4x4 - Corner (0,0) - COM (2,2)

    line.resize(0);
    line.push_back("Rectangle");
    line.push_back("1");
    line.push_back("0");
    line.push_back("0");
    line.push_back("4");
    line.push_back("4");

    rectC[0] = 2;
    rectC[1] = 2;
    rectA = 16;

    s.add_shape(line);

    //Calculate the com

    com[0] = (rectC[0]*rectA + circC[0]*circA)/(rectA + circA);
    com[1] = (rectC[1]*rectA + circC[1]*circA)/(rectA + circA);

    BOOST_REQUIRE_CLOSE(com[0], s.com()[0], 1.0e-15);
    BOOST_REQUIRE_CLOSE(com[1], s.com()[1], 1.0e-15);

    return;
}

/**
 * Check to make sure the center of mass calculation works properly with a solid
 * and a hole
 */
BOOST_AUTO_TEST_CASE(solidAndHole) {

    MultiShape s;
    vector<string> line;
    std::array<double, 2> com, triC, rectC;
    double triA, rectA;

    //Add a shape
    //Solid Rectangle - Dims 4x4 - Corner (0,0) - COM (2,2)

    line.push_back("Rectangle");
    line.push_back("1");
    line.push_back("0");
    line.push_back("0");
    line.push_back("4");
    line.push_back("4");

    rectC[0] = 2;
    rectC[1] = 2;
    rectA = 16;

    s.add_shape(line);

    //Add a shape
    //Triangle Hole - Base 2 - Height 2 - Corner (2,2) - COM (8/3,8/3)

    line.resize(0);
    line.push_back("Triangle");
    line.push_back("0");
    line.push_back("2");
    line.push_back("2");
    line.push_back("2");
    line.push_back("2");

    triC[0] = 8.0/3.0;
    triC[1] = 8.0/3.0;
    triA = 2.0;

    s.add_shape(line);

    //Calculate the com

    com[0] = (rectC[0]*rectA - triC[0]*triA)/(rectA - triA);
    com[1] = (rectC[1]*rectA - triC[1]*triA)/(rectA - triA);

    BOOST_REQUIRE_CLOSE(com[0], s.com()[0], 1.0e-15);
    BOOST_REQUIRE_CLOSE(com[1], s.com()[1], 1.0e-15);
    return;
}

/**
 * Check to make sure the center of mass calculation works properly with two solids and
 * a hole
 */
BOOST_AUTO_TEST_CASE(twoSolidsAndHole) {

    MultiShape s;
    vector<string> line;
    std::array<double, 2> com, circC, rectC, semiC;
    double circA, rectA, semiA;


    //Add a shape
    //Solid Circle - Radius 2 - Center (2,6) - COM (2,6)

    line.push_back("Circle");
    line.push_back("1");
    line.push_back("2");
    line.push_back("6");
    line.push_back("2");

    circC[0] = 2;
    circC[1] = 6;
    circA = M_PI * 4.0;

    s.add_shape(line);

    //Add a shape
    //Solid Rectangle - Dims 4x4 - Corner (0,0) - COM (2,2)

    line.resize(0);
    line.push_back("Rectangle");
    line.push_back("1");
    line.push_back("0");
    line.push_back("0");
    line.push_back("4");
    line.push_back("4");

    rectC[0] = 2;
    rectC[1] = 2;
    rectA = 16;

    s.add_shape(line);

    //Add a shape
    //Semicircle hole - Radius 1 - Center (3,2) - COM (3, 2 + 4/(3pi))

    line.resize(0);
    line.push_back("SemiCircle");
    line.push_back("0");
    line.push_back("3");
    line.push_back("2");
    line.push_back("1");

    semiC[0] = 3;
    semiC[1] = 2+4.0/(3.0*M_PI);
    semiA = M_PI/2.0;

    s.add_shape(line);

    //Calculate the com

    com[0] = (rectC[0]*rectA + circC[0]*circA - semiC[0]*semiA)/(rectA + circA - semiA);
    com[1] = (rectC[1]*rectA + circC[1]*circA - semiC[1]*semiA)/(rectA + circA - semiA);

    BOOST_REQUIRE_CLOSE(com[0], s.com()[0], 1.0e-15);
    BOOST_REQUIRE_CLOSE(com[1], s.com()[1], 1.0e-15);
    return;
}
