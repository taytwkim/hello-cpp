# Chapter 4: Fundamental Data Types

## Code
* `type.cpp`: The `typeof` operator.
* `size.cpp`: Fixed-width integers (e.g., `std::int8_t`) and `size_t`.
* `float.cpp`: Floating point numbers.
* `bool.cpp`: Printing boolean values to `std::cout`.
* `cast.cpp`: Type conversions.

## Notes

### Memory Address

In modern computers, each memory address holds 1 byte of data. So each byte (not each bit) gets its own memory address.

```
...

Address 2 -> 00000000
Address 1 -> 10010111
Address 0 -> 01101001
```

### Data Types

Data types are important because at the end of the day, everything stored in a computer is a sequence of bits.

The data type indicates how the compiler should interpret these bits. 

Based on the type, the compiler knows the object size, and can read the needed number of bytes to retrieve or write data.

### Integral Data Types

Integral data types mean data types that behave like integers.

The standard integer types are `short`, `int`, `long`, `long long` (including their signed and unsigned variants).

The integral types are `bool`, the various `char` types, and the standard integer types.

All integral types are stored in memory as integer values, but only the standard integer types will display as an integer value when output.

### `-t` Suffix

In newer versions of C++, types use the `_t` suffix (e.g., `std::nullptr_t`). So just think of it as being a type.

### `sizeof` Operator

C++ only guarantees that integers will have a certain minimum size, not that they will have a specific size.

We can use the `sizeof` operator to find the actual size of each type (can vary by machine).

### Signed Integers

By default, integers in C++ are signed, which means the sign is stored as part of the value. Therefore, a signed integer can hold both positive and negative numbers (and 0).

Because one bit is used to indicate sign, the values that can be represented by an n-bit signed integer will be `-(2^(n-1)) ~ (2^(n-1))-1`.

Assigning values that are not covered in this range is called an overflow and will result in undefined behavior.

### Unsigned Integers

Unsigned integers are integers that can only hold non-negative whole numbers.

We can use the `unsigned` keyword to define an unsigned integer.

An n-bit unsigned variable has a range of `0 to 2^n-1`.

Like signed integers, assigning values out of range can lead to an overflow.

An unsigned integer will "wrap around" (e.g., 280 wil wrap around and become 24, since 280 % 256 = 24).

Generally speaking, unsigned integers should be avoided because they are more error prone. 

However, they may be helpful in special use cases like bit manipulation, encryption, and so on.

### Float and Double

In most machines, `float` is 4 bytes and `double` is 8 bytes.

`double` is generally preferred over `float` as it has higher precision.

Be careful when comparing floating point numbers - there can be precision issues (e.g., adding 0.1 ten times might result in 0.999... instead of 1).

### `inf` and `nan`

`inf` represents infinity, `nan` means "not a number".

`inf` is signed and can be either positive or negative.

### Implicit and Explicit Type Conversions

Sometimes, the compiler will implicitly convert types on our behalf. The compiler might generate a warning.

We can also explicitly convert types using the `static_cast` operator.

```
static_cast<new_type>(expression)
```