class Solution {
public:
    bool isCircularSentence(string sentence) {
        char first_char = sentence[0];
        char prev_char = sentence[0];
        int n = sentence.length();
        for (int i = 1; i < n; i++) {
            if (sentence[i] == ' ') {
                // End of a word
                if (i + 1 < n) {
                    char next_char = sentence[i + 1];
                    if (prev_char != next_char) {
                        return false;
                    }
                }
            } else {
                prev_char = sentence[i];
            }
        }
        // After the loop, check that last character equals first character
        return prev_char == first_char;
    }
};
