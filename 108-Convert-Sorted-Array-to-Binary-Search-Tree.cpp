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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    
    // Helper function to recursively build the tree
    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        // Find the middle element and create a node
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left and right subtrees
        root->left = build(nums, start, mid - 1);
        root->right = build(nums, mid + 1, end);

        return root;
    }
};