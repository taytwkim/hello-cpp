// Chapter 3: Debugging C++ Programs
// Date: 2025-12-29
// Printing Error Stataments
// Compile: clang++ debug.cpp -o debug

#include <iostream>

// It is good practice to define a macro so that debug statements can be turned on or off easily.
// Uncomment the macro below to enable debugging.
// #define ENABLE_DEBUG

int main() {
    // It is good practice to direct error messages to cerr instead of cout.
    // This is because cout is buffered, which means the the message might not be displayed right away.
    // On the other hand, cerr is not buffered, so the messages will be visible right away - easier to trace the source of the problem.

    #ifdef ENABLE_DEBUG
        std::cerr << "Error detected!\n";
    #endif

    std::cout << "Hello World!" << std::endl;
  }