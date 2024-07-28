// Valid Binary Search Tree

// Given the root of a binary tree, return true if it is a valid binary search tree, otherwise return false.

// A valid binary search tree satisfies the following constraints:

// The left subtree of every node contains only nodes with keys less than the node's key.
// The right subtree of every node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees are also binary search trees.
// Example 1:

// Input: root = [2,1,3]

// Output: true
// Example 2:

// Input: root = [1,2,3]

// Output: false
// Explanation: The root node's value is 1 but its left child's value is 2 which is greater than 1.

// Constraints:

// 1 <= The number of nodes in the tree <= 1000.
// -1000 <= Node.val <= 1000

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
    bool isValidBST(TreeNode *root)
    {
        // LONG_MIN: minimum possible value for type long, same for LONG_MAX
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBST(TreeNode *node, long min, long max)
    {
        // if the node is null it's a valid tree
        if (!node)
            return true;

        // checks if the node value is outside bounds, if so returns false
        if (node->val <= min || node->val >= max)
            return false;

        // node val passed as max for the left subtree and min for the right; the other parameter is same as the one passed to the node
        return isValidBST(node->left, min, node->val) && isValidBST(node->right, node->val, max);
    }
};
