// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-01-20
// User-defined Namespaces
// Compile: clang++ name1.cpp -o name1

#include <iostream>

// put in a global namespace
int doSomething(int x, int y) {
    return x * y;
}

namespace foo {
    int doSomething(int x, int y) {
        return x + y;
    }
}

namespace goo {
    int doSomething(int x, int y) {
        return x - y;
    }

    // use the scope resolution operator (::) without specifying the namespace to look into the GLOBAL namespace
    int doSomething2(int x, int y) {
        return ::doSomething(x, y);
    }
}

// nested namespaces
namespace nested {
    namespace ns {
        int add(int x, int y) {
            return x + y;
        }
    }
}

int main() {
    int x = 2;
    int y = 1;

    std::cout << doSomething(x, y) << "\n"; // use the global namespace

    // use the scope resolution operator to explicitly choose which namespace to look into
    std::cout << foo::doSomething(x, y) << '\n';
    std::cout << goo::doSomething(x, y) << '\n';
    std::cout << goo::doSomething2(x, y) << '\n';

    // nested namespaces
    std::cout << nested::ns::add(x, y) << '\n';

    // set up an alias for namespace
    // if we use an alias, we don't have to type the namespace name every time, 
    // and if the namespace ever changes, we can update the alias instead of updating every place the namespace is used.
    namespace alias = nested::ns;
    std::cout << alias::add(x, y) << '\n';

    return 0;
}