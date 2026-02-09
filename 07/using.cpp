// Chapter 7: Scope, Duration, and Linkage
// Date: 2025-02-09
// using directives and declarations
// Compile: clang++ using.cpp -o using

#include <iostream>

/*
 * Why "using namespace std;" (using directive) is usually avoided.
 *
 * The C++ standard library lives in the std namespace (e.g., std::cout). 
 * This prevents name collisions with your own identifiers or with other libraries.
 *
 * A global "using namespace std;" pulls every name from std into the global namespace. 
 * In larger projects, that increases the chance of ambiguous references and accidental collisions, especially when multiple libraries
 * define similarly named functions or types.
 *
 * Prefer qualifying with std:: (most explicit), or bring in only the specific names you need with a using declaration (more limited scope, lower risk),
 * ideally in the smallest scope that makes sense.
 */

// Bringing in a single name (using declaration) is far safer than "using namespace std; (using directive)"
using std::cout;

int main () {
    cout << "Hello World\n";
    return 0;
}