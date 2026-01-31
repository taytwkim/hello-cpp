// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-01-30
// Internal Linkage
// Compile: clang++ intern.cpp -o intern

#include <iostream>

/*
 * An identifier with an internal linkage is only available within the source file.
 * If two source files have identically named identifiers with internal linkage, the linker will not complain for naming collision.
 * 
 * Internal linkage is used:
 * 
 * 1. when we don't want the identifier to be accessible from the outside.
 * 2. when we don't want naming collision across different src files.
 */

static int g_x {0};     // we can give internal linkage using ths static keyword, accessible only in internal.cpp
const int g_y {1};      // const and constexpr have internal linkage by default
constexpr int g_z {2};

static int add (int x, int y) {
    return x + y;
}

int main () {
     std::cout << "Hello World!" << '\n';
     return 0;
}