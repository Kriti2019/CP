class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int, vector<int>, greater<int>> minHeap;

    // Iterate through the array
    for (int num : nums) {
        minHeap.push(num); // Add element to the heap
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove the smallest element if heap size exceeds k
        }
    }

    // The root of the heap is the k-th largest element
    return minHeap.top();
    }
};