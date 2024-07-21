// Binary Tree Diameter

// The diameter of a binary tree is defined as the length of the longest path between any two nodes within the tree. The path does not necessarily have to pass through the root.

// The length of a path between two nodes in a binary tree is the number of edges between the nodes.

// Given the root of a binary tree root, return the diameter of the tree.

// Example 1:

// Input: root = [1,null,2,3,4,5]

// Output: 3
// Explanation: 3 is the length of the path [1,2,3,5] or [5,3,2,4].

// Example 2:

// Input: root = [1,2,3]

// Output: 2
// Constraints:

// 1 <= number of nodes in the tree <= 100
// -100 <= Node.val <= 100

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        // base case
        int res = 0;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode *node, int &res)
    { // MODIFIED: int& res added
        if (!node)
        { // MODDIFIED: this is node, not root
            return 0;
        }

        int left = dfs(node->left, res);
        int right = dfs(node->right, res);

        res = max(res, left + right);

        return 1 + max(left, right);
    }
};
