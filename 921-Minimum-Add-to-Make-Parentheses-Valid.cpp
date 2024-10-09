class Solution {
public:
    int minAddToMakeValid(string s) {
         int balance = 0; // keeps track of unmatched '('
    int unmatchedClosing = 0; // counts unmatched ')'

    for (char c : s) {
        if (c == '(') {
            balance++;
        } else { // c == ')'
            if (balance > 0) {
                balance--; // match ')' with a previous '('
            } else {
                unmatchedClosing++; // no matching '(' for this ')'
            }
        }
    }

    // Total additions needed will be unmatched '(' + unmatched ')'
    return balance + unmatchedClosing;
        
    }
};