// Max Water Container

// You are given an integer array heights where heights[i] represents the height of the ith bar.

// You may choose any two bars to form a container. Return the maximum amount of water a container can store.

// Example 1:

// Input: height = [1,7,2,5,4,7,3,6]

// Output: 36
// Example 2:

// Input: height = [2,2,2]

// Output: 4
// Constraints:

// 2 <= height.length <= 1000
// 0 <= height[i] <= 1000

class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int max_area = 0;
        int l = 0;
        int r = heights.size() - 1;

        int curr_height, curr_width, curr_area;

        while (l < r)
        {
            curr_height = min(heights[l], heights[r]);
            curr_width = r - l;
            curr_area = curr_height * curr_width;
            max_area = max(curr_area, max_area);
            if (heights[l] < heights[r])
            {
                l++; // increment left pointer, not decrement
            }
            else
            {
                r--;
            }
        }
        return max_area;
    }
};
