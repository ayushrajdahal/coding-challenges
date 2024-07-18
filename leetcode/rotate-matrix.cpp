// Rotate Matrix

// Given a square n x n matrix of integers matrix, rotate it by 90 degrees clockwise.

// You must rotate the matrix in-place. Do not allocate another 2D matrix and do the rotation.

// Example 1:

// Input: matrix = [
//   [1,2],
//   [3,4]
// ]

// Output: [
//   [3,1],
//   [4,2]
// ]
// Example 2:

// Input: matrix = [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ]

// Output: [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]
// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int left = 0;
        int right = matrix.size() - 1;

        while (left < right)
        {
            for (int i = 0; i < right - left; i++)
            {
                int top = left;
                int bottom = right;
                int topLeft = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = topLeft;
            }
            right -= 1;
            left += 1;
        }
    }
};
