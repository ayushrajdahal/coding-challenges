# Top K Elements in List
# Solved 
# Given an integer array nums and an integer k, return the k most frequent elements within the array.

# The test cases are generated such that the answer is always unique.

# You may return the output in any order.

# Example 1:

# Input: nums = [1,2,2,3,3,3], k = 2

# Output: [2,3]
# Example 2:

# Input: nums = [7,7], k = 1

# Output: [7]
# Constraints:

# 1 <= nums.length <= 10^4.
# -1000 <= nums[i] <= 1000
# 1 <= k <= number of distinct elements in nums.

import heapq
from typing import Counter, List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_counts = [(-count, num) for num,count in Counter(nums).items()] # MISTAKE: used -num instead of -count; we need to heapify acc to the counts.
        
        heapq.heapify(num_counts)

        top_k = []

        for _ in range(k):
            top_k.append(heapq.heappop(num_counts)[1])
        
        return top_k
    
    def topKFrequent2(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)

        heap = heapq.nlargest(k, count.keys(), key=count.get)

        return heap