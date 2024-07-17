// Number of One Bits

// You are given an unsigned integer n. Return the number of 1 bits in its binary representation.

// Example 1:

// Input: n = 00000000000000000000000000010111

// Output: 4
// Example 2:

// Input: n = 01111111111111111111111111111101

// Output: 30

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int total_bits = 0;
        while (n)
        {
            total_bits += n & 1;
            n = n >> 1;
        }
        return total_bits;
    }
};
