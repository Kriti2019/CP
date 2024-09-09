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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));  // Initialize matrix with -1
        
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode* curr = head;  // Pointer to traverse the linked list
        
        while (top <= bottom && left <= right && curr != nullptr) {
            // Fill top row (left to right)
            for (int i = left; i <= right && curr != nullptr; ++i) {
                matrix[top][i] = curr->val;
                curr = curr->next;
            }
            top++;  // Move the top boundary down
            
            // Fill right column (top to bottom)
            for (int i = top; i <= bottom && curr != nullptr; ++i) {
                matrix[i][right] = curr->val;
                curr = curr->next;
            }
            right--;  // Move the right boundary left
            
            // Fill bottom row (right to left)
            for (int i = right; i >= left && curr != nullptr; --i) {
                matrix[bottom][i] = curr->val;
                curr = curr->next;
            }
            bottom--;  // Move the bottom boundary up
            
            // Fill left column (bottom to top)
            for (int i = bottom; i >= top && curr != nullptr; --i) {
                matrix[i][left] = curr->val;
                curr = curr->next;
            }
            left++;  // Move the left boundary right
        }
        
        return matrix;
        
    }
};