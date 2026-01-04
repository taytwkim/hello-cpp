// Chapter 5: Constants and Strings
// Date: 2025-1-3
// Strings (std::string)
// Compile: clang++ str.cpp -o str

#include <iostream>
#include <string>

/*
 * Note that std::string and std::string_view (C++17) are features that have been introduced to replace the traditional C-style strings. 
 * While C-style strings are still available in C++, they should be avoided if possible.
 */

void example1()
{
    /* This is an example that might not work as intended. */
    
    // Let's say we input something like "John Doe" with a whitespace in between.
    std::cout << "Enter your full name: ";
    std::string name {};
    std::cin >> name;   // here, the name will only capture "John" and "Doe" will be buffered.

    std::cout << "Enter your favorite color: ";
    std::string color {};
    std::cin >> color;  // here, the color will capture "Doe" that was buffered before, not the color that we input.

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';
}

void example2()
{
    /* 
     * This example shows that we can use getline() to read a full line.
     * std::ws manipulates std::cin to ignore leading whitespaces.
     * This helps unintended results like std::getline picking up "\n" as the input.
     * Let's say we type "John" and press ENTER. The newline character could be buffered and picked up as the next input.
     */
    
    std::cout << "Enter your full name: ";
    std::string name {};
    std::getline(std::cin >> std::ws, name);    // read a full line of text into name

    std::cout << "Enter your favorite color: ";
    std::string color {};
    std::getline(std::cin >> std::ws, color);   // read a full line of text into color

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';
}

int main()
{
    std::string a {};     // this is an empty string

    std::string name { "Alice" };
    name = "Bob";         // can be overwritten and can handle strings of varying length
    
    std::cout << "My name is: " << name << "\n";
    std::cout << "length: " << name.length() << "\n";

    // example1();
    example2();

    std::cout << "foo\n";   // by default, no suffix means a C-style string literal
    
    // we can use the -s suffix to define a std::string literal
    using namespace std::string_literals; // need this namespace to use the -s suffix
    std::cout << "goo\n"s;

    // We can't use std::string as a constexpr
    // constexpr std::string name{ "Alex"s }; // compile error

    return 0;
}