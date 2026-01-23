// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-01-23
// Local Variables
// Compile: clang++ local.cpp -o local

#include <iostream>

int main()
{
    int x = 0;

    {
        int y = 1;
        std::cout << x << '\n'; // x can be used here!
        std::cout << y << '\n'; // y can be used here!
    }

    // y cannot be used here!
    
    return 0;
}