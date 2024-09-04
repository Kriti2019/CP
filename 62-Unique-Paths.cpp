class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
\tdp[0][0]=1;
\tfor(int i=0;i<m;i++){
\t\tfor(int j=0;j<n;j++){
\t\t\tint up=0;
\t\t\tint left=0;
\t\t\tif(i==0 && j==0)dp[0][0]=1;
\t\t\telse{
\t\t\t\tif(i>0)up=dp[i-1][j];
\t\t\t\tif(j>0)left=dp[i][j-1];
\t\t\t\tdp[i][j]=up+left;
\t\t\t}
\t\t}
\t}
\treturn dp[m-1][n-1];
        
    }
};