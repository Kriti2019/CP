class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        int pick=0;
        int nonpick=0;
        int curr;
        for(int i=1;i<n;i++){
            pick=nums[i];
            if(i>=2)pick+=prev2;
            nonpick=0+prev;
            curr=max(pick,nonpick);
            prev2=prev;
            prev=curr;

        }
        return prev;
        
    }
};