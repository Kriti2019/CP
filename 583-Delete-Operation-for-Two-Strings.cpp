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
    int minDistance(string str1, string str2) {
        
    int n = str1.size();
    int m = str2.size();
    
    // Calculate the length of the longest common subsequence between str1 and str2
    int k = lcs(str1, str2);
    
    // Calculate the minimum operations required to convert str1 to str2
    return (n - k) + (m - k);
    }
};