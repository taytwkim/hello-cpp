// Chapter O: Bit Manipulation
// Date: 2025-01-13
// Bitwise Operators
// Compile: clang++ bit_ops.cpp -o ops

#include <bitset>
#include <iostream>

int main() {
    int bin { 0b1010 };
    std::cout << bin << '\n';   // will print 10

    std::bitset<4> bs { 0b1010 };
    std::cout << bs << '\n';    // will print 1010

    /*
     * left shift	    x << n      the bits from x are shifted left by n positions, new bits are 0.
     * right shift	    x >> n	    the bits from x are shifted right by n positions, new bits are 0.
     * bitwise NOT	    ~x	        each bit from x is flipped.
     * bitwise AND	    x & y	    each bit is set when both corresponding bits in x and y are 1.
     * bitwise OR	    x | y	    each bit is set when either corresponding bit in x and y is 1.
     * bitwise XOR	    x ^ y	    each bit is set when the corresponding bits in x and y are different.
     * 
     * When using a bitset, be aware of how many bits we are using.
     * For instance, if we have a bitset of 8 bits and do "NOT 1010", 
     * we might expect the result to be 00000101, but it can be 11110101.
     */

    std::bitset<8> bs2 { 0b1010 };
    std::bitset<8> bs3 { 0b0101 };

    std::cout   << "Original: "         << bs2          << '\n'
                << "Left-shit by 1: "   << (bs2 << 1)   << '\n'
                << "Right-shift by 1: " << (bs2 >> 1)   << '\n'
                << "Bitwise NOT: "      << (~bs2)       << '\n' 
                << "Bitwise AND: "      << (bs2 & bs3)  << '\n'
                << "Bitwise OR: "       << (bs2 | bs3)  << '\n'
                << "Bitwise XOR: "      << (bs2 ^ bs3)  << '\n';
    
    return 0;
}