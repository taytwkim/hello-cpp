// Chapter 1: C++ Basics
// Date: 2025-12-28
// Initializing Variables in C++
// Compile: clang++ var_init.cpp -o var_init

#include <iostream>
#include <vector>

int main()
{
    // There are several ways to initialize variables in C++.
    // As of C++17, these initializations behave identically in most cases.
    // However, using list initialization can be considered more modern or best practice.

    // Default initialization (uninitialized variable)
    int a;  // the value of 'a' is indeterminate (garbage value)

    // ===== Traditional initialization forms =====

    // Copy initialization
    // Copy-initialization has fallen out of favor due to being less efficient, but a lot of the
    // issues have been remedied since C++17.
    int b = 5;

    // Direct initialization
    // Direct initialization was initially introduced to allow for more efficient initialization of
    // complex objects. Direct initialization had fallen out of favor in modern C++, largely due to
    // being superseded by direct-list-initialization.
    int c(6);

    // ===== Modern initialization forms =====

    // List initialization (C++11 and later)
    // List-initialization was introduced to provide a initialization syntax that works in almost
    // all cases, behaves consistently, and has an unambiguous syntax that makes it easy to tell
    // where we’re initializing an object.
    int d{7};

    // List initialization also provides a way to initialize objects with a list of values rather
    // than a single value.
    std::vector<int> e{3, 7};  // [3, 7]

    // Value initialization (C++11 and later)
    int f{};  // initialized to zero instead of indeterminate value.

    // ===== Narrowing Conversions =====
    // One characteristic of list-initialization is that it prevents narrowing conversions.

    // int w1 { 4.5 }; // compile error: list-init does not allow narrowing conversion
    int w2 = 4.5;  // compiles: w2 copy-initialized to value 4
    int w3(4.5);   // compiles: w3 direct-initialized to value 4

    // std::cout << "w1: " << w1 << "\n";
    std::cout << "w2: " << w2 << "\n";
    std::cout << "w3: " << w3 << "\n";

    // ===== maybe_unused attribute =====
    // Normally, the compiler will complain if we declare a variable and never use it.
    // To avoid this warning, we can use the [[maybe_unused]] attribute.
    [[maybe_unused]] double pi{3.14159};

    return 0;
}