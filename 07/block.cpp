// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-01-20
// Compound Statements
// Compile: clang++ block.cpp -o block

#include <iostream>

// A compound statement is a group of zero or more statements that is treated by the compiler as if it were a single statement.

int main()
{
    // 1. function blocks are an example of a compound statement

    // 2. conditional blocks are also an example of a compound statement
    // technically speaking, `if (cond)` should be followed by a single statement, which is why we use a block to group statements. 
    if (true) {
        std::cout << "Hello ";
        std::cout << "World!\n";
    }

    return 0;
}