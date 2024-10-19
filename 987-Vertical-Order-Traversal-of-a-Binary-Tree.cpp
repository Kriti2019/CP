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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;
        queue <pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int line=it.second.first;
            int level=it.second.second;
            mpp[line][level].insert(node->val);
            if(node->left!=NULL){
                q.push({node->left,{line-1,level+1}});
            }
             if(node->right!=NULL){
                q.push({node->right,{line+1,level+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto it:mpp){
            vector<int>ds;
            for(auto p:it.second){
                ds.insert(ds.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(ds);
        }
        return ans;
    }
};