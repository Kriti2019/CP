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
    void findPaths(TreeNode* root, string currentPath, vector<string>& result) {
        if (root == NULL) return;  // Base case: if the node is null, return

        // Append the current node's value to the path
        if (currentPath.empty()) {
            currentPath = to_string(root->val);  // If this is the first node (root)
        } else {
            currentPath += \->\ + to_string(root->val);  // Append \->node_value\ format
        }

        // If it's a leaf node, add the current path to the result
        if (root->left == NULL && root->right == NULL) {
            result.push_back(currentPath);
        } else {
            // Otherwise, continue DFS on the left and right children
            findPaths(root->left, currentPath, result);
            findPaths(root->right, currentPath, result);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string> result;
        if (root == NULL) return result;  // If the root is NULL, return an empty result

        // Start the DFS traversal from the root
        findPaths(root, \\, result);

        return result;
        
    }
};