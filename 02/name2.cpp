// Chapter 2: C++ Basics: Functions and Files
// Date: 2025-01-06
// Namespaces
// clang++ name2.cpp -o name

#include <iostream>

namespace x {
void f(int x)
{
    std::cout << "x::f(int): " << x << "\n";
}
void g(int x)
{
    std::cout << "x::g(int): " << x << "\n";
}
}  // namespace x

namespace y {
// void f(int x) { std::cout << "x::f(int): " << x << "\n"; }   // if this line was uncommented,
// there could be an ambiguity issue.
void g(long x)
{
    std::cout << "y::g(long): " << x << "\n";
}
}  // namespace y

int main()
{
    // Note that namespaces respect scope, so can be declared within a block
    using namespace x;
    f(1);

    // Here, using namespace y will make names in BOTH namespaces be considered.
    // But there could be a problem if there's an ambiguity.
    using namespace y;
    f(1);
    g(1);  // here, g is fine because the two functions have different signatures (argument type).

    return 0;
}