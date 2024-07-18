// Sum of Two Integers

// Given two integers a and b, return the sum of the two integers without using the + and - operators.

// Example 1:

// Input: a = 1, b = 1

// Output: 2
// Example 2:

// Input: a = 4, b = 7

// Output: 11
// Constraints:

// -1000 <= a, b <= 1000

class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b)
        {
            int tmp = (a & b) << 1; // MODIFIED: brackets necessary to ensure bit shifting in result of a+b, and not on just b.
            a = a ^ b;
            b = tmp;
        }
        return a;
    }
};
