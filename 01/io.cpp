// Chapter 1: C++ Basics
// Date: 2025-12-28
// IO in C++
// Compile: clang++ io.cpp -o io

#include <iostream>

int main()
{
    // A new line character is not needed here as user will press enter after input.
    std::cout << "Enter a number: ";

    int x;

    // Like cout, cin is also buffered.
    std::cin >> x;

    std::cout << "You entered: " << x << std::endl;

    return 0;
}