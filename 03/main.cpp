// Chapter 3: Debugging C++ Programs
// Date: 2025-12-29
// Using a Debugger
// Compile: clang++ main.cpp -o main

#include <iostream>

void print_value(int x) {
    std::cout << x << "\n";
}

int main() {
    int x = 5;
    print_value(x);
    return 0;
}

