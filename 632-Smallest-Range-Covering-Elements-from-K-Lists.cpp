class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        
        int k = nums.size();
        int maxElement = INT_MIN;
        
        // Initialize the heap with the first element of each list
        for (int i = 0; i < k; i++) {
            minHeap.push({nums[i][0], {i, 0}});
            maxElement = max(maxElement, nums[i][0]); // Track the largest element in the window
        }
        
        int startRange = 0, endRange = INT_MAX;
        
        // Process the elements
        while (true) {
            auto [minElement, indices] = minHeap.top(); // Get the minimum element
            minHeap.pop();
            int row = indices.first, col = indices.second;
            
            // Update the best range if the current range is smaller
            if (maxElement - minElement < endRange - startRange) {
                startRange = minElement;
                endRange = maxElement;
            }
            
            // Move to the next element in the same row (list)
            if (col + 1 < nums[row].size()) {
                int nextElement = nums[row][col + 1];
                minHeap.push({nextElement, {row, col + 1}});
                maxElement = max(maxElement, nextElement); // Update the max element in the window
            } else {
                // If we have reached the end of one of the lists, break the loop
                break;
            }
        }
        
        return {startRange, endRange};
        
    }
};