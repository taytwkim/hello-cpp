// Chapter 2: C++ Basics: Functions and Files
// Date: 2025-12-28
// Header Guard

/* Why use a header guard?
 * 
 * Without a header guard, this code will fail to compile.
 * This is because wave.h includes square.h, so this file ends up including square.h twice.
 * To prevent accidents like this, we use a header guard to include headers only once.
 * 
 * Note that to illustrate a point, getSquaredSides is defined within the header file, which we should generally avoid.
 * But sometimes it's necessary to include non-function definitions in a header file like custom types, so it's still good practice to use header guards.
 */

#include "square.h"
#include "wave.h"

int main() {
    return 0;
}