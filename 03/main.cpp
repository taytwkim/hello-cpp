// Chapter 3: Debugging C++ Programs
// Date: 2025-12-29
// Using a Debugger
// Compile: clang++ -g main.cpp -o main

#include <iostream>

void print_value(int x)
{
    std::cout << x << "\n";
}

void a()
{
    std::cout << "a() called\n";
}

void b()
{
    std::cout << "b() called\n";
    a();
}

int main()
{
    int x = 5;
    print_value(x);

    // We can see the call stack in the debugger's call stack window
    a();
    b();

    return 0;
}
