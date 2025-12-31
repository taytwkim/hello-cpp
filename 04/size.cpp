// Chapter 4: Fundamental Data Types
// Date: 2025-12-30
// Fixed-width Integers and size_t
// Compile: clang++ size.cpp -o size

#include <cstdint>    // for fixed-width integers
#include <iostream>

int main() {
    std::int32_t x { 32767 }; // x is always a 32-bit integer
    x = x + 1;                // so 32768 will always fit (will be an overflow if int is 16 bits)
    std::cout << x << "\n\n";
    
    std::int8_t y { 65 };     // initialize 8-bit integral type with value 65
    std::cout << y << "\n\n";   // You're probably expecting this to print 65, but it will print 'A'

    // fast and least integral types
    std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << '\n';
    std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
    std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
    std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n\n";

    // Using size_t
    int z { 5 };
    std::size_t s { sizeof(z) }; // sizeof returns a value of type std::size_t, so that should be the type of s
    std::cout << s << '\n';

    return 0;
}