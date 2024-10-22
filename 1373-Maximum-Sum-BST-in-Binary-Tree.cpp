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
    // Helper function to store subtree information
    struct NodeValue {
        int minNode, maxNode, sum;
        bool isBST;
        
        NodeValue(int minNode, int maxNode, int sum, bool isBST) 
            : minNode(minNode), maxNode(maxNode), sum(sum), isBST(isBST) {}
    };

    int maxSum = 0;

    // Helper function to perform post-order traversal and find the maximum sum BST
    NodeValue maxSumBSTHelper(TreeNode* root) {
        // An empty tree is a BST with sum 0
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0, true);

        // Get values from the left and right subtree
        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);

        // Check if the current tree rooted at 'root' is a BST
        if (left.isBST && right.isBST && root->val > left.maxNode && root->val < right.minNode) {
            // It's a valid BST, calculate the sum of the subtree
            int currentSum = root->val + left.sum + right.sum;

            // Update the maximum sum
            maxSum = max(maxSum, currentSum);

            // Return the new values for this subtree
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), currentSum, true);
        }

        // If it's not a BST, return invalid values
        return NodeValue(INT_MIN, INT_MAX, 0, false);
    }

    // Main function to calculate the maximum sum BST in the tree
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return maxSum;
    }
};
