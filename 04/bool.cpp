// Chapter 4: Fundamental Data Types
// Date: 2025-12-30
// Booleans
// Compile: clang++ bool.cpp -o bool

#include <iostream>

int main()
{
    // This will print 0 or 1 instead of "true" or "false"
    std::cout << true << '\n';
    std::cout << false << '\n';

    // This tells std::cout to print booleans as "true" or "false"
    std::cout << std::boolalpha;
    std::cout << true << '\n';
    std::cout << false << '\n';

    // Turn off std::noboolalpha
    std::cout << std::noboolalpha; 
    std::cout << true << '\n';
    std::cout << false << '\n';
    
    return 0;
}