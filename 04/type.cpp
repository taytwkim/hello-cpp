// Chapter 4: Fundamental Data Types
// Date: 2025-12-30
// Fundamental Data Types
// Compile: clang++ type.cpp -o type

#include <iomanip>    // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits>

void do_nothing()
{
    // void indicates "no type".
    // It is typically used for functions that do not have any return value.
}

void typeof_demo()
{
    // We can use the sizeof operator to find the size of each type (can vary by machine).
    
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    // C++ only guarantees that integers will have a certain minimum size, not that they will have a specific size.
    // So when we print the size of "long" and "long long", they may actually be the same though they have different "minimum size".

    std::cout << std::left; // left justify output
    std::cout << std::setw(16) << "bool:"         << sizeof(bool)         << " bytes\n";
    std::cout << std::setw(16) << "char:"         << sizeof(char)         << " bytes\n";
    std::cout << std::setw(16) << "short:"        << sizeof(short)        << " bytes\n";
    std::cout << std::setw(16) << "int:"          << sizeof(int)          << " bytes\n";
    std::cout << std::setw(16) << "long:"         << sizeof(long)         << " bytes\n";
    std::cout << std::setw(16) << "long long:"    << sizeof(long long)    << " bytes\n";
    std::cout << std::setw(16) << "float:"        << sizeof(float)        << " bytes\n";
    std::cout << std::setw(16) << "double:"       << sizeof(double)       << " bytes\n";
    std::cout << std::setw(16) << "long double:"  << sizeof(long double)  << " bytes\n\n";

    // We can use also use the typeof operator on a variable.
    // But note that the sizeof operator will not count memory dynamically allocated for the object.
    int x = 16;
    std::cout << "x: " << sizeof(x) << " bytes\n\n";
}

void signed_int_demo()
{
    int i;          // by default, integers are signed
    short s;        // prefer "short" instead of "short int"
    long l;         // prefer "long" instead of "long int"
    long long ll;   // prefer "long long" instead of "long long int"

    // Integer division will simply drop the fraction (not round)
    std::cout << "8 / 5 is: " << 8 / 5 << '\n';   // will be 1

    // Unsigned integers
    unsigned short us;
    unsigned int ui;
    unsigned long ul;
    unsigned long long ull;
}

int main ()
{
    // std::cout << "Hello World!" << std::endl;
    
    typeof_demo();
    signed_int_demo();

    return 0;
}