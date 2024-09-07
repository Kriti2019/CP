/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
          // Base case: if the tree is empty, there can't be a matching path
        if (!root) return false;
        
        // Check if the current node in the tree can start a path that matches the linked list
        if (dfs(head, root)) return true;
        
        // Recur for left and right subtrees to find the linked list path
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
    // Depth First Search to check if the linked list matches from the current tree node
    bool dfs(ListNode* head, TreeNode* node) {
        // If we've reached the end of the linked list, we've found a match
        if (!head) return true;
        // If the tree node is null or the values don't match, return false
        if (!node || head->val != node->val) return false;
        
        // Recur down the left and right subtree to check the next node in the linked list
        return dfs(head->next, node->left) || dfs(head->next, node->right);
        
        
    }
};