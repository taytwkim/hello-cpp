// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-01-30
// External Linkage
// Compile: clang++ main.cpp a.cpp -o extern

/*
 * External Linkage
 * An identifier with external linkage is truly global - it can be accessed across files.
 */

#include <iostream>

void sayHi();         // forward declaration of a function named sayHi defined somewhere else
extern int g_x;       // forward declaration of a variable named g_x defined somewhere else
extern const int g_y; // forward declaration of a const variable named g_y defined somewhere

int main() {
    sayHi();
    std::cout << g_x << ", " << g_y << '\n';   
    return 0;
}