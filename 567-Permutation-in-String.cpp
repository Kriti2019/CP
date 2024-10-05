class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
        return false;
    }
    
    vector<int> s1Freq(26, 0), windowFreq(26, 0);
    
    // Count frequency of each character in s1
    for (char c : s1) {
        s1Freq[c - 'a']++;
    }
    
    int windowSize = s1.length();
    
    // Initialize the first window in s2
    for (int i = 0; i < windowSize; ++i) {
        windowFreq[s2[i] - 'a']++;
    }
    
    // Check the first window
    if (s1Freq == windowFreq) {
        return true;
    }
    
    // Slide the window over s2
    for (int i = windowSize; i < s2.length(); ++i) {
        // Add new character to the window
        windowFreq[s2[i] - 'a']++;
        
        // Remove the character that is left behind
        windowFreq[s2[i - windowSize] - 'a']--;
        
        // Check if current window matches the frequency of s1
        if (s1Freq == windowFreq) {
            return true;
        }
    }
    
    return false;
        
    }
};