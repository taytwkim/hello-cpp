// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-01-23
// Sharing global constants across multiple files
// Compile: clang++ main.cpp -o circle

// We can use the inline to share global constants across files (C++17)

#include <iostream>

#include "constants.hpp"

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}