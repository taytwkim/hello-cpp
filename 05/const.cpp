// Chapter 5: Constants and Strings
// Date: 2025-1-1
// Constants and Numerals
// Compile: clang++ const.cpp -o const

#include <iostream>

void gravity()
{
    // Why use a constant variable?
    // 1. It reduces the chance of bugs - the compiler will complain if a constant variable is
    // overwritten accidentally.
    // 2. If the compiler knows that the variable is constant, it can perform additional
    // optimizations
    const double gravity{9.8};
}

void numerals()
{
    // octal
    int x{012};              // '0' before a number means this is octal
    std::cout << x << '\n';  // this will print 10

    // hexadecimal
    int y{0xF};              // '0x' before a number means this is hexadecimal
    std::cout << y << '\n';  // this will print 15

    // binary
    // we can use the 0b prefix to declare a binary literal
    int bin{};         // assume 16-bit ints
    bin = 0b1;         // assign binary 0000 0000 0000 0001 to the variable
    bin = 0b11;        // assign binary 0000 0000 0000 0011 to the variable
    bin = 0b1010;      // assign binary 0000 0000 0000 1010 to the variable
    bin = 0b11110000;  // assign binary 0000 0000 1111 0000 to the variable

    // digit separator
    // we can use ' to separate digits to make it easier to read
    int long_bin{0b1011'0010};
    long value{2'132'673'462};

    // printing values as decimal, octal, or hexadecimal
    int z{12};
    std::cout << z << '\n';              // print as decimal
    std::cout << std::hex << z << '\n';  // print as hex
    std::cout << std::oct << z << '\n';  // print as oct
    std::cout << std::dec << z << '\n';  // back to decimal
}

int main()
{
    numerals();
    return 0;
}