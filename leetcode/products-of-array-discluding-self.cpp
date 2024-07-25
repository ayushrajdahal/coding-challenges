// Products of Array Discluding Self

// Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

// Each product is guaranteed to fit in a 32-bit integer.

// Follow-up: Could you solve it in
// 𝑂
// (
// 𝑛
// )
// O(n) time without using the division operation?

// Example 1:

// Input: nums = [1,2,4,6]

// Output: [48,24,12,8]
// Example 2:

// Input: nums = [-1,0,1,2,3]

// Output: [0,-6,0,0,0]
// Constraints:

// 2 <= nums.length <= 1000
// -20 <= nums[i] <= 20

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> postfix(n, 1);

        int pre_prod = 1;
        int post_prod = 1;

        for (int i = 0; i < n; i++)
        {
            prefix[i] = pre_prod;
            pre_prod *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
            class Solution
            {
            public:
                vector<int> productExceptSelf(vector<int> &nums)
                {
                    int n = nums.size();
                    vector<int> prefix(n, 1);
                    vector<int> postfix(n, 1);

                    int pre_prod = 1;
                    int post_prod = 1;

                    for (int i = 0; i < n; i++)
                    {
                        prefix[i] = pre_prod;
                        pre_prod *= nums[i];
                    }

                    // note: reversed traversal; decrement i
                    for (int i = n - 1; i >= 0; i--)
                    {
                        postfix[i] = post_prod;
                        post_prod *= nums[i];
                    }

                    vector<int> result(n);

                    for (int i = 0; i < n; i++)
                    {
                        result[i] = prefix[i] * postfix[i];
                    }

                    return result;
                }
            };

        {
            postfix[i] = post_prod;
            post_prod *= nums[i];
        }

        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            result[i] = prefix[i] * postfix[i];
        }

        return result;
    }
};
