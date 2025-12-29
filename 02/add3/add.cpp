// Chapter 2: C++ Basics: Functions and Files
// Date: 2025-12-28
// Header File

// It is best practice for the source file to include its paired header file.
// This is because this allows the compiler to catch certain kind of errors early on.
// For example, if add.h and add.cpp declare functions that don't match (e.g., have different return type), the compiler will complain.
#include "add.h"

int add(int x, int y) {
    return x + y;
}