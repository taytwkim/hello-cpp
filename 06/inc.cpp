// Chapter 6: Operators
// Date: 2025-1-6
// Increment and Decrement Operators
// Compile: clang++ inc.cpp -o inc

/* 
 * The prefix (++x) and the postfix (x++) increment/decrement operators behave differently.
 * The prefix operator is more performant and should be preferred unless we specifically want postfix behavior.
 */

#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int x = 5;
    std::cout << ++x << '\n';   // increment x and use the incremented value to evaluate the expression.
    
    x = 5;  // reset x to 5
    
    // Postfix increment works like this:
    // First, the original value is copied to a temporary varible.
    // Then, x is incremented, and the copied (original) value is used to evaluate the expression.
    std::cout << x++ << '\n';

    // But if we use the increment operator on its own (without using it in an expression), then doesn't really matter which one we use.
    ++x;
    x++;

    x = 1;
    
    // Again, C++ does not guarantee that function parameters will be evluated in order, so something like below has an undefined result.
    // In clang, probably 1+2. In gcc, probably 2+2.
    std::cout << add(x, ++x) << '\n';   // might throw a warning

    return 0;
}