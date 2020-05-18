/**
 * @file test_equality.cpp
 *
 * Tests String class operator==(const String &)
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

#include <cassert>
#include <iostream>

int main () {
    
    {
	String s;
	assert(s == "");
    }

    {
	String s('a');
	assert(s == "a");
    }

    {
	String s("abc");
	assert(s == "abc");
    }

    {
	String s("abcdefg");
	assert(s == "abcdefg");
    }

    {
	String s("abcdefg");
	String t("bbcdefg");
	assert(!(s == t));
    }

    {
	String s("abcdefg");
	String t("abceefg");
	assert(!(s == t));
    }

    {
	String s("abcdefg");
	String t("abcdeff");
	assert(!(s == t));
    }

    {
	String s("");
	String t("abc");
	assert(!(s == t));
	assert(!(t == s));
    }

    {
	String s("ab");
	String t("abcd");
	assert(!(s == t));
	assert(!(t == s));
    }

    return 0;
}
