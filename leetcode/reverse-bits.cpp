// Reverse Bits

// Given a 32-bit unsigned integer n, reverse the bits of the binary representation of n and return the result.

// Example 1:

// Input: n = 00000000000000000000000000010101

// Output:    2818572288 (10101000000000000000000000000000)
// Explanation: Reversing 00000000000000000000000000010101, which represents the unsigned integer 21, gives us 10101000000000000000000000000000 which represents the unsigned integer 2818572288.

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t rev = 0; // MODIFIED: use int32_t instead of int
        for (int i = 0; i < 32; i++)
        {
            rev = (rev << 1) | (n & 1);
            n = n >> 1;
        }
        return rev;
    }
};
