class Solution {
public:
    string makeFancyString(string s) {
         string result;
    int count = 0;
    char prev_char = '\0'; // Initialize with a null character

    for (char c : s) {
        if (c == prev_char) {
            count++;
        } else {
            count = 1;      // Reset count for a new character
            prev_char = c;  // Update previous character
        }

        if (count <= 2) {
            result += c;    // Append character if it doesn't create three in a row
        }
    }

    return result;
        
    }
};