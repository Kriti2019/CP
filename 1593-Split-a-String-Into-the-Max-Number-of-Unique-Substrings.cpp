class Solution {
public:
    int backtrack(const string& s, int start, unordered_set<string>& used) {
        if (start == s.length()) {
            return 0;  // Base case: if we've reached the end of the string, no more splits are possible
        }

        int maxSplits = 0;  // Variable to store the maximum number of splits

        // Try all possible substrings starting from index 'start'
        for (int end = start; end < s.length(); end++) {
            // Extract the substring from 'start' to 'end'
            string substring = s.substr(start, end - start + 1);

            // If the substring is unique (not used before), proceed
            if (used.find(substring) == used.end()) {
                // Mark the substring as used
                used.insert(substring);

                // Recursively call the backtracking function on the remaining string
                int currentSplits = 1 + backtrack(s, end + 1, used);

                // Update the maximum number of splits
                maxSplits = max(maxSplits, currentSplits);

                // Backtrack: remove the substring from the used set
                used.erase(substring);
            }
        }

        return maxSplits;
    }

    // Main function to compute the maximum number of unique splits
    int maxUniqueSplit(string s) {
        unordered_set<string> used;  // Set to track used substrings
        return backtrack(s, 0, used);
    }
};