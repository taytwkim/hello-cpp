// Chapter 5: Constants and Strings
// Date: 2025-1-2
// Constant Expressions
// Compile: clang++ constexpr.cpp -o constexpr

#include <iostream>

/* What are Constant Expressions?
 * 
 * Constant expressions are expressions that could be evaluated at compile time.
 * Constant expressions can only involve constant objects.
 * In some contexts, an expression is required be a constant expression, or the compiler will complain.
 */

int getFive()
{
    return 5;   // constant expression
}

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

constexpr int cmax(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{   
    getFive();          // runtime expression, even if it returns a constant

    const int a {1};    // can be used in constant expressions
    const int b {a};    // can be used in constant expressions
    const int c {a+2};  // can be used in constant expressions
    int d {1};          // cannot be used in constant expressions

    const int e {3+4};  // required to be a constant expression, will be evaluated at compile time
    int f {3+4};        // may or may not be evaluated at compile time.
    
    /* const vs. constexpr
     * 
     * const simply means that the value of an object cannot be changed after initialization. 
     * We are not guaranteed that its value will be konwn at compile-time.
     * This can be a problem. Sometimes, it might not be straightforward whether 
     * a const variable's value will be known at compile-time, and thus can be used in a constant expression.
     * 
     * In this case, we can use the constexpr keyword to define a variable which can be used in a constant expression.
     * The compiler will complain if the object's value is not known at compile-time.
     */

    constexpr int sum { 4+5 };

    // will throw an error because getFive() does not return a constexpr
    // constexpr int five { getFive() };
    
    /*
     * A constexpr function is a function that can be called in a constant expression. 
     * A constexpr function must evaluate at compile-time when the constant expression it is part of must evaluate at compile time. 
     * Otherwise, a constexpr function may be evaluated at either compile-time or runtime. 
     * To be eligible for compile-time execution, all arguments must be constant expressions.
     */

    int m1 { max(5, 6) };            // ok
    const int m2 { max(5, 6) };      // ok

    // compile error: max(5, 6) not a constant expression
    // constexpr int m3 { max(5, 6) };

    int m4 { cmax(5, 6) };           // ok: may evaluate at compile-time or runtime
    const int m5 { cmax(5, 6) };     // ok: may evaluate at compile-time or runtime
    constexpr int m6 { cmax(5, 6) }; // ok: must evaluate at compile-time

    return 0;
}