class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorResult = start ^ goal;
        
        // Count the number of set bits (1s) in xorResult
        int count = 0;
        while (xorResult > 0) {
            count += (xorResult & 1);  // Check if the least significant bit is 1
            xorResult >>= 1;  // Right shift to check the next bit
        }
        
        return count;
        
    }
};