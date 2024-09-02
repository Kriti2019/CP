class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Step 1: Calculate total chalk needed for one complete cycle
        long long total_chalk = 0;
        for (int c : chalk) {
            total_chalk += c;
        }
        
        // Step 2: Reduce k modulo the total chalk
        k %= total_chalk;
        
        // Step 3: Determine the student who will need to replace the chalk
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        // This line will never be reached due to the problem constraints
        return -1;
    }
};
