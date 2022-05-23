#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Array.hpp"
#include "Array.cpp"
typedef Array::value_type* TArray;

TEST_CASE( "Arguments initialized") {
    int n = 2;
    Array c = Array(2 * n);
    TArray a = new Array::value_type[n];
    a[0] = -2;
    a[1] = 3;
    a[2] = 4;
    a[3] = -5;
    Array::iterator l = const_cast<Array::iterator>(c.begin());
    for (int j = 0; j < 2 * n; j++, l++)
        *l = a[j];
    c.add_absolute_non_pair();
    REQUIRE( c[0] == 1);
    REQUIRE( c[1] == 6);
    REQUIRE( c[2] == 7);
    REQUIRE( c[3] == -2);
}
