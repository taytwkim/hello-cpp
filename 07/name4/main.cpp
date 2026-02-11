// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-02-11
// unnamed and inline namespaces
// Compile: clang++ main.cpp -o main

#include <iostream>

/*
 * 1. unnamed namespaces

 * unnamed namespaces are defined without a name. The function can be accessible from the parent namespace.
 * All identifiers inside an unnamed namespace are treated as if they have internal linkage - effectively the same as
 * defining all functions in the unnamed namespace as static functions.
 * 
 * One usecase of unnamed namespaces is to mark a bunch of functions static.
 */

namespace x {
    namespace {
        // unnamed namespace, can be accessed from the parent namespace
        void doSomething() {
            std::cout << "Hello World!\n";
        }
    }
}

/*
 * 2. inline namespaces

 * Like in unnamed namespaces, any identifier declared in inline namespaces is accessible from the parent namespace.
 * However, inline namespaces don't affect the linkage.
 * inline namespaces are commonly used for versioning.
 */

namespace lib {
    // can be accessed via lib::doSomething()
    inline namespace v1 {
        void doSomething() {
            std::cout << "Hello!\n";
        }
    }

    // can be accessed via lib::v2::doSomething()
    namespace v2 {
        void doSomething() {
            std::cout << "World!\n";
        }
    }
}

int main () {
    x::doSomething();
    lib::doSomething();     // this will print "Hello" because v1 is inline
    lib::v2::doSomething(); // this will print "World"

    return 0;
}