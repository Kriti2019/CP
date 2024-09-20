class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds(n, string(n, '.'));
        vector<int> lrow(n,0),ud(2*n-1,0),ld(2*n-1,0);
        solve(0,ans,ds,lrow,ud,ld,n);
        return ans;
        
    }
    void solve(int col,vector<vector<string>>& ans,vector<string>& ds,vector<int>& lrow,vector<int>& ud,vector<int>& ld,int n){
        if(col==n){
            ans.push_back(ds);
            return;
        }
        for(int row=0;row<n;row++){
            if(lrow[row]==0 && ld[row+col]==0 && ud[n-1+col-row]==0){
                ds[row][col]='Q';
                lrow[row]=1;
                ld[row+col]=1;
                ud[n-1+col-row]=1;
                solve(col+1,ans,ds,lrow,ud,ld,n);
                ds[row][col]='.';
                lrow[row]=0;
                ld[row+col]=0;
                ud[n-1+col-row]=0;

            }
        }

    }
};