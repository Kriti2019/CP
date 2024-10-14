class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
    std::priority_queue<long long> maxHeap;
        
        // Insert all elements into the max-heap
        for (int num : nums) {
            maxHeap.push(num);
        }
        
        long long score = 0;
        
        // Perform k operations
        for (int i = 0; i < k; ++i) {
            // Get the maximum element
            long long maxElement = maxHeap.top();
            maxHeap.pop();
            
            // Add the max element to the score
            score += maxElement;
            
            // Replace the max element with ceil(maxElement / 3)
            long long newElement = (maxElement + 2) / 3; // This is a shortcut for ceil(maxElement / 3)
            maxHeap.push(newElement);
        }
        
        return score;
    }
};