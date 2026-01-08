// Chapter 6: Operators
// Date: 2025-01-08
// Floating Point Comparisons
// Compile: clang++ float.cpp -o float

#include <cmath>    // for std::abs
#include <iostream>

const double absEpsilon = 0.0000001;

int example1()
{
    constexpr double d1 {100.0 - 99.99};
    constexpr double d2 {10.0 - 9.99};

    // d1 and d2 are mathematically equivalent, but floating point values are not precise!
    if (d1 == d2)
        std::cout << "d1 == d2" << '\n';    // be careful especially when using the equal operator!
    else if (d1 > d2)
        std::cout << "d1 > d2" << '\n';
    else if (d1 < d2)
        std::cout << "d1 < d2" << '\n';
    
    return 0;
}

/* Best practice to compare two floats, compare to a threshold */
bool approximatelyEqualAbs(double a, double b, double absEpsilon)
{
    return std::abs(a - b) <= absEpsilon;
}

int example2()
{
    constexpr double d1 {100.0 - 99.99};
    constexpr double d2 {10.0 - 9.99};

    if (approximatelyEqualAbs(d1, d2, absEpsilon))
        std::cout << "d1 == d2" << '\n';
    
    return 0;
}

int main()
{
    example1();
    example2();
    return 0;
}