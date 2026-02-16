// Chapter 5: Constants and Strings
// Date: 2025-1-3
// Strings (std::string_view)
// Compile: clang++ strview.cpp -o strview

#include <iostream>
#include <string>

/*
 * std::string_view is a "read-only" string.
 *
 * The analogy is that we are "viewing" the string through a window, but does not own or can modify
 * it.
 *
 * This could be a bit misleading, but it's really just a pointer to where the characters are stored
 * (plus the string length). Because std::string_view is basically a pointer + length, we can pass
 * it around without making a copy of the full string.
 *
 * string_view is read-only in the sense that the compiler will not let us update the characters
 * using string_view, but the underlying character buffer may still be mutable and could be modified
 * if we have some other handle to that same memory.
 *
 * std::string_view is best used as a read-only function parameter.
 */

void printString(std::string s)
{
    std::cout << s << '\n';
}

// std::string_view is best used as a read-only function parameter
void printSV(std::string_view str)
{
    std::cout << str << '\n';
}

void example1()
{
    // when we declare a string, a C-style literal (the RHS of the equation) "Hello world" is copied
    // into the memory, which is slow
    std::string s{"Hello, world!"};
    std::cout << s << '\n';

    // Furthermore, calling this function will make a local copy of s, which is also slow.
    printString(s);
}

void example2()
{
    std::string_view s{"Hello, world!"};

    // This time, we create a local copy of the pointer, not the full string.
    // So for function parameters, string_view may be preferred if we are not going to modify the
    // string in the function (e.g., convert to lowercase).
    printSV(s);
}

void example3()
{
    // Also note that string_view can be updated to point a new string, but the original string will
    // still be there
    std::string name{"Alex"};
    std::string_view sv{name};  // sv is now viewing name
    std::cout << sv << '\n';    // prints Alex

    sv = "John";                // sv is now viewing "John" (does not change the underlying "name")
    std::cout << sv << '\n';    // prints John
    std::cout << name << '\n';  // prints Alex
}

void example4()
{
    std::string x = "Hello";

    // Here, std::string makes a full copy of the initializer (the RHS), so is independent from x.
    // On the other hand, z is dependent on x.
    // If x is destroyed or updated, y will not be affected but z might have unexpected
    // consequences.
    std::string y = x;
    std::string_view z = x;

    x = "World!";
    std::cout << z << '\n';  // UNDEFINED BEHAVIOR because x has been updated
    z = x;                   // But we can "revalidate" z to point to the updated string
}

void example5()
{
    /* We can update "our view" of the string without modifying the underlying string */

    std::string_view str{"Peach"};
    std::cout << str << '\n';

    // Remove 1 character from the left side of the view
    str.remove_prefix(1);
    std::cout << str << '\n';

    // Remove 2 characters from the right side of the view
    str.remove_suffix(2);
    std::cout << str << '\n';

    str = "Peach";  // reset the view
    std::cout << str << '\n';
}

int main()
{
    example1();
    example2();
    example3();
    example4();
    example5();

    return 0;
}