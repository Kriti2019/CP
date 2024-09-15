class Solution {
public:
    int fun(int ind,int res,vector<int>& arr,vector<vector<int>>&dp){
        if(ind==0){
            if(res%arr[0]==0) return res/arr[0];
            else return 1e9;
        }
        if(dp[ind][res]!=-1)return dp[ind][res];
        int notpick=0+ fun(ind-1,res,arr,dp);
        int pick=1e9;
        if(arr[ind]<=res){
            pick=1+fun(ind,res-arr[ind],arr,dp);
        }
        return dp[ind][res]=min(pick,notpick);

    }
    int coinChange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        int ans=fun(n-1,k,arr,dp);
        if(ans>=1e9)return -1;
        else return ans;
        
    }
};