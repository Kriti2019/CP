class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
         // Array to store counts of remainders
        vector<int> remainder_count(k, 0);

        // Calculate remainders and populate remainder_count
        for (int num : arr) {
            int remainder = num % k;
            if (remainder < 0) remainder += k;  // Handle negative remainders
            remainder_count[remainder]++;
        }

        // Check pairing conditions
        // Remainder 0 elements must pair with themselves
        if (remainder_count[0] % 2 != 0) {
            return false;
        }

        // Check remainder pairs
        for (int i = 1; i <= k / 2; i++) {
            if (remainder_count[i] != remainder_count[k - i]) {
                return false;
            }
        }

        return true;
        
    }
};