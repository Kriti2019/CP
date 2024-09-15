class Solution {
public:
    int findTheLongestSubstring(string s) {
         // Map to store the first occurrence of each bitmask state
        unordered_map<int, int> first_occurrence;
        first_occurrence[0] = -1; // Starting with an initial state of 0 at index -1
        
        int mask = 0;  // This will track the bitmask
        int max_len = 0;  // To track the longest valid substring
        
        for (int i = 0; i < s.size(); ++i) {
            // Update the mask depending on the current character
            if (s[i] == 'a') {
                mask ^= (1 << 0);
            } else if (s[i] == 'e') {
                mask ^= (1 << 1);
            } else if (s[i] == 'i') {
                mask ^= (1 << 2);
            } else if (s[i] == 'o') {
                mask ^= (1 << 3);
            } else if (s[i] == 'u') {
                mask ^= (1 << 4);
            }
            
            // If this bitmask has been seen before, calculate the length of the substring
            if (first_occurrence.find(mask) != first_occurrence.end()) {
                max_len = max(max_len, i - first_occurrence[mask]);
            } else {
                // Otherwise, store the index of the first time we see this bitmask
                first_occurrence[mask] = i;
            }
        }
        
        return max_len;
        
    }
};