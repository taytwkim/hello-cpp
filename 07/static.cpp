// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-02-04
// The static keyword
// Compile: clang++ static.cpp -o static

/*
 * The static keyword
 * 
 * The static keyword can have different meanings depending on the context.
 * 
 * 1. Internal Linkage
 * 
 * If the static keyword is used at the file scope for global (non-constant) variables or functions, 
 * it indicates internal linkage, i.e., the identifiers not being accessible outside the file.
 * 
 * 2. Static Duration
 * 
 * Static can also mean static duration. Static duration means that the variable is created at the start of the program,
 * and destroyed at the end of the program (global variables have static duration).
 * 
 * Local variables have auto duration by default. They are created when initialized in a block, and destroyed when we exit the block.
 * But by using the static keyword, we can make a local variable static (e.g., unique ID generation).
 * 
 * 3. Static Local Constants
 * 
 * Sometimes, we might want to declare a local constant as static.
 * 
 * For example, if computing a variable is expensive, we want to persist its value so that we don't have to recompute it everytime.
 * If a variable is computed within a function, we get the value in the first function call, and reuse it in subsequent calls.
 */

#include <iostream>

/* This is also used in OOP, e.g., assign a unique ID to an instance */
int get_uid() {
    static int s_id = 0;
    return s_id++;
}

int main() {
    std::cout << get_uid() << '\n';
    std::cout << get_uid() << '\n';
    std::cout << get_uid() << '\n';
    return 0;
}