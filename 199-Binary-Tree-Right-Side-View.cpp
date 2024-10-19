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
    void fun(TreeNode* node,vector<int>&ans,int level){
    if(node==NULL)return;
    if(level==ans.size()){ans.push_back(node->val);}
    fun(node->right,ans,level+1);
    fun(node->left,ans,level+1);
    
}
    vector<int> rightSideView(TreeNode* root) {
         vector<int> ans;
   fun(root,ans,0);
   return ans;
    }
};