// Non-Cyclical Number

// A non-cyclical number is an integer defined by the following algorithm:

// Given a positive integer, replace it with the sum of the squares of its digits.
// Repeat the above step until the number equals 1, or it loops infinitely in a cycle which does not include 1.
// If it stops at 1, then the number is a non-cyclical number.
// Given a positive integer n, return true if it is a non-cyclical number, otherwise return false.

// Example 1:

// Input: n = 100

// Output: true
// Explanation: 1^2 + 0^2 + 0^2 = 1

// Example 2:

// Input: n = 101

// Output: false
// Explanation:
// 1^2 + 0^2 + 1^2 = 2
// 2^2 = 4
// 4^2 = 16
// 1^2 + 6^2 = 37
// 3^2 + 7^2 = 58
// 5^2 + 8^2 = 89
// 8^2 + 9^2 = 145
// 1^2 + 4^2 + 5^2 = 42
// 4^2 + 2^2 = 20
// 2^2 + 0^2 = 4 (This number has already been seen)

// Constraints:

// 1 <= n <= 1000

class Solution
{
public:
    int sumSquare(int num)
    {
        int sum_square = 0;
        while (num)
        {
            sum_square += pow(num % 10, 2);
            num = (int)num / 10;
        }
        return sum_square;
    }
    bool isHappy(int n)
    {
        unordered_set<int> seen; // MODIFIED: set used instead of copy var containing original n
        while (n != 1)
        {
            if (seen.find(n) != seen.end())
            {
                return false;
            }
            seen.insert(n);
            n = sumSquare(n);
        }
        return true;
    }
};
