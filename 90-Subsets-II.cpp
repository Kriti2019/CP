class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Explore further subsets
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            // Include nums[i] in the current subset
            current.push_back(nums[i]);
            
            // Recur to explore further elements
            backtrack(nums, i + 1, current, result);
            
            // Backtrack to explore subsets without nums[i]
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the input to easily skip duplicates
        sort(nums.begin(), nums.end());
        
        // Start the backtracking process
        backtrack(nums, 0, current, result);
        
        return result;
    }
};
