class Solution {
public:
    char findKthBit(int n, int k) {
        // Helper function to find the k-th bit in S_n
        return findKthBitHelper(n, k);
    }
     char findKthBitHelper(int n, int k) {
        // Base case: if n == 1, S1 is "0", so return '0'.
        if (n == 1) return '0';

        // Length of S_n is 2^n - 1
        int length = (1 << n) - 1;  // This is 2^n - 1

        // Middle element of S_n is at index 2^(n-1)
        int middle = length / 2 + 1;

        if (k == middle) {
            // If k is the middle element, it is always '1'
            return '1';
        } else if (k < middle) {
            // If k is in the first half, it is the same as S_(n-1)'s k-th bit
            return findKthBitHelper(n - 1, k);
        } else {
            // If k is in the second half, it is the reverse and invert of S_(n-1)'s corresponding bit
            int mirrored_k = length - k + 1;
            char mirrored_bit = findKthBitHelper(n - 1, mirrored_k);
            // Invert the bit (0 becomes 1, 1 becomes 0)
            return mirrored_bit == '0' ? '1' : '0';
        }
     }
  
};