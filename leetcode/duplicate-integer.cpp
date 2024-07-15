// Duplicate Integer

// Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

// Example 1:

// Input: nums = [1, 2, 3, 3]

// Output: true
// Example 2:

// Input: nums = [1, 2, 3, 4]

// Output: false

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            if (seen.find(nums[i]) != seen.end())
            {
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};