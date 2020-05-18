/**
 * @file test_concat.cpp
 *
 * Tests String class operator+
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

#include <cassert>
#include <iostream>

//===========================================================================
int main () {

    {
	String lhs("foo");
	String rhs("bar");

	String result = lhs + rhs;

	assert(lhs == "foo");
	assert(rhs == "bar");
	assert(result == "foobar");
    }

    return 0;
}

