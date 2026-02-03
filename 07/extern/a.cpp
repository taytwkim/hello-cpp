// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-01-30
// Internal Linkage
// Compile: g++ main.cpp a.cpp -o extern

// See main.cpp

#include <iostream>

// Non-constant globals are EVIL and should be avoided!
int g_x { 2 };                  // non-constant globals are external by default (no need to use extern)

extern const int g_y { 3 };     // const globals can be defined as extern, making them external
extern constexpr int g_z { 3 }; // constexpr globals can be defined as extern, making them external

/* Functions have external linkage by default */
void sayHi() {
    std::cout << "Hello World!" << '\n';
}