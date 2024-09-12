class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowedSet(26, false);
        for (char c : allowed) {
            allowedSet[c - 'a'] = true;  // Mark allowed characters
        }

        int consistentCount = 0;  // To store the count of consistent strings

        // Step 2: Check each word in the words array
        for (string& word : words) {
            bool isConsistent = true;

            // Check if all characters of the word are in the allowed set
            for (char c : word) {
                if (!allowedSet[c - 'a']) {
                    isConsistent = false;
                    break;  // If a character is not allowed, break the loop
                }
            }

            // If the word is consistent, increment the counter
            if (isConsistent) {
                consistentCount++;
            }
        }

        // Step 3: Return the total number of consistent strings
        return consistentCount;
        
    }
};