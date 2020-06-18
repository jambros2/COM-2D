#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE shapes

#if defined __GNUC__ && __GNUC__>=6
  #pragma GCC diagnostic ignored "-Wwrite-strings"
#endif

#include <boost/test/included/unit_test.hpp>
#include <memory>
#include <math.h>
#include "../include/semi_circle.hpp"

using namespace std;
using namespace shapes;

/**
 * Checks the getters and setters for the semicircle
 */
BOOST_AUTO_TEST_CASE(memberAccess) {

    semiCircle c;

    //Use the setters to set the values
	std::array<double,2> nPos = {5.0, 6.0};
	c.position(nPos);
	c.type(Solid);
	c.radius(12.0);

	// Check that the setters worked
	BOOST_REQUIRE_CLOSE(5.0,c.position()[0],1.0e-15);
	BOOST_REQUIRE_CLOSE(6.0,c.position()[1],1.0e-15);
	BOOST_REQUIRE_CLOSE(12.0,c.radius(),1.0e-15);
	BOOST_REQUIRE_EQUAL(Solid,c.type());

	return;
}

/**
 * Check to make sure the area calculation works properly
 */
BOOST_AUTO_TEST_CASE(areaCalc) {

    semiCircle c;
    double area;

	std::array<double,2> nPos = {5.0, 6.0};
	c.position(nPos);
	c.type(Solid);
	c.radius(12.0);

    //Calculate the actual area
    area = M_PI * 72.0;

    BOOST_REQUIRE_CLOSE(area, c.area(), 1.0e-15);

    return;
}

/**
 * Check to make sure the center of mass calculation works properly
 */
BOOST_AUTO_TEST_CASE(comCalc) {

    semiCircle c;

	std::array<double,2> nPos = {5.0, 6.0};
	c.position(nPos);
	c.type(Solid);
	c.radius(12.0);

    //The COM for a semiCircle is the center, so just use the position
    BOOST_REQUIRE_CLOSE(5.0, c.com()[0], 1.0e-15);
    BOOST_REQUIRE_CLOSE(6.0+(4.0*12.0)/(3*M_PI), c.com()[1], 1.0e-15);
}
