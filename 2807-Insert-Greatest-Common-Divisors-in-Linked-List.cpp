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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
         if (!head || !head->next) {
            // If there's only one node or the list is empty, return the head.
            return head;
        }
        
        ListNode* current = head;
        
        while (current && current->next) {
            // Get the GCD of current node and the next node.
            int gcdValue = std::gcd(current->val, current->next->val);
            
            // Create a new node with the GCD value.
            ListNode* gcdNode = new ListNode(gcdValue);
            
            // Insert the gcdNode between current and current->next.
            gcdNode->next = current->next;
            current->next = gcdNode;
            
            // Move current to the node after the newly inserted gcdNode.
            current = gcdNode->next;
        }
        
        return head;
        
    }
};