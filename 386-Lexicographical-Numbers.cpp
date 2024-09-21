class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int current = 1;
        
        for (int i = 0; i < n; ++i) {
            result.push_back(current);
            if (current * 10 <= n) {
                current *= 10; // Go deeper
            } else {
                if (current >= n) {
                    current /= 10; // Go up one level
                }
                current += 1; // Move to the next number
                
                while (current % 10 == 0) {
                    current /= 10; // Backtrack if the current number ends with 0
                }
            }
        }
        
        return result;
        
    }
};