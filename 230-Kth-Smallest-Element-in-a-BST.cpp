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
     void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
        if (!node || counter >= k) return;

        // Traverse left subtree
        inorder(node->left, counter, k, kSmallest);

        // Increment counter after visiting left subtree
        counter++;

        // Check if current node is the Kth smallest
        if (counter == k) {
            kSmallest = node->val;
            return;
        }

        // Traverse right subtree if
        // Kth smallest is not found yet
        inorder(node->right, counter, k, kSmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kSmallest = -1;
        // Counter to track visited nodes
        int counter = 0; 

        // Find Kth smallest element
        // (perform inorder traversal)
        inorder(root, counter, k, kSmallest);
        return kSmallest;
        
    }
};