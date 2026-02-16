// Chapter 2: C++ Basics: Functions and Files
// Date: 2025-12-28
// Header File
// Compile: clang++ main.cpp add.cpp -o add

/*
 * Brackets <> are for header files that we did not write.
 * Double quotes "" are for header files that we wrote.
 *
 * The #include will be replaced with actual contents of the header file.
 * The reason why we need a header file is because the compiler needs the "type", and that's why we
 * just need the function headers.
 *
 * Note that a header file might also include a header file, which recursively includes headers
 * (also called transitive includes). Also note that header files are not included in compilation.
 * It is handled by the preprocessor.
 */

#include <iostream>

#include "add.hpp"

int main()
{
    std::cout << "5 + 7 is " << add(5, 7) << std::endl;
    return 0;
}