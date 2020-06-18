#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE shapes

#if defined __GNUC__ && __GNUC__>=6
  #pragma GCC diagnostic ignored "-Wwrite-strings"
#endif

#include <boost/test/included/unit_test.hpp>
#include <memory>
#include <math.h>
#include "../include/triangle.hpp"

using namespace std;
using namespace shapes;

/**
 * Checks the getters and setters for the triangle
 */
BOOST_AUTO_TEST_CASE(memberAccess) {

    triangle t;

    //Use the setters to set the values
	std::array<double,2> nPos = {5.0, 6.0};
	t.position(nPos);
	t.type(Solid);
	t.base(12.0);
	t.height(10.0);

	// Check that the setters worked
	BOOST_REQUIRE_CLOSE(5.0, t.position()[0], 1.0e-15);
	BOOST_REQUIRE_CLOSE(6.0, t.position()[1], 1.0e-15);
	BOOST_REQUIRE_CLOSE(12.0, t.base(), 1.0e-15);
	BOOST_REQUIRE_CLOSE(10.0, t.height(), 1.0e-15);
	BOOST_REQUIRE_EQUAL(Solid, t.type());

	return;
}

/**
 * Check to make sure the area calculation works properly
 */
BOOST_AUTO_TEST_CASE(areaCalc) {

    triangle t;
    double area;

	std::array<double,2> nPos = {5.0, 6.0};
	t.position(nPos);
	t.type(Solid);
	t.base(12.0);
	t.height(10.0);

    BOOST_REQUIRE_CLOSE(60.0, t.area(), 1.0e-15);

    return;
}

/**
 * Check to make sure the center of mass calculation works properly
 */
BOOST_AUTO_TEST_CASE(comCalc) {

    triangle t;

	std::array<double,2> nPos = {5.0, 6.0};
	t.position(nPos);
	t.type(Solid);
	t.base(12.0);
	t.height(10.0);

    //The COM for a circle is the center, so just use the position
    BOOST_REQUIRE_CLOSE(4.0+5, t.com()[0], 1.0e-15);
    BOOST_REQUIRE_CLOSE(10.0/3.0+6, t.com()[1], 1.0e-15);
}
