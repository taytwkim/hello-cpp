// Chapter 6: Operators
// Date: 2025-01-07
// Conditional Operator
// Compile: clang++ cond.cpp -o cond

#include <iostream>

/* We can use the conditional operator (?:) in place of if else */

int main()
{
    int x = 1;
    int y = 2;
    int max;

    /*
    if (x > y) {
        max = x;
    }
    else {
        max = y;
    }
    */

    // The ?: operator has low precedence compared to most other operators, so always try to use
    // parenthesis.
    max = ((x > y) ? x : y);

    // Also, x and y should have the same type, or at least the compiler should know how to convert
    // x or y to have matching types.

    std::cout << (true ? 1 : 2) << '\n';     // okay: both operands are int
    std::cout << (false ? 1 : 2.2) << '\n';  // okay: int can be converted to double
    // std::cout << (true ? -1 : 2u) << '\n';   // surprising result: -1 converted to unsigned int,
    // result out of range

    return 0;
}