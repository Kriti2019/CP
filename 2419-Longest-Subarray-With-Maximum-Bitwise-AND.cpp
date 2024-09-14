class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());  // Find the maximum element in the array
        int longest = 0, current_length = 0;
        
        for (int num : nums) {
            if (num == max_val) {
                current_length++;  // Increment current subarray length
                longest = max(longest, current_length);  // Update longest subarray length if needed
            } else {
                current_length = 0;  // Reset if the number is not equal to the maximum value
            }
        }
        
        return longest;
    }
};