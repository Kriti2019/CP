class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string combined = s + \#\ + rev_s;

    // Compute the LPS array for the combined string
    int n = combined.size();
    vector<int> lps(n, 0);
    
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        
        while (j > 0 && combined[i] != combined[j]) {
            j = lps[j - 1];
        }
        
        if (combined[i] == combined[j]) {
            j++;
        }
        
        lps[i] = j;
    }
    
    // The value at the last position of the LPS array tells us the longest palindromic prefix
    int pal_len = lps.back();
    
    // Add the remaining characters in reverse order to the front
    string to_add = s.substr(pal_len);
    reverse(to_add.begin(), to_add.end());
    return to_add + s;
        
    }
};