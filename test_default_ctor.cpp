/**
 * @file test_default_ctor.cpp
 *
 * Tests String class default constructor.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

#include <cassert>
#include <iostream>

int main () {

    {
	String s;
	assert(s[0] == '\0');
	assert(s.length() == 0);
    }

    return 0;
}
