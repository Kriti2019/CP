class Solution {
public:
   
    int coinChange(vector<int>& arr, int k) {
        int n=arr.size();
         
        vector<int>prev(k+1,0),curr(k+1,0);
        for (int target = 0; target <= k; target++) {
            if (target % arr[0] == 0) 
                prev[target] = target / arr[0];  // Minimum coins when we only have the first coin
            else 
                prev[target] = 1e9;  // Impossible case
        }
        
        // Fill dp for all coins starting from the second one (ind = 1)
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= k; target++) {
                int notpick = 0 + prev[target];  // Don't pick the current coin
                int pick = 1e9;
                
                if (arr[ind] <= target) {
                    pick = 1 + curr[target - arr[ind]];  // Pick the current coin
                }
                
                curr[target] = min(pick, notpick);  // Take the minimum of both options
            }
            prev = curr;  // Move to the next row
        }
        
        // If no solution, return -1
        if (prev[k] >= 1e9) return -1;
        return prev[k];
    }
};