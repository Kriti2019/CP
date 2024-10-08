class Solution {
public:
    int minSwaps(string s) {
    int balance = 0;
    int max_imbalance = 0;
    
    // Traverse the string to calculate imbalance
    for (char c : s) {
        if (c == '[') {
            balance++; // We add to balance for an opening bracket
        } else {
            balance--; // We subtract for a closing bracket
        }
        
        // Track the maximum imbalance (negative balance)
        if (balance < 0) {
            max_imbalance = max(max_imbalance, -balance);
        }
    }
    
    // The minimum swaps required is half the maximum imbalance
    // Each swap fixes two misplaced brackets.
    return (max_imbalance + 1) / 2;
}

};