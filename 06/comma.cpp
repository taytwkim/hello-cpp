// Chapter 6: Operators
// Date: 2025-01-07
// Comma Operator
// Compile: clang++ comma.cpp -o comma

#include <iostream>

/*
 * The comma operator allows you to evaluate multiple expressions in a single expression.
 * The comma operator evaluates the left operand, then the right operand, and then returns the
 * result of the right operand. It's pretty much never used except maybe within for loops.
 */

int main()
{
    int x{1};
    int y{2};

    std::cout << (++x, ++y) << '\n';  // increment x and y, and evaluates to the right operand

    // Note that the comma operator had the lowest precedence, so these two lines have different
    // behavior.
    int z = (x, y);
    z = x, y;  // here, the assignment (z=x) takes precedence. So z gets assigned x, and y is
               // evaluated then discarded.

    // This is an example of how the comma operator can be used within for loops.
    // The for loop syntax is: for (init; cond; incr) { body }, where init, cond, and incr must each
    // be a single expression. So the comma operator allows us to update both i and j in a single
    // expression.

    for (int i = 0, j = 10; i < j; ++i, --j) {
        // ...
    }

    return 0;
}