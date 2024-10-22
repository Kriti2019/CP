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
 class BSTIterator {
    stack<TreeNode*> st;
    bool rev=true;
public:
    BSTIterator(TreeNode* root,bool r) {
        rev=r;
        pushall(root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(rev==false){pushall(node->right);}
        else{pushall(node->left);}
        return node->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void pushall(TreeNode* node){
         while (node != nullptr)
          if(!rev){
        st.push(node);         // Push the current node onto the stack
        node = node->left;     // Move to the left child
          }else{
            st.push(node);         // Push the current node onto the stack
        node = node->right;
          }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        BSTIterator l=BSTIterator(root,false);
        BSTIterator r=BSTIterator(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k)return true;
            else if(i+j<k){i=l.next();}
            else {j=r.next();}
        }
        return false;

    }
};