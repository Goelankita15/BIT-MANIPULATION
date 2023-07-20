https://cp-algorithms.com/algebra/bit-manipulation.html

has_single_bit: checks if the number is a power of two
bit_ceil / bit_floor: round up/down to the next power of two
rotl / rotr: rotate the bits in the number
countl_zero / countr_zero / countl_one / countr_one: count the leading/trailing zeros/ones
popcount: count the number of set bits
Additionally, there are also predefined functions in some compilers that help working with bits. E.g. GCC defines a list at Built-in Functions Provided by GCC that also work in older versions of C++:

__builtin_popcount(unsigned int) returns the number of set bits (__builtin_popcount(0b0001'0010'1100) == 4)
__builtin_ffs(int) finds the index of the first (most right) set bit (__builtin_ffs(0b0001'0010'1100) == 3)
__builtin_clz(unsigned int) the count of leading zeros (__builtin_clz(0b0001'0010'1100) == 23)
__builtin_ctz(unsigned int) the count of trailing zeros (__builtin_ctz(0b0001'0010'1100) == 2)
----------------------------------------------------------------------------------------------
Check if a number (X) is odd or even

X & 1 = 0 means X is an even number
X & 1 = 1 means X is an odd number
-----------------------------------------------
Check if a number (X) is a power of 2

X & (X - 1) = 0 means X is a power of 2
X & (X - 1) > 0 means X is not a power of 2
----------------------------------------------------
Check if the kth bit in a number (X) is set or unset

(X >> k) & 1 = 0 means kth bit is unset
(X >> k) & 1 = 1 means kth bit is set

Some more cool tricks:
X xor (1 << k) toggles the kth bit
X | (1 << k) sets the kth bit
X & ~(1<<k) unsets the kth bit
-------------------------------------------
  If number of set bits in A = X, and number of set bits in B = Y, then number of set bits in (A xor B) is even if (X + Y) is even and odd if (X + Y) is odd.
--------------------------------------------------
Find out the remainder of a number (X) when divided by 2^k

X & ((1 << k) - 1) will give the remainder

Explanation: 
(1 << k) = 10000... (k bits)
(1 << k) - 1 = 0111111... (k bits)
Clearly, when you do X & ((1 << k) - 1) this will return the set bits in X before the kth bit.
---------------------------------------------------
 Finding number of set bits in a number (X)

__builtin_popcount(X) if X is an integer
__builtin_popcountll(X) if X is a long long

This function returns the number of set bits in O(1). Yes, you heard that right O(1) but this is only available in C++.
--------------------------------------------------------
Two important Identities:

A + B = (A xor B) + 2 * (A & B)
A + B = (A | B) + (A & B)
--------------------------------------------------------
Clear all the trailing ones in a number (X)

X & (X + 1) will give a number where all the trailing ones of X will be changed to zeros.

Example: 
X = 1011011, X + 1 = 1011100
X & (X + 1) = 1011000
---------------------------------------
Multiple and divide a number (X) by 2^k 

(X << k) gives X multiplied by (2^k)
(X >> k) gives X divided by (2^k)
---------------------------------------------------
Swap two numbers (X) and (Y) without a temporary variable

X = X xor Y
Y = X xor Y
X = X xor Y
---------------------------------------------------------
Have you come across something like:
If (X == A) 
   X = B
else
   X = A

You can do this in one step with this:
X = A xor B xor X
