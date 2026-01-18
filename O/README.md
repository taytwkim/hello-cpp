# Chapter O (Optional): Bit Manipulation

* `bitset.cpp`: Bit flags and bit manipulation via `std::bitset`
* `bit_ops.cpp`: Bitwise operators
* `bit_mask.cpp`: Bit masks

## Two's Complement

Two's complement is a way of expressing signed integers in computer systems. To understand why its called "two's complement", let's start by discussing one's complement.

### One's Complement

In one’s complement, a negative value is represented by **bitwise-inverting** (flipping) the bits of the corresponding positive value. 

The name comes from the fact that a number plus its one’s complement sums to **all 1s** (within a fixed bit-width).

For example (3-bit):
- `011` represents **+3**
- Its one’s-complement negation is `100`, which represents **−3**

The left-most bit acts as a **sign bit**: `0` for non-negative values, `1` for negative values.

A quirk of one’s complement is that it has **two zeros**:
- `000` is **+0**
- `111` is **−0**

With 3 bits, one’s complement represents values from **−3 to +3**, plus the two zeros:
- Positives: `+1, +2, +3`
- Negatives: `−1, −2, −3`
- Zeros: `+0` and `−0`

### Two's Complement

In two’s complement, a negative value is represented by **bitwise-inverting** the bits of the corresponding positive value, then **adding 1** (within a fixed bit-width).

For example (3-bit):
- `011` represents **+3**
- Its two’s-complement negation is `101`, which represents **−3**

A key property is that adding a number and its two’s complement gives **1 followed by all zeros** in `n+1` bits:
- the lower n bits become `000...0`
- there is a carry-out of `1` (which is typically discarded in n-bit arithmetic)

Unlike one’s complement, two’s complement has **only one zero**. If you negate `000`:
- flip → `111`
- add 1 → `1 000` (overflow)
- stored n bits → `000`

With 3 bits, two’s complement represents values from **−4 to +3**. There is one more negative value because the pattern `100` is **−4** (and `111` is **−1**, not “−0”):
- Positives: `+1, +2, +3`
- Negatives: `−1, −2, −3, −4`
- Zero: `0`

To interpret an n-bit two’s-complement value:
- If the leading bit is `0`, convert as ordinary unsigned binary.
- If the leading bit is `1`, take the two’s complement (flip bits, add 1) to get the magnitude, then apply a negative sign.