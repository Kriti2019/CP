class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        // Step 1: Create the prefix XOR array
        vector<int> prefixXOR(n);
        prefixXOR[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
        }
        
        // Step 2: Answer each query using the prefix XOR array
        vector<int> result;
        for (const auto& q : queries) {
            int left = q[0];
            int right = q[1];
            if (left == 0) {
                result.push_back(prefixXOR[right]);
            } else {
                result.push_back(prefixXOR[right] ^ prefixXOR[left - 1]);
            }
        }
        
        return result;
    }
};