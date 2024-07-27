// Find Target in Rotated Sorted Array
// You are given an array of length n which was originally sorted in ascending order. It has now been rotated between 1 and n times. For example, the array nums = [1,2,3,4,5,6] might become:

// [3,4,5,6,1,2] if it was rotated 4 times.
// [1,2,3,4,5,6] if it was rotated 6 times.
// Given the rotated sorted array nums and an integer target, return the index of target within nums, or -1 if it is not present.

// You may assume all elements in the sorted rotated array nums are unique,

// A solution that runs in O(n) time is trivial, can you write an algorithm that runs in O(log n) time?

// Example 1:

// Input: nums = [3,4,5,6,1,2], target = 1

// Output: 4
// Example 2:

// Input: nums = [3,5,6,0,1,2], target = 4

// Output: -1
// Constraints:

// 1 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// -1000 <= target <= 1000

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left <= right)
        { // changed from < to <=
            mid = (left + right) / 2;

            if (nums[mid] == target)
            { // don't use nums[target] since target isn't an index
                return mid;
            }

            if (nums[left] <= nums[mid])
            { // left side is sorted
                if (target < nums[mid] && target >= nums[left])
                {
                    right = mid - 1; // target is in the left portion
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            { // right side is sorted
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1; // target is in the right portion
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
