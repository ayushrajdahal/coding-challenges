// Counting Bits

// Given an integer n, count the number of 1's in the binary representation of every number in the range [0, n].

// Return an array output where output[i] is the number of 1's in the binary representation of i.

// Example 1:

// Input: n = 4

// Output: [0,1,1,2,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100

// Constraints:

// 0 <= n <= 1000

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> bit_list(n + 1); // MODIFIED: predefined size of n+1 (incl zero and n itself)
        for (int i = 0; i < n + 1; i++)
        {                               // MODIFIED: include n as well
            bit_list[i] = getBitNum(i); // MODIFIED: since we have predefined size, we can just use indexing; otherwise, we'd be using .push_back()
        }
        return bit_list;
    }

    int getBitNum(int n)
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
