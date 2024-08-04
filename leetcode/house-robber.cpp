// House Robber

// You are given an integer array nums where nums[i] represents the amount of money the ith house has. The houses are arranged in a straight line, i.e. the ith house is the neighbor of the (i-1)th and (i+1)th house.

// You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically alert the police if two adjacent houses were both broken into.

// Return the maximum amount of money you can rob without alerting the police.

// Example 1:

// Input: nums = [1,1,3,3]

// Output: 4
// Explanation: nums[0] + nums[2] = 1 + 3 = 4.

// Example 2:

// Input: nums = [2,9,8,3,6]

// Output: 16
// Explanation: nums[0] + nums[2] + nums[4] = 2 + 8 + 6 = 16.

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // these two variables store maximum possible money that can be robbed from the last two houses
        int maxRob1 = 0, maxRob2 = 0;

        // interate through the whole list, calculate the max possible robbery for each index and
        // only store the last two since that's all we'll need to calculate the next max

        for (int n : nums)
        {
            temp = max(maxRob1 + n, maxRob2);
            maxRob1 = maxRob2;
            maxRob2 = temp;
        }

        // this stores the max robbery value for the last element in the list
        return maxRob2
    }
};
