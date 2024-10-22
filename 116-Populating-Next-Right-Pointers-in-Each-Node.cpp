/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        
        // If the current node has a left child, we connect the left child to the right child.
        if (root->left) {
            root->left->next = root->right;
            
            // If the current node has a next pointer, we connect the right child to the left child
            // of the next node.
            if (root->next) {
                root->right->next = root->next->left;
            }
        }
        
        // Recursively connect the left and right subtrees
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};
