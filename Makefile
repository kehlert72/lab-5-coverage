##
# @file Makefile
#
# @version 1.0
# @date Fall 2018
# @authors Michael John Decker, Ph.D.
#
# Makefile for string class.
#

all: string.o

string.o: string.cpp string.hpp
	clang++ -c string.cpp

###############################################################
# Variables
CPP     = clang++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11

TESTS = test_concat test_default_ctor test_cstring_ctor test_equality

###############################################################
# Compile string 
#
string: string.hpp string.cpp
	$(CPP) -c $(OPTIONS) string.cpp -o string.o

###############################################################
# Run all of your tests
# 
# You will need to ADD your other below:
# For example: ./test_plus
#
tests: $(TESTS)
	./test_default_ctor
	./test_equality
	./test_cstring_ctor
	./test_concat

###############################################################
# Compile all test programs
#
test_%: string.o test_%.o
	$(CPP) string.o test_$*.o -o test_$*

test_%.o: string.hpp test_%.cpp
	$(CPP) $(OPTIONS) -c test_$*.cpp

clean:
	rm -f *.o
	rm -f $(TESTS)
