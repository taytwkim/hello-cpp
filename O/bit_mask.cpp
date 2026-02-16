// Chapter O: Bit Masks
// Date: 2025-01-14
// Bit masks
// Compile: clang++ bit_mask.cpp -o mask

#include <bitset>
#include <iostream>

/* Bit masks */
void example1()
{
    std::cout << "Example 1\n";

    [[maybe_unused]] constexpr std::uint8_t mask0{0b0000'0001};  // mask for bit 0
    [[maybe_unused]] constexpr std::uint8_t mask1{0b0000'0010};
    [[maybe_unused]] constexpr std::uint8_t mask2{0b0000'0100};
    [[maybe_unused]] constexpr std::uint8_t mask3{0b0000'1000};
    [[maybe_unused]] constexpr std::uint8_t mask4{0b0001'0000};
    [[maybe_unused]] constexpr std::uint8_t mask5{0b0010'0000};
    [[maybe_unused]] constexpr std::uint8_t mask6{0b0100'0000};
    [[maybe_unused]] constexpr std::uint8_t mask7{0b1000'0000};

    std::uint8_t flags{0b0000'0000};

    // check that the bit is on/off
    std::cout << "bit 0 is " << (static_cast<bool>(flags & mask0) ? "on" : "off") << '\n';
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on" : "off") << '\n';

    // set bit using bitwise OR
    flags |= mask1;  // turn on bit 1
    std::cout << "turn on bit 1: bit 1 is " << (static_cast<bool>(flags & mask1) ? "on" : "off")
              << '\n';

    // clear bit using bitwise AND and NOT
    flags &= ~mask2;  // clear bit 2
    std::cout << "clear bit 2: bit 2 is " << (static_cast<bool>(flags & mask2) ? "on" : "off")
              << '\n';

    // flip bit using bitwise XOR
    flags ^= mask2;  // flip bit 2
    std::cout << "flip bit 2: bit 2 is " << (static_cast<bool>(flags & mask2) ? "on" : "off")
              << '\n';
}

/*
 * We can also use bit masks on bit sets.
 * While bit sets provide built-in functions to manipulate individual bits, bit masks can be helpful
 * when manipulating multiple bits.
 */
void example2()
{
    std::cout << "Example 2\n";

    [[maybe_unused]] constexpr std::bitset<8> mask0{0b0000'0001};
    [[maybe_unused]] constexpr std::bitset<8> mask1{0b0000'0010};
    [[maybe_unused]] constexpr std::bitset<8> mask2{0b0000'0100};
    [[maybe_unused]] constexpr std::bitset<8> mask3{0b0000'1000};
    [[maybe_unused]] constexpr std::bitset<8> mask4{0b0001'0000};
    [[maybe_unused]] constexpr std::bitset<8> mask5{0b0010'0000};
    [[maybe_unused]] constexpr std::bitset<8> mask6{0b0100'0000};
    [[maybe_unused]] constexpr std::bitset<8> mask7{0b1000'0000};

    std::bitset<8> flags{0b0000'0000};

    std::cout << "bit 1 is " << (flags.test(1) ? "on" : "off") << '\n';
    std::cout << "bit 2 is " << (flags.test(2) ? "on" : "off") << '\n';

    flags ^= (mask1 | mask2);  // flip bits 1 and 2
    std::cout << "bit 1 is " << (flags.test(1) ? "on" : "off") << '\n';
    std::cout << "bit 2 is " << (flags.test(2) ? "on" : "off") << '\n';

    flags |= (mask1 | mask2);  // turn bits 1 and 2 on
    std::cout << "bit 1 is " << (flags.test(1) ? "on" : "off") << '\n';
    std::cout << "bit 2 is " << (flags.test(2) ? "on" : "off") << '\n';

    flags &= ~(mask1 | mask2);  // turn bits 1 and 2 off
    std::cout << "bit 1 is " << (flags.test(1) ? "on" : "off") << '\n';
    std::cout << "bit 2 is " << (flags.test(2) ? "on" : "off") << '\n';
}

/* Best practice for using a bitmask: give meaningful names */
void example3()
{
    std::cout << "Example 3\n";

    [[maybe_unused]] constexpr std::uint8_t isHappy{0b0000'0001};
    [[maybe_unused]] constexpr std::uint8_t isSad{0b0000'0010};
    [[maybe_unused]] constexpr std::uint8_t isHungry{0b0000'0100};
    [[maybe_unused]] constexpr std::uint8_t isTired{0b0000'1000};
    [[maybe_unused]] constexpr std::uint8_t isSick{0b0001'0000};
    [[maybe_unused]] constexpr std::uint8_t isAlive{0b0010'0000};
    [[maybe_unused]] constexpr std::uint8_t isBlue{0b0100'0000};
    [[maybe_unused]] constexpr std::uint8_t isRed{0b1000'0000};

    std::uint8_t flags{0b0000'0000};
    std::cout << std::boolalpha;
    std::cout << "Is Happy?: " << (static_cast<bool>(flags & isHappy)) << '\n';
}

int main()
{
    example1();
    example2();
    example3();

    return 0;
}