class Solution {
public:
    int getLucky(string s, int k) {
          // Step 1: Convert the string to its corresponding integer representation
        string numStr;
        for (char c : s) {
            int val = c - 'a' + 1;  // Convert character to its position in the alphabet
            numStr += to_string(val);
        }

        // Step 2: Apply the transformation k times
        int result = 0;
        for (int i = 0; i < k; ++i) {
            result = 0;
            for (char digit : numStr) {
                result += digit - '0';  // Sum up the digits
            }
            numStr = to_string(result);  // Update the number as a string for the next transformation
        }
        return result;
        
    }
};