// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-02-03
// Inline Functions and Variables
// Compile: clang++ main.cpp a.cpp b.cpp -o inline

/*
 * Inline Functions
 *
 * 1. Historical definition
 *
 * Traditionally, the inline keyword was used to indicate that a function can be expanded in place.
 * This avoids the overhead incurred from actually calling the function, and is well-suited for
 * short functions that are 2~3 lines.
 *
 * In the past, the compiler was pretty bad at figuring out which function can be expanded, so the
 * developer gave hints using the inline keyword. However, over time, compilers became pretty good
 * at figuring out which functions can be expanded. So now, the compiler might ignore the inline
 * keyword (choose not to expand), or expand the functions that aren't marked inline.
 *
 * So the historic definition is now mostly obsolete.
 *
 * 2. Modern definition
 *
 * In modern C++, the inline keyword is used to indicate that “multiple definitions are allowed”.
 *
 * Let's say two source files each implement a function with the same name and body (must be the
 * same). If the functions are marked inline, the compiler will not complain about naming
 * collisions.
 *
 * A common pattern is to define an inline function in a header file, which can be included in
 * multiple source files.
 *
 * 3. inline vs. static
 * static and inline seems to be similar in that they allow multiple definitions of a symbol.
 * However, how they work is conceptually different. static creates a private copy, while inline
 * "shares" the same function.
 */

#include <iostream>

#include "hello.hpp"

/* the same function is defined in a.cpp, but the compiler will not complain */
inline int min(int x, int y)
{
    return (x < y) ? x : y;
}

int main()
{
    std::cout << min(5, 6) << '\n';
    std::cout << min(3, 2) << '\n';

    hi();  // defined in hello.h and can be included in multiple source files

    return 0;
}