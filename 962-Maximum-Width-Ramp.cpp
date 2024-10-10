class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> numIndexPairs;
    int n = nums.size();

    // Create a vector of pairs (value, index)
    for (int i = 0; i < n; i++) {
        numIndexPairs.push_back({nums[i], i});
    }

    // Sort the pairs by value (and index implicitly)
    sort(numIndexPairs.begin(), numIndexPairs.end());

    int maxWidth = 0;
    int minIndex = n;

    // Iterate through the sorted pairs and calculate the maximum width ramp
    for (auto& [value, index] : numIndexPairs) {
        // Update the maxWidth based on the difference between the current index and minIndex
        maxWidth = max(maxWidth, index - minIndex);
        // Update the minIndex with the smallest index seen so far
        minIndex = min(minIndex, index);
    }

    return maxWidth;
        
    }
};