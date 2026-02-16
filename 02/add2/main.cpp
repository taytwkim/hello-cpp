// Chapter 2: C++ Basics: Functions and Files
// Date: 2025-12-28
// Using Multiple Files
// Compile: clang++ main.cpp add.cpp -o add

#include <iostream>

// This function is defined in a different file, but we still need to declare it here in order to
// use it.
int add(int x, int y);

int main()
{
    std::cout << "The sum of 5 and 7 is " << add(5, 7) << std::endl;
    return 0;
}