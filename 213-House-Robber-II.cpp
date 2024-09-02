class Solution {
public:
    int rob1(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n=nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
        
    }
};