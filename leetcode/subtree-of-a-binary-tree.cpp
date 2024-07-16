// Subtree of a Binary Tree

// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

// Example 1:

// Input: root = [1,2,3,4,5], subRoot = [2,4,5]

// Output: true
// Example 2:

// Input: root = [1,2,3,4,5,null,null,6], subRoot = [2,4,5]

// Output: false
// Constraints:

// 0 <= The number of nodes in both trees <= 100.
// -100 <= root.val, subRoot.val <= 100

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
    bool isSametree(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }
        else if (root1 == nullptr || root2 == nullptr)
        {
            return false;
        }
        if (root1->val == root2->val)
        {
            return isSametree(root1->left, root2->left) && isSametree(root1->right, root2->right);
        }
        return false;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
        {
            return false;
        }
        else if (subRoot == nullptr)
        {
            return true;
        }

        if (isSametree(root, subRoot))
        {
            return true;
        }
        else
        {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }
};
