// Chapter 4: Fundamental Data Types
// Date: 2025-12-31
// Type Casting
// Compile: clang++ cast.cpp -o cast

#include <iostream>

// The function takes in an int parameter
void print(int x)
{
	std::cout << x << '\n';
}

int main()
{
    print(5.5);                     // Warning: we're passing in a double value
    print(static_cast<int>(5.5));   // We can explicitly convert the type   
    return 0;
}