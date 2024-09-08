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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         // Step 1: Calculate the length of the list
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        // Step 2: Calculate the size of each part
        int partSize = length / k;
        int extraNodes = length % k;

        // Step 3: Split the list
        vector<ListNode*> result(k, nullptr); // Resultant array of k parts
        curr = head;
        for (int i = 0; i < k && curr; i++) {
            result[i] = curr;
            int currentPartSize = partSize + (extraNodes-- > 0 ? 1 : 0);
            for (int j = 1; j < currentPartSize; j++) {
                curr = curr->next;
            }
            // Break the list
            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        
        return result;
        
    }
};