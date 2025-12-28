// Chapter 2: C++ Basics: Functions and Files
// Date: 2025-12-28
// Preprocessors

// Compile: clang++ pre.cpp -o pre
// Print preprocessor output to stdout: clang++ -E pre.cpp

// Before compilation, each cpp file goes through preprocessing.
// The preprocessor makes various changes to the code.

// 1. #include
// Replaces the #include directive with the contents of the included file.
// The included contents might also have a #include, which will be preprocessed recursively.
#include <iostream>

// 2. Macros
// There are two types of macros: object-like and function-like.

// Object-like macros can be defined in one of two ways:
// 1. Without substitution text:  #define IDENTIFIER
// 2. With substitution text:     #define IDENTIFIER substitution_text

// Preprocessors don't understand C++ syntax so it can be defined inside functions, 
// but it is standard to declare at the top of the code and not inside any functions.
#define MY_NAME "Tay"
#define PRINT_A

int main() {
    std::cout << "Hello World!\n";   
    std::cout << "My name is " << MY_NAME << ".\n";

    // 3. Conditional Compilation

    // if defined
    #ifdef PRINT_A
        std::cout << "Print A" << "\n"; // will print because PRINT_A is defined
    #endif

    #ifdef PRINT_B
        std::cout << "Print B" << "\n"; // will not print because PRINT_B is not defined
    #endif

    // if not defined
    #ifndef PRINT_B
        std::cout << "Print B" << "\n"; // will print because PRINT_B is NOT defined
    #endif

    // "#if 0" excludes a block from being compiled
    // this could be an easy way to comment/uncomment a block of code as we can toggle between 0 and 1
    #if 0
        std::cout << "Print C" << "\n";
    #endif

    return 0;
}