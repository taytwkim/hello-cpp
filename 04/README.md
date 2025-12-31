# Fundamental Data Types

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

### `-t` Suffix

In newer versions of C++, types use the `_t` suffix (e.g., `std::nullptr_t`). So just think of it as a data type.

### `sizeof` Operator

C++ only guarantees that integers will have a certain minimum size, not that they will have a specific size.

We can use the `sizeof` operator to find the size of each type (can vary by machine).

### Signed Integers

By default, integers in C++ are signed, which means the sign is stored as part of the value. Therefore, a signed integer can hold both positive and negative numbers (and 0).

Because one bit is used to indicate sign, the values that can be represented by an n-bit signed integer will be `-2^(n-1) ~ 2^(n-1)`.

Assigning values that are not covered in this range is called an overflow and will result in undefined behavior.
