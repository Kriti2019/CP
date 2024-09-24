class Solution {
public:
   
    bool isMatch(string s, string p) {
       int n = s.size();
    int m = p.size();

    // dp[i][j] will be true if s[0...i-1] matches p[0...j-1]
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Empty pattern matches empty string
    dp[0][0] = true;

    // Handle the case where pattern contains '*' at the start
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                // Characters match or '?' matches any single character
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // '*' matches zero characters (dp[i][j-1]) or matches one or more characters (dp[i-1][j])
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    // The value at dp[n][m] will tell if the entire string matches the pattern
    return dp[n][m];
    }
};