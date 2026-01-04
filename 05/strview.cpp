// Chapter 5: Constants and Strings
// Date: 2025-1-3
// Strings (std::string_view)
// Compile: clang++ strview.cpp -o strview

#include <iostream>
#include <string>

/* 
 * std::string_view is a "read-only" string.
 *
 * This could be a bit misleading, but it's really just a pointer to where the characters are stored (plus the string length).
 * Because std::string_view is basically pointer + length, we can pass it around without making a copy of the full string.
 *
 * string_view is read-only in the sense that the compiler will not let us update the characters using string_view,
 * but the underlying character buffer may still be mutable and could be modified through some other writable handle to that same memory.
 */

void printString(std::string s)
{
    std::cout << s << '\n';
}

void printSV(std::string_view str)
{
    std::cout << str << '\n';
}

void example1()
{
    std::string s { "Hello, world!" };  // when we declare a string, a C-style literal "Hello world" is copied into the memory, which is slow
    std::cout << s << '\n';             // if all we do is to print, not worth it to pay the cost

    // Furthermore, calling this function will make a local copy of s, which is also slow.
    printString(s);
}

void example2()
{
    std::string_view s{ "Hello, world!" };

    // This time, we create a local copy of the pointer, not the full string, so more efficient.
    // So for function parameters, string_view may be preferred.
    // But if we want to modify the string in the function (e.g., convert to lowercase), just use std::string.
    printSV(s);
}

void example3()
{
    // Also note that string_view can be updated to point a new string, but the original string will still be there
    std::string name { "Alex" };
    std::string_view sv { name }; // sv is now viewing name
    std::cout << sv << '\n';      // prints Alex

    sv = "John";                  // sv is now viewing "John" (does not change name)

    std::cout << sv << '\n';      // prints John
    std::cout << name << '\n';    // prints Alex
}

int main()
{
    example1();
    example2();
    example3();
    
    return 0;
}