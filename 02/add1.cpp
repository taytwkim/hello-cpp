// Chapter 2: C++ Basics: Functions and Files
// Date: 2025-12-28
// Forward Declaration
// Compile: clang++ add.cpp -o add

#include <iostream>

// In C++, a function must be declared before it is used.
// A forward declaration tells the compiler about a function's name, return type, and parameters before its actual definition.

int add (int a, int b); // If we comment out this line, the compiler will throw an error because 'add' is used before its declaration.

int main () {
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << std::endl;
    return 0;
}

int add (int a, int b) {
    return a + b;
}