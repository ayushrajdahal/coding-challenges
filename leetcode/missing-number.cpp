// Missing Number

// Given an array nums containing n integers in the range [0, n] without any duplicates, return the single number in the range that is missing from nums.

// Follow-up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

// Example 1:

// Input: nums = [1,2,3]

// Output: 0
// Explanation: Since there are 3 numbers, the range is [0,3]. The missing number is 0 since it does not appear in nums.

// Example 2:

// Input: nums = [0,2]

// Output: 1
// Constraints:

// 1 <= nums.length <= 1000

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int res = 0;
        int numsize = nums.size();

        for (int i = 0; i < numsize + 1; i++)
        {
            res = res ^ i;
            if (i < numsize)
            {
                res = res ^ nums[i];
            }
        }
        return res;
    }
};