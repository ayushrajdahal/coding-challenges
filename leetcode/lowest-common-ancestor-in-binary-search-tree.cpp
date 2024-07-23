// Lowest Common Ancestor in Binary Search Tree

// Given a binary search tree (BST) where all node values are unique, and two nodes from the tree p and q, return the lowest common ancestor (LCA) of the two nodes.

// The lowest common ancestor between two nodes p and q is the lowest node in a tree T such that both p and q as descendants. The ancestor is allowed to be a descendant of itself.

// Example 1:

// Input: root = [5,3,8,1,4,7,9,null,2], p = 3, q = 8

// Output: 5
// Example 2:

// Input: root = [5,3,8,1,4,7,9,null,2], p = 3, q = 4

// Output: 3
// Explanation: The LCA of nodes 3 and 4 is 3, since a node can be a descendant of itself.

// Constraints:

// 2 <= The number of nodes in the tree <= 100.
// -100 <= Node.val <= 100
// p != q
// p and q will both exist in the BST.

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // base case
        if (root == nullptr)
        {
            return nullptr;
        }

        // if both nodes have values greater than root, call function by passing right as root

        if ((p->val > root->val) && (q->val > root->val))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if ((p->val < root->val) && (q->val < root->val)) // same for smaller values
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;
    }
};
