class Solution {
public:
    int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Create two arrays to store the previous and current rows of DP values
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base Case is covered as we have initialized the prev and cur to 0.

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        // Update the prev array with the current values
        prev = cur;
    }

    // The value at prev[m] contains the length of the LCS
    return prev[m];
}

// Function to calculate the length of the Longest Palindromic Subsequence
int longestPalindromeSubsequence(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
}

    int minInsertions(string s) {
         int n = s.size();
    int k = longestPalindromeSubsequence(s);

    // The minimum insertions required is the difference between the string length and its longest palindromic subsequence length
    return n - k;
        
    }
};