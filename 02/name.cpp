// Chapter 2: C++ Basics: Functions and Files
// Date: 2025-12-28
// Namespaces

/* 1. Naming collision
 *
 * Consider the following example.
 * 
 * // a.cpp
 * void myFcn(int x) {
 *    std::cout << x;
 * }
 *
 * // main.cpp
 * void myFcn(int x) {
 *    std::cout << 2 * x;
 * }
 * 
 * int main() {
 *    return 0;
 * }
 * 
 * This code will throw an error, because there are two functions named myFcn, and the compiler/linker does not know how to resolve this symbol.
 * This is because by default, all functions are placed under the implictly-defined global namespace.
 * 
 * To avoid this conflict, we can use namespaces; two functions with the same name will not collide if declared under two different namespaces.
 * 
 * 2. std namespace
 * 
 * When C++ was originally designed, all of the identifiers in the standard library were available without the std:: prefix.
 * This turned out to be a problem, because the users may want to declare conflicting identifiers, 
 * or code that worked previously might suddenly fail as new identifiers are introduced in the standard library.
 * 
 * So C++ moved all of the functionality in the standard library into a namespace named std.
 * 
 * The std::cout prefix means "use cout in the std namespace".
 */

#include <iostream>

// 3. Using namespace
// One way to avoid using the std:: prefix is to use the "using" directive.
using namespace std;

// However, "using" directive may not be preferable because it may lead to errors.
// If the user tried to define a conflicting identifier, there will be errors.
// If we uncomment this, there will be errors.

// int cout() {
//     return 5;
// }

int main() {
    cout << "Hello World!\n";
    return 0;
}