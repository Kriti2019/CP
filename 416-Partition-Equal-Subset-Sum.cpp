class Solution {
public:
    bool isSubsetSum(vector<int>arr, int k){
        // code here 
        int n=arr.size();
     vector<bool>prev(k+1,false),curr(k+1,false);
    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    prev[0]=true;
    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    // Fill the DP array iteratively
    for (int ind = 1; ind < n; ind++) {
        curr[0]=true;
        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = prev[target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            // Store the result in the DP array for the current subproblem
            curr[target] = notTaken || taken;
        }
        prev=curr;
    }

    // The final result is stored in dp[n-1][k]
    return prev[k];
    }
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int totalsum=0;
\tfor(int i=0;i<n;i++)totalsum+=arr[i];
\tif(totalsum%2)return false;
\telse{
\t\tint target=totalsum/2;
\t\treturn isSubsetSum(arr,target);
        
    }}
};