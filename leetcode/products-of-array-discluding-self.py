# Products of Array Discluding Self

# Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].
# Each product is guaranteed to fit in a 32-bit integer.
# Follow-up: Could you solve it in O(n) time without using the division operation?

# Example 1:

# Input: nums = [1,2,4,6]

# Output: [48,24,12,8]

# Example 2:

# Input: nums = [-1,0,1,2,3]

# Output: [0,-6,0,0,0]
# Constraints:

# 2 <= nums.length <= 1000
# -20 <= nums[i] <= 20


from typing import List

def productExceptSelf(self, nums: List[int]) -> List[int]:
    len_nums = len(nums)
    out = [1] * len_nums

    for i in range(len_nums-1):
        out[i+1] *= out[i] * nums[i]

    post = 1

    for i in range(len_nums-1, 0, -1): # MODIFIED: changed to len_nums - 1 from len_nums because out of bouds
        post *= nums[i]
        out[i-1] *= post

    return out