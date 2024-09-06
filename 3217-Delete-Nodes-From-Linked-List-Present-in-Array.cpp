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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
          std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Create a dummy node to handle edge cases (e.g., removing head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Pointer to iterate through the list
        ListNode* current = dummy;
        
        while (current->next != NULL) {
            if (numSet.find(current->next->val) != numSet.end()) {
                // Remove the node
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // free the memory of the removed node
            } else {
                // Move to the next node
                current = current->next;
            }
             }
        
        // Return the new head (which could be different if the original head is removed)
        return dummy->next;
        
    }
};