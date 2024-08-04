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
        int numsLen = nums.size();

        // base cases: in case length of the array passed is either 0 or 1
        if (numsLen == 0)
            return 0;
        if (numsLen == 1)
            return nums[0];

        // vector to store result for previously seen maxes
        vector<int> maxRobbery(numsLen, 0);

        // set the first two values
        maxRobbery[0] = nums[0];
        maxRobbery[1] = max(nums[0], nums[1]);

        // iterate through the rest of the values, assign it as the max of last seen value and sum of step-over and current value
        for (int i = 2; i < numsLen; i++)
        {
            maxRobbery[i] = max(maxRobbery[i - 1], maxRobbery[i - 2] + nums[i]);
        }

        // return the last element of vector
        return maxRobbery[numsLen - 1];
    }
};
