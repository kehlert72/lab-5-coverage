/**
 * @file test_cstring_ctor.cpp
 *
 * Tests String class C string constructor.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

#include <cassert>
#include <iostream>

int main () {

    {
	String s("");
	assert(s[0] == '\0');
	assert(s.length() == 0);
    }

    return 0;
}
