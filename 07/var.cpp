// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-01-23
// Local and Global Variables
// Compile: clang++ var.cpp -o var

#include <iostream>

// global variables can be declared at the top of the file
int g_x {}; // it is common to use the 'g_' prefix for global variables

// Foo is defined in the global scope
namespace Foo
{
    int g_y {}; // g_y is inside the Foo namespace, but is still a global variable
}

// use of non-constant global variables should generally be avoided
int g_a;                // unlike local variables, global variables are zero initialized by default
int g_b {1};

// const int g_c;       // error: constants must be initialized
// constexpr int g_d;   // error: constexpr must be initialized

int main() 
{
    int x {0};

    std::cout << g_a << '\n';

    {
        int y {1};
        std::cout << x << '\n'; // x can be used here!
        std::cout << y << '\n'; // y can be used here!
    }

    // y cannot be used here!

    {
        int x {10};
        std::cout << x << '\n'; // the value of x is 10, not 0 here. this is called "variable shadowing"
    }
    
    return 0;
}