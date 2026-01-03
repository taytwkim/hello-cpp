# Fixed-width Integers and `size_t`

I personally find fixed-width integers and `size_t` to be confusing, so I think they deserve some explanation.

## Fixed-width Integers

First of all, it is important to remember that **C++ only guarantees that integer variables will have a minumum size**, but they could be larger depending on the target system.

For example, an `int` has a minimum size of 16-bits, but it’s typically 32-bits on modern architectures. 

But some systems may still rely on 16-bit `int`. So if we write a program assuming that `int` is 32-bits, it may fail in systems where `int` is not 32-bits.

```cpp
#include <iostream>

int main()
{
    int x { 32767 };          // x may be 16-bits or 32-bits
    x = x + 1;                // 32768 overflows if int is 16-bits, okay if int is 32-bits
    std::cout << x << '\n';

    return 0;
}
```

To address the above issues, C++11 provides an alternate set of integer types that are guaranteed to be the same size on any architecture. 

Because the size of these integers is fixed, they are called fixed-width integers.

* `std::int8_t`
* `std::uint8_t`
* `std::int16_t`
* `std::uint16_t`
* `std::int32_t`
* `std::uint32_t`
* `std::int64_t`
* `std::uint64_t`

The fixed-width integers are defined in the `<cstdint>` header.

```cpp
#include <cstdint> // for fixed-width integers
#include <iostream>

int main()
{
    std::int32_t x { 32767 };   // x is always a 32-bit integer
    x = x + 1;                  // so 32768 will always fit
    std::cout << x << '\n';

    return 0;
}
```

The fixed-width integers don’t define new types — they’re aliases for existing types with the required size.

So `std::int32_t` is an alias for some existing type that is exactly 4 bytes on that platform. That underlying type could be `int`, `long`, or something else. `std::int32_t` is really just saying: "use whatever type that is 4 bytes."

Same idea for`std::int8_t`: since char-sized types are usually 8-bits, `std::int8_t`/`std::uint8_t` often end up as aliases of `signed char`/`unsigned char`, which is why they can behave like `char`.

Also, if we use `std::int32_t` but the **platform doesn’t have any integer type that’s exactly 32-bits wide**, our code won’t compile.

## Fast and Least Integral Types

### Fast Types

Systems might be faster at processing 64-bit integers than 32-bit integers (The CPU is optimized to process certain sizes faster).

`std::int_fast32_t` will give you the fastest signed integer type that’s *at least* 32-bits.

### Least Types

The least types provide the smallest signed/unsigned integer type with a width of at least # bits.

For example, `std::uint_least32_t` will give you the smallest unsigned integer type that’s at least 32-bits.

This can help avoid the problem discussed above where a 32-bit type may not already exist in the system.

## `std::size_t`

`std::size_t` stores the size of objects. In a 64-bit machine, `sizeof(size_t)` is 8 bytes.

The `sizeof` operator returns a `size_t`. `size_t` is defined in `<cstddef>`.

```cpp
#include <cstddef>    // for std::size_t
#include <iostream>

int main()
{
    int x { 5 };
    std::size_t s { sizeof(x) }; // sizeof returns a value of type std::size_t, so that should be the type of s
    std::cout << s << '\n';

    return 0;
}
```

The `sizeof` operator must be able to return the byte-size of an object as a value of type `std::size_t`. 

Therefore, the byte-size of an object can be no larger than the largest value `std::size_t` can hold.

In other words, no object larger than the upper limit imposed by `std::size_t` can be created.