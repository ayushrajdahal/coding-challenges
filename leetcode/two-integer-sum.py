# Two Integer Sum
# Solved 
# Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.

# You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

# Return the answer with the smaller index first.

# Example 1:

# Input: 
# nums = [3,4,5,6], target = 7

# Output: [0,1]
# Explanation: nums[0] + nums[1] == 7, so we return [0, 1].

# Example 2:

# Input: nums = [4,5,6], target = 10

# Output: [0,2]
# Example 3:

# Input: nums = [5,5], target = 10

# Output: [0,1]
# Constraints:

# 2 <= nums.length <= 1000
# -10000 <= nums[i] <= 10000
# -10000 <= target <= 10000

# O(n)
def twoSum(self, nums: List[int], target: int) -> List[int]:
    prevMap = {}
    # NEW: this accomplishes the task in O(n) complexity by considering the remaining value we get after subtracting input from the target.
    for index, val in enumerate(nums):
        rem = target - val
        if rem in prevMap:
            # return [prevMap[rem], val] # mistake: returned value instead of index
            return [prevMap[rem], index]
        prevMap[val] = index


# O(n^2)
def twoSum2(self, nums: List[int], target: int) -> List[int]:
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i,j]