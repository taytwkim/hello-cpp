// Chapter 2: C++ Basics: Functions and Files
// Date: 2025-12-28
// Header File
// Compile: clang++ main.cpp add.cpp -o add

// brackets <> are for header files that we did not write
// quotes "" are for header files that we wrote 
#include <iostream> 
#include "add.h"

// Note that a header file might also include a header file, 
// which recursively brings in headers (also called transitive includes).

int main () {
    std::cout << "5 + 7 is " << add(5, 7) << std::endl;
    return 0;
}