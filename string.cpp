/**
 * @file string.cpp
 *
 * Implements a fixed size string class.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

/**
 * String
 *
 * @post str = ""
 */
String::String() {
    str[0] = 0;
}

/**
 * String
 *
 * @post str = "c"
 */
String::String(char c) {
    str[0] = c;
    str[1] = 0;
}

/**
 * String
 *
 * @post str = "abc"
 */
String::String(const char * cstr) {

    int pos = 0;
    while(cstr[pos] != 0) {
        str[pos] = cstr[pos];
        ++pos;
        if(pos >= capacity()) break;
    }

    str[pos] = 0;

}

/**
 * capacity
 *
 * @returns the total number of characters the string can hold
 */
int String::capacity() const {
    return STRING_SIZE - 1;
}

/**
 * length
 *
 * @returns the number of characters currently used
 */
int String::length() const {

    int size = 0;
    while(str[size] != 0) {
        ++size;
    }
    return size;

}

/**
 * operator[]
 * @pre 0 <= i < length()
 * @pos return value == str[i]
 */
char & String::operator[](int i) {
    assert(i >= 0);
    assert(i < length() + 1);
    return str[i];
}

/**
 * operator[]
 * @pre 0 <= i < length()
 * @pos return value == str[i]
 */
char String::operator[](int i) const {
    assert(i >= 0);
    assert(i < length() + 1);
    return str[i];
}

bool String::operator==(const String & rhs) const {

    int pos = 0;
    while((str[pos] != 0) && (str[pos] == rhs.str[pos])) {
        ++pos;
    }
    return str[pos] == rhs.str[pos];

}


std::ostream & operator<<(std::ostream & out, const String & rhs) {
    out << rhs.str;
    return out;

}


std::istream & operator>>(std::istream & in, String & rhs) {
    in >> rhs.str;
    return in;

}

/**
 * operator+
 * @post return value == str + rhs.str;
 */
String String::operator+(const String & rhs) const {

    String result(str);
    int offset = length();

    int pos = 0;
    while(rhs.str[pos] != 0) {
        if((offset + pos) >= capacity()) break;
        result.str[offset + pos] = rhs.str[pos];
        ++pos;
    }

    result.str[offset + pos] = 0;
    return result;
}

/**
 * operator+=
 * @post return value = str + rhs.str;
 */
String & String::operator+=(String rhs) {

    int offset = length();
    int pos = 0;
    while(rhs.str[pos] != 0) {
        if((offset + pos) >= capacity()) break;
        str[offset + pos] = rhs.str[pos];
        ++pos;
    }
    str[offset + pos] = 0;
    return *this;
}


bool String::operator<(const String & rhs) const {

    int pos = 0;
    while(   str[pos] != 0
             && rhs.str[pos] != 0
             && str[pos] == rhs.str[pos]) {
        ++pos;
    }

    return str[pos] < rhs.str[pos];

}

// untested
int String::find(char ch, int start_pos) const {

    if(start_pos < 0 || start_pos >= length()) return -1;

    for(int pos = start_pos; str[pos] != 0 ; ++pos) {
        if(str[pos] == ch) {
            return pos;
        }
    }
    return -1;
}

int String::find(const String & s, int start_pos) const {

    if(s.str[0] == 0) return 0;
    if(start_pos < 0 || start_pos >= length()) return -1;

    for(int index = find(s[0], start_pos); index != -1; index = find(s[0], index + 1)) {

        int pos = 1;
        while(s.str[pos] != 0 && str[index + pos] != 0 && s.str[pos] == str[index + pos]) {
            ++pos;
	}
        if(s.str[pos] == 0) return index;
    }
    return -1;

}

String String::substr(int start_pos, int count) const {

    if(start_pos < 0 || start_pos >= length()) return String();

    char substring[count + 1];
    int num_chars = 0;
    while(num_chars < count && str[start_pos + num_chars] != 0){
        substring[num_chars] = str[start_pos + num_chars];
	++num_chars;
    }

    substring[num_chars] = 0;
    return substring;

}

std::vector<String> String::split(char ch) const {

    std::vector<String> splits;

    int start = 0;
    int end = 0;
    while((end = find(ch, start)) != -1) {
	splits.push_back(substr(start, end - start));
	start = end + 1;
    }
    splits.push_back(substr(start, length() - start));

    return splits;
}
