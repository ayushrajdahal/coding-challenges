// Level Order Traversal of Binary Tree

// Given a binary tree root, return the level order traversal of it as a nested list, where each sublist contains the values of nodes at a particular level in the tree, from left to right.

// Example 1:

// Input: root = [1,2,3,4,5,6,7]

// Output: [[1],[2,3],[4,5,6,7]]
// Example 2:

// Input: root = [1]

// Output: [[1]]
// Example 3:

// Input: root = []

// Output: []
// Constraints:

// 0 <= The number of nodes in both trees <= 1000.
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> all_levels;
        deque<TreeNode *> q;

        if (root)
            q.push_back(root); // only push if root exists

        while (!q.empty())
        {
            vector<int> curr_level;

            for (int i = 0, len = q.size(); i < len; i++)
            {
                TreeNode *curr_node = q.front();
                q.pop_front();
                curr_level.push_back(curr_node->val);

                if (curr_node->left)
                {
                    q.push_back(curr_node->left);
                }
                if (curr_node->right)
                {
                    q.push_back(curr_node->right);
                }
            }
            all_levels.push_back(curr_level);
        }
        return all_levels;
    }
};
