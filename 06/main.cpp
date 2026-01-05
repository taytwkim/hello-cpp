// Chapter 6: Operators
// Date: 2025-1-5
// Operators
// Compile: clang++ main.cpp -o main

#include <cmath>        // for std::pow
#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

void printCalculation(int x, int y, int z)
{
    std::cout << x + (y * z) << "\n";
}

void example1()
{
    /* Ambiguous example that may lead to unexpected results */

    // We think that the first function parameter will be evaluated first, 
    // but the compiler has the freedom to compile the parameters in any order.
    printCalculation(getValue(), getValue(), getValue());

    // Not guaranteed, but we might observe:
    // - clang evaluates arguments in left-to-right order. 
    // - gcc compiler evaluates arguments in right-to-left order.
}

void example2()
{
    /* Unambiguous example */
    int a{ getValue() };        // will execute first
    int b{ getValue() };        // will execute second
    int c{ getValue() };        // will execute third
    printCalculation(a, b, c);  // this line is now unambiguous
}

long long ipow(long long base, long long exp)
{
    /* integer exponentiation */
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

void example3()
{
    double x { std::pow(3.0, 4.0) };
    std::cout << x << '\n';

    /*
    * C++ doesn’t provide a standard “integer power” function.
    * 
    * The main reason is that there is no consensus on desired behavior:
    *   - What should 2^-3 mean in an integer API?
    *   - What should happen on overflow?
    *
    * std::pow operates on floating-point values, so using it for integer
    * exponentiation can introduce rounding/precision issues and is best avoided when exact integer results are required.
    *
    * If you need integer exponentiation, use a third-party library (e.g., big-int or modular arithmetic) 
    * or implement a small integer power helper yourself.
    */

    long long y { ipow(2, 10) };
    std::cout << y << '\n';
}

int main()
{
    // example1();
    // example2();
    example3();
    return 0;
}