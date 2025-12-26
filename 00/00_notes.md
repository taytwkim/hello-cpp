# Chapter 0: Introduction and Getting Started

## 1. Compiling Code

We can compile C++ from the command line with either Clang or GCC:

```bash
# clang
clang++ main.cpp -o main

# g++ (GCC)
g++ main.cpp -o main
```

`-o` sets the name of the output executable to `main`.

On macOS, Clang is the default compiler, so `clang++` is the normal choice. 

Also, on macOS, `g++` may actually invoke Clang (the `g++` command can just be a wrapper for Clang), so it might not be “real GCC.”

If we want actual GCC’s `g++`, we can install GCC separately (via Homebrew), and then use a versioned command like `g++-15` (or whatever version we installed).

## 2. Choosing a Language Standard

The ISO committee releases new C++ standards on a roughly 3-year cycle (C++14, C++17, C++20, C++23).

Since newer standards add new language/library features, it’s important to know which standard the compiler is using.

To choose a specific standard when compiling, use the `-std` flag (GCC/Clang):

```bash
clang++ -std=c++20 main.cpp -o main

g++ -std=c++20 main.cpp -o main
```

It’s often good practice to target a recent but widely supported standard, commonly the second-most-recent one, so you get modern features without running into compiler/library support issues.

## 3. Compiler Warnings and Debuggers

We can turn on compiler warnings with `-Wall` (and it’s common to also add `-Wextra`). While learning C++, it’s good practice to compile with warnings enabled.

```bash
clang++ -std=c++20 -Wall -Wextra -g main.cpp -o main

g++ -std=c++20 -Wall -Wextra -g main.cpp -o main
```

To include debug symbols for debugging, compile with `-g`.

On macOS, debug symbols may be stored inside the executable, or a separate `.dSYM/` bundle may be generated (depending on your toolchain/settings). 

The program still runs either way, but symbols help the LLDB debugger show source lines, variables, and stack traces.

```bash
lldb ./main
run
```

## 4. Configuring Compiler Extensions

While the C++ standard defines a common set of rules, compilers may also provide compiler-specific extensions.

These extensions can be useful, but they can also make code non-portable (it may fail to compile with other compilers) or behave differently than expected.

Extensions are often enabled by default. If portability is a priority, we can ask the compiler to be stricter about standard compliance.

In GCC or clang, we can use the `-pedantic` flag to get a warning when non-standard extension has been used.

* `-pedantic`: see warning when non-standard extensions have been used.
* `-pedantic-errors`: same, but treated as error instead of warning.