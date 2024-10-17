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
    void inorder(TreeNode* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->val);
    // Recursively traverse 
    // the right subtree
    inorder(root->right, arr);
}

    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> arr;
    // Call the preorder traversal function
         inorder(root, arr);
    // Return the resulting vector
    // containing preorder traversal values
        return arr;
    }
};