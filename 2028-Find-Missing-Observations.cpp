class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total_sum = mean * (n + m);  // Calculate the required total sum for mean
        int sum_of_given_rolls = std::accumulate(rolls.begin(), rolls.end(), 0);  // Sum of given rolls

              int sum_of_missing_rolls = total_sum - sum_of_given_rolls;  // Calculate sum needed for missing rolls
        
        // Check if the sum needed for missing rolls is within the feasible range
        if (sum_of_missing_rolls < n || sum_of_missing_rolls > 6 * n) {
            return {};  // Return an empty array if it is not possible
        }
        
        // Initialize the result vector with the minimum possible values
        std::vector<int> result(n, 1);
        sum_of_missing_rolls -= n;  // Adjust for the initial sum of n ones
        
        // Distribute the remaining sum among the missing rolls
        for (int i = 0; i < n && sum_of_missing_rolls > 0; ++i) {
            int add = std::min(5, sum_of_missing_rolls);  // Max we can add to any element is 5
            result[i] += add;
            sum_of_missing_rolls -= add;
        }
        
        return result;
        
    }
};