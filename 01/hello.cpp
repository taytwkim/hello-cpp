// Chapter 1: C++ Basics
// Date: 2025-12-27
// Dissecting Hello World in C++
// Compile: clang++ hello.cpp -o hello

// Anything that starts with a # is a preprocessor directive.
// A preprocessor runs before the compiler and handles directives that start with #, such as including files or defining macros.
// #include tells the preprocessor to paste the contents of that header file into the source file at that spot.
#include <iostream>

int main() {
    /* The "std::"" syntax means that we are using the cout function from the standard (std) namespace.
     * 
     * What is a namespace?
     * 
     * A namespace is basically a container for identifiers (such as variable and function names).
     * Namespaces are used to avoid name collisions in larger projects.
     * In our case, iostream's functions are defined within the std namespace.
     * 
     * std::cout is the standard character output stream. It is used to output data to the standard output device (usually the screen).
     * std::endl is used to insert a newline character (stands for end line).
     * 
     * We have to be careful and intentional when using std::endl.
     * Using std::endl forces the output buffer to flush, which can be less efficient than just using '\n' for new lines.
     * 
     * For instance, let's say we have:
     * 
     * std::cout << "a\n";
     * std::cout << "b\n";
     * std::cout << "c\n";
     * 
     * In this example, we print three characters, but don't flush them immediately.
     * This means that the system can store the characters in the buffer and flush them all at once.
     * So the characters will be eventually printed, but not necessarily right away.
     * But if we used std::endl after each printing each character, we are making frequent small writes instead of one big write, so it can be slow.
     */
    std::cout << "Hello, World!" << std::endl;

    // For the main function, it is standard practice to return 0 to indicate normal or expected exit.
    // If there was an error, a non-zero value could be returned to indicate an abnormal termination.
    return 0;
}