#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE shapes

#if defined __GNUC__ && __GNUC__>=6
  #pragma GCC diagnostic ignored "-Wwrite-strings"
#endif

#include <boost/test/included/unit_test.hpp>
#include <memory>
#include <math.h>
#include "../include/rectangle.hpp"

using namespace std;
using namespace shapes;

/**
 * Checks the getters and setters for the rectangle
 */
BOOST_AUTO_TEST_CASE(memberAccess) {

    rectangle r;

    //Use the setters to set the values
	std::array<double,2> nPos = {5.0, 6.0};
	r.position(nPos);
	r.type(Solid);
	r.width(12.0);
	r.height(10.0);

	// Check that the setters worked
	BOOST_REQUIRE_CLOSE(5.0, r.position()[0], 1.0e-15);
	BOOST_REQUIRE_CLOSE(6.0, r.position()[1], 1.0e-15);
	BOOST_REQUIRE_CLOSE(12.0, r.width(), 1.0e-15);
	BOOST_REQUIRE_CLOSE(10.0, r.height(), 1.0e-15);
	BOOST_REQUIRE_EQUAL(Solid, r.type());

	return;
}

/**
 * Check to make sure the area calculation works properly
 */
BOOST_AUTO_TEST_CASE(areaCalc) {

    rectangle r;
    double area;

	std::array<double,2> nPos = {5.0, 6.0};
	r.position(nPos);
	r.type(Solid);
	r.width(12.0);
	r.height(10.0);

    BOOST_REQUIRE_CLOSE(120.0, r.area(), 1.0e-15);

    return;
}

/**
 * Check to make sure the center of mass calculation works properly
 */
BOOST_AUTO_TEST_CASE(comCalc) {

    rectangle r;

	std::array<double,2> nPos = {5.0, 6.0};
	r.position(nPos);
	r.type(Solid);
	r.width(12.0);
	r.height(10.0);

    //The COM for a circle is the center, so just use the position
    BOOST_REQUIRE_CLOSE(6.0+5, r.com()[0], 1.0e-15);
    BOOST_REQUIRE_CLOSE(5.0+6, r.com()[1], 1.0e-15);
}
