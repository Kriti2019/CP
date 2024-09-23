class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    vector<int> dp(n + 1, n);  // dp[i] = minimum extra chars if starting from index i
    dp[n] = 0;  // Base case: no extra chars beyond the end of the string
    
    // Traverse from the end of the string to the beginning
    for (int i = n - 1; i >= 0; --i) {
        // Try every substring starting from index i
        string current = "";
        for (int j = i; j < n; ++j) {
            current += s[j];
            // Check if current substring is in the dictionary
            if (dict.find(current) != dict.end()) {
                dp[i] = min(dp[i], dp[j + 1]);  // No extra chars for this substring
            }
        }
        // If we don't use any dictionary word starting from i, add 1 to the result (extra char)
        dp[i] = min(dp[i], 1 + dp[i + 1]);
    }
    
    // The answer is dp[0], which means starting from index 0
    return dp[0];
        
    }
};