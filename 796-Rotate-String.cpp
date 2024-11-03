class Solution {
public:
    bool rotateString(string p, string q) {
        if (p.length() != q.length()) {
        return 0;  // Different lengths, cannot be cyclic rotations
    }

    // Concatenate the first string with itself
    string concatenated = p + p;

    // Check if the second string is a substring of the concatenated string
    if (concatenated.find(q) != string::npos) {
        return 1;  // Second string is a substring, cyclic rotation is possible
    } else {
        return 0;  // Second string is not a substring, cyclic rotation is not possible
    }
        
    }
};