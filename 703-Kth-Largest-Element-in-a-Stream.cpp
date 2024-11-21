
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store the k largest elements
    int k; // The value of k

public:
    // Constructor to initialize the KthLargest object
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num); // Add all elements to the heap
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove smallest element if heap size exceeds k
            }
        }
    }

    // Add a new value and return the k-th largest element
    int add(int val) {
        minHeap.push(val); // Add the new value to the heap
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove smallest element if heap size exceeds k
        }
        return minHeap.top(); // The k-th largest element is the root of the heap
    }
};

/**
 * Example Usage:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
