// Kth Smallest Integer in BST

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) in the tree.

// A binary search tree satisfies the following constraints:

// The left subtree of every node contains only nodes with keys less than the node's key.
// The right subtree of every node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees are also binary search trees.
// Example 1:



// Input: root = [2,1,3], k = 1

// Output: 1
// Example 2:



// Input: root = [4,3,5,2,null], k = 4

// Output: 5
// Constraints:

// 1 <= k <= The number of nodes in the tree <= 1000.
// 0 <= Node.val <= 1000

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

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrder = bringInOrder(root);
        
        return inOrder[k-1]; // since this is zero-indexed and we want one-indexed
    }

private:
    vector<int> bringInOrder(TreeNode* root) {
        
        // stores the values as we perform in-order traversal through the tree
        vector<int> result;

        // if the root is null it just returns an empty vector
        if (!root) {
            return result;
        }
        
        // recursive call: this fetches the left subtree, stores it in a vector, and inserts that vector into result.
        vector<int> leftSubTree = bringInOrder(root->left);
        // push_back would've required us to do a for loop through the returned elements. here we are simply appending.
        result.insert(result.end(), leftSubTree.begin(), leftSubTree.end());
        
        // only pushes if the root exists
        if (root) result.push_back(root->val);
        
        // similar logic for the right subtree
        vector<int> rightSubTree = bringInOrder(root->right);
        result.insert(result.end(), rightSubTree.begin(), rightSubTree.end());

        //returns the vector after all operations.
        return result;
    }
};
