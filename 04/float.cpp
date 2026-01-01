// Chapter 4: Fundamental Data Types
// Date: 2025-12-31
// Floating Point Numbers
// Compile: clang++ float.cpp -o float

#include <iomanip> // for output manipulator std::setprecision()
#include <iostream>

int main()
{
    // float f;
    // double d;
    // long double ld;

    int a { 5 };        // 5 means integer
    double b { 5.0 };   // 5.0 is a floating point literal (no suffix means double type by default)

    // Below, if we don't include the "f" suffix, the code will fail to compile.
    // This is because 5.0 is by default a double, so this line will try to convert a double to a float.
    // But since list initialization does not allow narrowing conversions, the conversion will fail.
    // But float c = 5.0 will be fine.

    float c { 5.0f };   // 5.0 is a floating point literal, f suffix means float type
    int d { 0 };        // 0 is an integer
    double e { 0.0 };   // 0.0 is a double

    // Printing floating point numbers
    std::cout << 5.0 << '\n';         // will just print 5 (by default, std::cout will not print the fractional part of a number if the fractional part is 0.)
	  std::cout << 6.7f << '\n';
	  std::cout << 9876543.21 << '\n';  // will be in scientific notation

    // std::cout will truncate float to six significant digits
    std::cout << 9.87654321f << '\n';

    // We can set the precision for std::cout
    // Be careful! The values may not be precise.
    std::cout << std::setprecision(17);                               // show 17 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f <<'\n';    // f suffix means float - will not be precise
    std::cout << 3.33333333333333333333333333333333333333 << '\n';    // no suffix means double - will not be precise

    return 0;
}