// Chapter O: Bit Manipulation
// Date: 2025-01-12
// Comma 
// Compile: clang++ bitset.cpp -o bit

#include <iostream>
#include <bitset>

/* 
 * Why bitset could be useful.
 *
 * In modern computer architecture, every object is byte-addressable, which means the min size of an object is a byte.
 * This means that even a boolean (which is 1 bit), takes up a whole byte, which is fine in most cases but is technically a waste of 7 bits.
 * So in some usecases, it might be helpful to pack bits into a byte and manipulate the individual bits. This is where we we can use "std::bitset".
 * 
 * But note that the size of the bitset is rounded up to the size of size_t (64 bits in a 64-bit machine).
 * So a bitset of 8 bits does not mean we are using exactly 8 bits.
 */

int main()
{
    std::bitset<8> bits{ 0b0000'0101 };

    /*
     * bit position goes from right to left, so bit 0 is the rightmost bit.
     * 
     * test() allows us to query whether a bit is a 0 or 1.
     * set() allows us to turn a bit on (this will do nothing if the bit is already on).
     * reset() allows us to turn a bit off (this will do nothing if the bit is already off).
     * flip() allows us to flip a bit value from a 0 to a 1 or vice versa.
     * size() returns the number of bits in the bitset.
     * count() returns the number of bits in the bitset that are set to true.
     * all() returns a Boolean indicating whether all bits are set to true.
     * any() returns a Boolean indicating whether any bits are set to true.
     * none() returns a Boolean indicating whether no bits are set to true.
     */

    bits.set(3);        // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4);       // flip bit 4 (now we have 0001 1101)
    bits.reset(4);      // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << bits<< '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    std::bitset<8> new_bits { 0b0000'1101 };
    std::cout << "All the bits: " << new_bits<< '\n';
    std::cout << new_bits.size() << " bits are in the bitset\n";
    std::cout << new_bits.count() << " bits are set to true\n";

    std::cout << std::boolalpha;
    std::cout << "All bits are true: " << new_bits.all() << '\n';
    std::cout << "Some bits are true: " << new_bits.any() << '\n';
    std::cout << "No bits are true: " << new_bits.none() << '\n';

    return 0;
}